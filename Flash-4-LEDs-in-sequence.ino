void setup(){
    for(int i=8; i<=12; i=i+1){
        pinMode(i, OUTPUT);
    }
}

void loop(){
    for(int i=8; i<=12; i=i+1){
        digitalWrite(i, HIGH);
        delay(2000);
        digitalWrite(i, LOW);
        delay(200);
    }
}