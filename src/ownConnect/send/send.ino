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
    digitalWrite(outPin, HIGH);
    delay(2);
    digitalWrite(outPin, LOW);
    delay (1500);
  }


  Serial.print("Sending\n");
  // Start sending
  digitalWrite(outPin, HIGH);
  delay(1);
  digitalWrite(outPin, LOW);
  delay(1);

  // Data
  digitalWrite(outPin, LOW);
  delay(1);
  digitalWrite(outPin, HIGH);
  delay(1);
  digitalWrite(outPin, LOW);
  delay(1);
  digitalWrite(outPin, LOW);
  delay(1);
  digitalWrite(outPin, LOW);
  delay(1);
  digitalWrite(outPin, HIGH);
  delay(1);
  digitalWrite(outPin, HIGH);
  delay(1);
  digitalWrite(outPin, HIGH);
  delay(1);
  Serial.print("Sending done.\n");
  
  digitalWrite(outPin, LOW);
  delay(5000);
}
