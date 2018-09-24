int inPin = 2;


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
  delay(10000);
  Serial.print("listening\n");
  
  int rcvData[8] = {9,9,9,9,9,9,9,9};
  recvByte(rcvData);
  
  delay(5000000);
}

void recvByte (int dest[8])
{
  int dataInterval = 50;
  

  // Startsequenz
  while(true)
  {
    if (digitalRead(inPin) == HIGH)
    {
      delay(dataInterval +25);
      break;
    }
  }

  // Reveive
  for (int i=0; i<8; i++)
  {
    dest[i] = digitalRead(inPin);
    Serial.print(dest[i]);
    delay(dataInterval);
  }
  
}

