#include <Servo.h>  // Include the Servo library
int SR1=9,  SR2=3, SR3=2;  // Define three servo pins
int IR_PIN=13;    // Define IR sensor pin
int IR_Value;     // To store the value of IR sensor
int Buzzer_PIN=10;  // Define buzzer pin
int Led1_PIN=6;     // Define LED 1 pin
int Led2_PIN=5;     // Define LED 2 pin
Servo myservo1; // Create a Servo object for servo 1
Servo myservo2; // Create a Servo object for servo 2
Servo myservo3; // Create a Servo object for servo 3

void setup() {
  myservo1.attach(SR1); // Attach servo 1 to pin 9
  myservo2.attach(SR2); // Attach servo 2 to pin 3
  myservo3.attach(SR3); // Attach servo 3 to pin 2
  pinMode(IR_PIN,INPUT);   // Set the IR sensor pin as input
  pinMode(Buzzer_PIN,OUTPUT); // Set the buzzer pin as output
  pinMode(Led1_PIN,OUTPUT);   // Set LED 1 pin as output
  pinMode(Led2_PIN,OUTPUT);   // Set LED 2 pin as output
}

void loop() {
  IR_Value=digitalRead(IR_PIN);  // Read the value from the IR sensor
  if(IR_Value==0)  // If the IR sensor detects an object .

  {
    myservo1.write(120); // Set servo 1 to rotate to position 120
    delay(50); // Wait for 50 milliseconds
    myservo2.write(120); // Set servo 2 to rotate to position 120
    delay(400); // Wait for 400 milliseconds
    myservo3.write(180); // Set servo 3 to rotate to position 180
  }
  if(IR_Value==0)// If the IR sensor detects an object
  {
  
    digitalWrite(Led1_PIN,HIGH); // Turn on LED 1
    digitalWrite(Led2_PIN,HIGH); // Turn on LED 2
    delay(400); // Wait for 400 milliseconds
    digitalWrite(Led2_PIN,LOW); // Turn off LED 2
    digitalWrite(Led1_PIN,LOW); // Turn off LED 1
  }
  if(IR_Value==0){ // If the IR sensor detects an object
    for(int i=2000;i<=3000;i++) // Play a tone between 2000 and 3000 Hz
      tone(Buzzer_PIN,i);
  }
  else  // If the IR sensor doesn't detect an object
  {
    myservo3.write(0); // Set servo 3 to rotate to position 0
    delay(500); // Wait for 500 milliseconds
    myservo1.write(0); // Set servo 1 to rotate to position 0
    myservo2.write(0); // Set servo 2 to rotate to position 0
    noTone(Buzzer_PIN); // Stop playing the tone
    digitalWrite(Led1_PIN,LOW); // Turn off LED 1
    digitalWrite(Led2_PIN,LOW); // Turn off LED 2  
  }
  }