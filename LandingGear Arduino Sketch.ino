#include <Servo.h>
int jointSignal; 
int recieverPulse = 3; //Pin 3 connected to reciever
int portPulse; // 2000us = deployed 1000us = retracted
int stbdPulse; // 1000us = deployed 2000us = retracted
int gearPosition; //1 = Retracted, 0 = Deployed
unsigned long inputPulse; //Saved value of input
Servo portServo; // Portside Servo
Servo stbdServo; // Starboardside Servo

void setup() 
{
  Serial.begin(9600);
  
  pinMode(recieverPulse, INPUT); //Sets pin 3 to input.
  portServo.attach(5); //attaches (left) servo to digitalPin 5. 
  stbdServo.attach(6); //attaches (right) servo to digitalPin 6.
  
  //initializes landing gear to retracted position
  initGear();
 
}

void loop() 
{

 //Records pin 3's current uSecond signal to inputPulse variable.
  inputPulse = pulseIn(recieverPulse,HIGH, 20000);  

 //Spew current values,,, 
  Serial.print("STBD Pulsewidth   "); 
  Serial.println(stbdPulse);
  Serial.print("PORT Pulsewidth   ");
  Serial.println(portPulse);
  Serial.print("Input Pulse   ");
  Serial.println(inputPulse);
  Serial.print("Gear Position  ");
  Serial.println(gearPosition);

  //Retracts gear
  while((inputPulse > 950) && (inputPulse < 1400) && (gearPosition == 1) && (portPulse >= 1975))
  {
    retractGear();
  }
  //Deploys gear
  while ((inputPulse > 1600) && (gearPosition == 0) && (portPulse <= 1010))
  {
    deployGear();
  }
  
  delay(700);
}

void initGear() 
{
  portServo.writeMicroseconds(1000); //initializes to a deployed state.
  portPulse = 1000; //Saves current position's microsecond pulse signal.
  stbdServo.writeMicroseconds(2000); //initializes to a deployed state. 
  stbdPulse = 2000; //Saves current position's microsecond pulse signal.
  gearPosition = 0; //Initializes gear position.
  Serial.println("Gear initialized (retracted)");
}

void deployGear() 
{
  Serial.println("Deploying Gear")g
  while(portPulse < 2000)
 {
    stbdPulse=stbdPulse-1;
    portPulse=portPulse+1;
    stbdServo.writeMicroseconds(stbdPulse);
    portServo.writeMicroseconds(portPulse);
    delay(5);
 }
   gearPosition = 1;
   Serial.println("Gear deployed");
}
   
void retractGear( )
{
  Serial.println("Retracting gear");
  while(portPulse > 1000)
  {
    stbdPulse=stbdPulse+1;
    portPulse=portPulse-1;
    stbdServo.writeMicroseconds(stbdPulse);
    portServo.writeMicroseconds(portPulse);
    delay(5);
  }
  gearPosition = 0;
  Serial.println("Gear retracted");
}