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
  int dataInterval = 2;

  Serial.print("started\n");
  delay(8000);
  Serial.print("now sending\n");
  
  digitalWrite(outPin, HIGH);
  delay(dataInterval);

  digitalWrite(outPin, LOW);
  delay(dataInterval);
  digitalWrite(outPin, HIGH);
  delay(dataInterval);
  digitalWrite(outPin, LOW);
  delay(dataInterval);
  digitalWrite(outPin, LOW);
  delay(dataInterval);
  digitalWrite(outPin, LOW);
  delay(dataInterval);
  digitalWrite(outPin, HIGH);
  delay(dataInterval);
  digitalWrite(outPin, HIGH);
  delay(dataInterval);
  digitalWrite(outPin, HIGH);
  delay(dataInterval);
  
  Serial.print("ok\n");
  digitalWrite(outPin, LOW);

  delay(500000);
}
