constintfrontPin = A0;
constintleftPin = A1;
constintrightPin = A2;
constintbackPin = A3;
constintleftMotor = 9;
constintrightMotor = 10;
intthreshHold = 170;
int Direction;
int direction1;
int direction2;
int Delay = 25;
int Delay2 = 25;

void setup()
{

pinMode(frontPin, INPUT);
pinMode(leftPin, INPUT);
pinMode(rightPin, INPUT);
pinMode(backPin, INPUT);
pinMode(leftMotor, OUTPUT);
pinMode(rightMotor, OUTPUT);
digitalWrite(leftMotor, HIGH);
digitalWrite(rightMotor,HIGH);
delay(100);
digitalWrite(leftMotor, LOW);
digitalWrite(rightMotor, LOW);
delay(100);
digitalWrite(leftMotor, HIGH);
digitalWrite(rightMotor, HIGH);
delay(100);
digitalWrite(leftMotor, LOW);
digitalWrite(rightMotor, LOW);
delay(1500);
Serial.begin(9600);  
}

void loop()
{

int Direction;
int direction1;
int direction2;
intfrontSignal = 1023 - analogRead(frontPin);
intleftSignal = 1023 - analogRead(leftPin);
intrightSignal = 1023 - analogRead(rightPin);
intbackSignal = 1023 - analogRead(backPin);
Serial.println(frontSignal); 
Serial.println(leftSignal); 
Serial.println(rightSignal); 
Serial.println(backSignal);
// frontSignal + leftSignal + rightSignal + backSignal<= threshHold
if (abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal) >= threshHold )
{
Serial.println("motion loop");
                     direction1 = max(frontSignal, leftSignal);
                     direction2 = max(rightSignal, backSignal);
                      Direction = max(direction1, direction2);
//Loop here is entered only if the light received is not evenly distributed.
     if (frontSignal == Direction)
     {
                   do
                   {
                         digitalWrite(leftMotor, HIGH);
                         digitalWrite(rightMotor, HIGH);
                         delay(Delay2);
                         digitalWrite(leftMotor, LOW);
                         digitalWrite(rightMotor, LOW);
                         delay(Delay);
                         frontSignal = 1023 - analogRead(frontPin);
                         leftSignal = 1023 - analogRead(leftPin);
                         rightSignal = 1023 - analogRead(rightPin);
                         backSignal = 1023 - analogRead(backPin);
                         direction1 = max(frontSignal, leftSignal);
                         direction2 = max(rightSignal, backSignal);
                         Direction = max(direction1, direction2);
                         Serial.println("Forward");
          
                   } while(frontSignal == Direction && abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal) >= threshHold);
           digitalWrite(leftMotor, LOW);
           digitalWrite(rightMotor, LOW); 
     }
     else if (leftSignal == Direction)     //Signal is greatest on the left
     {
                             do
                 {
                       Serial.println("Left");
                       digitalWrite(rightMotor, HIGH);
                       delay(Delay2);
                       digitalWrite(rightMotor, LOW);
                       delay(Delay);
                       frontSignal = 1023 - analogRead(frontPin);
                       leftSignal = 1023 - analogRead(leftPin);
                       rightSignal = 1023 - analogRead(rightPin);
                       backSignal = 1023 - analogRead(backPin);
                       direction1 = max(frontSignal, leftSignal);
                       direction2 = max(rightSignal, backSignal);
                       Direction = max(direction1, direction2);
                 } while(leftSignal == Direction && abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal) >= threshHold);
          digitalWrite(rightMotor, LOW);
     }
     else if (rightSignal == Direction)        //Signal is greatest on the right.
     {
               do
               {
                     Serial.println("Right");
                     digitalWrite(leftMotor, HIGH);
                     delay(Delay2);
                     digitalWrite(leftMotor, LOW);
                     delay(Delay);             
                     frontSignal = 1023 - analogRead(frontPin);
                     leftSignal = 1023 - analogRead(leftPin);
                     rightSignal = 1023 - analogRead(rightPin);
                     backSignal = 1023 - analogRead(backPin);
                     direction1 = max(frontSignal, leftSignal);
                     direction2 = max(rightSignal, backSignal);
                     Direction = max(direction1, direction2);
                    
               } while(rightSignal == Direction && abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal) >= threshHold);
               digitalWrite(leftMotor, LOW);
     }
     else if (backSignal == Direction)      //Signal is greatest behind.
     {
               do
               {
                     Serial.println("Back");
                     digitalWrite(leftMotor, HIGH);
                     delay(Delay2);
                     digitalWrite(leftMotor, LOW);
                     delay(Delay);             
                     frontSignal = 1023 - analogRead(frontPin);
                     leftSignal = 1023 - analogRead(leftPin);
                     rightSignal = 1023 - analogRead(rightPin);
                     backSignal = 1023 - analogRead(backPin);
                     direction1 = max(frontSignal, leftSignal);
                     direction2 = max(rightSignal, backSignal);
                     Direction = max(direction1, direction2);
               } while(backSignal == Direction && abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal) >= threshHold);
               digitalWrite(leftMotor, LOW);
     }
}
else if(abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal) <= threshHold)
{
             int difference = abs(frontSignal-leftSignal)+abs(frontSignal-rightSignal)+abs(frontSignal-backSignal);
             Serial.println("Signal differential is equal to ");
             Serial.println(difference);
             digitalWrite(leftMotor, LOW);
             digitalWrite(rightMotor, LOW);
             delay(1000); // Else sample environment at a rate of 10 hz
}
else
{
             digitalWrite(leftMotor, LOW);
             digitalWrite(rightMotor, LOW);
}

} 
