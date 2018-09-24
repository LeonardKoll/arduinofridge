int inPin = 2;
long heartbeatAlarm = 2000;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (inPin, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  Serial.print("started\n");
  
  int rcvData[8] = {9,9,9,9,9,9,9,9};
  while (true)
  {
    listen (rcvData, 8);
  }
}

void listen(int dest[], int msgLength)
{
  long lastHeartbeat = millis();
  int hbAlarm = 0;

  // Startsequenz
  while(true)
  {
    delay(1);
    
    // Daten / Heartbeat lesen
    if (digitalRead(inPin) == HIGH)
    {
      delay(1);
      
      // Heartbeat yes/no
      if (digitalRead(inPin) == HIGH)
      {
        // Heartbeat
        lastHeartbeat = millis();
      }
      else
      {
        delay(1);
        // Data - switch to recv mode.
        break;
      } 
    }

    // Heartbeat analysieren
    if (hbAlarm)
    {
      if (millis()-lastHeartbeat < heartbeatAlarm) 
      {
        hbAlarm = 0;
        stop_heartbeatAlarm();
      }
    }
    else
    {
      if (millis()-lastHeartbeat > heartbeatAlarm) 
      {
        hbAlarm = 1;
        fire_heartbeatAlarm();
      }
    }
  }

  // Daten Empfangen
  for (int i=0; i<msgLength; i++)
  {
    dest[i] = digitalRead(inPin);
    Serial.print(dest[i]);
    delay(1);
  }
  Serial.print("\n");
}

void fire_heartbeatAlarm ()
{
  Serial.print("Kein Heartbeat\n");
}

void stop_heartbeatAlarm ()
{
  Serial.print("Heartbeat back\n");
}

