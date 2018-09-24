int inPin = 2;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (inPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int sensVal = digitalRead(inPin);
  Serial.print(sensVal);

}
