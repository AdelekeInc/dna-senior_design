const int pwPin = A0;              //switched from pwPin to Analog for waveform
const int USStart = 7; 

//variables needed to store values
long pulse = 0; 
int DistInches = 0; 
int DistFeet = 0;  
unsigned long previousMillis = 0; 
unsigned long pulseInterval = 30;
boolean pulseFlag = false;   
int x = 0; 

void setup()
{
  Serial.begin(9600);
  pinMode(pwPin, INPUT);
  pinMode(USStart, OUTPUT);
  
  digitalWrite(USStart, LOW); //Ultrasonic initially off

  //used delay to see first output values
  //delay(520);
  delay(2000); 

}

void loop()
{
  ////////////////////////////////////////////////////////
  // Make one ultrasonic pulse
  ///////////////////////////////////////////////////////
  
  Serial.print("pulseFlag is ");
  Serial.println(pulseFlag);
  
    //confirm outputs///////////
    x = x + 1;
    Serial.print("x is "); 
    Serial.println(x);  

    
  if(pulseFlag == false)
  {
    digitalWrite(USStart, HIGH);       //start Ultrasonic pulse
    previousMillis = millis();         //start timer
    pulseFlag = true;                  //prevents setting pulse high again
  }

  //Timer until set low
  if(millis() - previousMillis >= pulseInterval)
  {
    digitalWrite(USStart, LOW); 
  }
  

/////////////////////////////////////////////////////////////////////////////////////////////////////
//    Read Pulse, Conversion, and Print
/////////////////////////////////////////////////////////////////////////////////////////////////////
  //Used to read in the pulse that is being sent by the MaxSonar device.
  //1uS per mm
  pulse = pulseIn(pwPin, HIGH);
  

  DistInches = pulse/25.4;
  DistFeet = DistInches/12;

  Serial.print("Pulse: ");
  Serial.print(pulse);
  Serial.print("     ");
  Serial.print("Feet: ");
  Serial.print(DistFeet);
  Serial.print("     ");
  Serial.print("in: ");
  Serial.print(DistInches);
  Serial.print("     ");

  Serial.println();


}

