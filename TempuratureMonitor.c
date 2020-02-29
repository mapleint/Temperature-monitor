double G_TMP; //declare global temp
void setup() {
        Serial.begin(9600);
        pinMode(11, OUTPUT);
        pinMode(12, OUTPUT);
        pinMode(13, OUTPUT);
}
double VoltToCelcius(double val) // phat function telling vals
{
        return -1481.98+sqrt(2196200+(1.8639-val)/(0.00000388));
}

void loop() {   
        G_TMP = VoltToCelcius((5.0*analogRead(A0))/1023.0); // set G_TMP
                if(G_TMP < 4.4){
                        digitalWrite(11, HIGH); // leds being set
                        digitalWrite(12, LOW);   
                        digitalWrite(13, LOW);
                }else if(G_TMP > 4.4 && G_TMP < 21.11){
                        digitalWrite(11, LOW);  
                        digitalWrite(12, HIGH);
                        digitalWrite(13, LOW);  
                } else {
                        digitalWrite(11, LOW);  
                        digitalWrite(12, LOW);  
                        digitalWrite(13, HIGH);
                } // end of led block
        Serial.print((5.0*analogRead(A0))/1023.0); //print raw voltage
        Serial.print(", ");
        Serial.print(G_TMP); // print centigrade
        Serial.print(", ");
        Serial.print(G_TMP*1.8 + 32); //print freedom
        Serial.print("\n");
        delay(100); // limit to not overload the mc
}
