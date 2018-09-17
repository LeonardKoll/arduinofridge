/* # When you push the digital button, the Led 13 on the board will turn on. Otherwise,the led turns off.
*/
int ledPin = 13;                // choose the pin for the LED
int pushbutton = 4;               // Connect sensor to input pin 3 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pushbutton, INPUT);     // declare pushbutton as input
}
void loop(){
  int val = digitalRead(pushbutton);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
