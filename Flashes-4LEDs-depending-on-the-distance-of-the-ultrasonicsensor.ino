# include "SR04.h"
# define TRIG_FIN 12
# define ECHO_PIN 11
SR04 sr04 = SR04 (ECHO_PIN,TRIG_FIN);
long num;

void setup(){
    for(int i=2; i<=5; i=i+1){
        pinMode(i, OUTPUT);
   }
    Serial.begin(9600);
    delay(1000);
}

void loop(){
    num=sr04.Distance();

    Serial.print(num);
    Serial.println("cm");
    delay(1000);
    
    if (num >= 30){
         digitalWrite(2, HIGH);
         delay(2000);
         digitalWrite(2, LOW);
         delay(200);
    }
    else if (num >= 20){
         digitalWrite(3, HIGH);
         delay(2000);
         digitalWrite(3, LOW);
         delay(200);
    }
    else if (num >= 10){
         digitalWrite(4, HIGH);
         delay(2000);
         digitalWrite(4, LOW);
         delay(200); 
    }
    else {             
         digitalWrite(5, HIGH);
         delay(2000);
         digitalWrite(5, LOW);
         delay(200); 
    }
}