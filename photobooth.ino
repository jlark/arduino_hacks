  // Sweep
  // by BARRAGAN <http://barraganstudio.com> 
  // This example code is in the public domain.
  
  
  #include <Servo.h> 
   
  Servo myservo;  // create servo object to control a servo 
                  // a maximum of eight servo objects can be created 
   
  // constants won't change. They're used here to 
  // set pin numbers:
   const int buttonPin = 2;     // the number of the pushbutton pin
   const int ledPin =  13;      // the number of the LED pin
   const int sensorPin = 0;
   const int potPin = 5;
   const int timerState = 500;
   const int drunkState = 60;
  
  //LED pins
   const int led3 = 13;
   const int led2 = 12;
   const int led1 = 11;
  
  // variables will change:
  int buttonState = 0;         // variable for reading the pushbutton status
  int prevState = 0;
  int sensorValue = 0;
  int statePot = 0;
  int pos = 0;    // variable to store the servo position 
   
  void setup() 
  { 
    Serial.begin(9600);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  
    // initialize the LED pin as an output:
     pinMode(ledPin, OUTPUT);      
     // initialize the pushbutton pin as an input:
     pinMode(buttonPin, INPUT);
     pinMode(13,OUTPUT);  
     pinMode(12,OUTPUT);
     pinMode(11,OUTPUT);
     
  } 
   
   
  void loop() 
  { 
    
      buttonState = digitalRead(buttonPin);
      statePot = analogRead(potPin);
      sensorValue = analogRead(sensorPin);       // read analog input pin sensor

     // check if the pushbutton is pressed.
     // if it is, the buttonState is HIGH:
     
     if (statePot < timerState)
     {
       Serial.println("booze mode ");
      // Alcohol based code
      digitalWrite(13, HIGH);  

      
      Serial.print(sensorValue);
      if (sensorValue > drunkState){
        LEDCountdown();
        triggerShutter();
      }
     }
     else{
         // timer based function
         Serial.println("timer mode");
        digitalWrite(13, LOW);  

         if (buttonState == HIGH) {
         
           // turn LED on:
             //Serial.println("High reading on");      
             //delay(2500);

             LEDCountdown();
             triggerShutter();
             
         } 
         else {
           // turn LED off:
         // Serial.println("low reading");
   
         }
     }
     delay(100);
  } 
  
void LEDCountdown()
{
             digitalWrite(led3, HIGH);  
             digitalWrite(led2, HIGH);  
             digitalWrite(led1, HIGH);
             delay(3000);
             digitalWrite(led3, LOW); 
             delay(1000);
             digitalWrite(led2, LOW); 
             delay(1000);
             digitalWrite(led1, LOW);   
}
void triggerShutter(){
              int range = 100; //range we want to travel 
             
                   
             for(pos = 0; pos < range; pos += 1)  // goes from 0 degrees to 180 degrees 
             {                                  // in steps of 1 degree 
                myservo.write(pos);              // tell servo to go to position in variable 'pos' 
                delay(5);                       // waits 15ms for the servo to reach the position 
              } 
             for(pos = range; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
             {                                
               myservo.write(pos);              // tell servo to go to position in variable 'pos' 
               delay(5);                       // waits 15ms for the servo to reach the position 
             }  
}
