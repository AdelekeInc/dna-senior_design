const int pwPin = 7; 
//variables needed to store values
long pulse;
// inches, cm;
// OUR OLD CODE: int Dist = PIN0; //RX
// OUR OLD CODE: int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pwPin, INPUT);
  // OUR OLD CODE: pinMode(Dist , INPUT);


}

void loop()
{
  // val = analogRead(Dist); //Serial.read();
  // Serial.println(val);
  // delay(250);         // Default is in ms


  //Used to read in the pulse that is being sent by the MaxSonar device.
  //Pulse Width representation with a scale factor of 147 uS per Inch.
  pulse = pulseIn(pwPin, HIGH);
  
  //147uS per inch
  //inches = pulse/147;
  //change inches to centimetres
  //cm = inches * 2.54;
  // Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
  // Serial.print("cm");
Serial.print(pulse);
Serial.println();
delay(250);
}
