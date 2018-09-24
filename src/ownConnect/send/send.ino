int outPin = 2;


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (outPin, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  Serial.print("Heartbeat...\n");
  // 5 seconds of Heartbeat
  for (int  i=0; i<3; i++)
  {
    heartbeat();
    delay (1500);
  }


  Serial.print("Sending\n");
  // Start sending
  int sendData[8] = {1,1,1,0,0,1,1,1};
  send(sendData, 8);
  
  delay(5000);
}

void send(int msg[], int msgLength)
{
  // Start sending
  digitalWrite(outPin, HIGH);
  delay(1);
  digitalWrite(outPin, LOW);
  delay(1);

  // Data
  for (int i=0; i<msgLength; i++)
  {
    if(msg[i] == 0)
    {
      digitalWrite(outPin, LOW);
    }
    else
    {
      digitalWrite(outPin, HIGH);
    }
    delay(1);
  }

  digitalWrite(outPin, LOW);
}

void heartbeat ()
{
  digitalWrite(outPin, HIGH);
  delay(2);
  digitalWrite(outPin, LOW);
}

