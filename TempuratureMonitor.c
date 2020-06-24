void setup(){
        Serial.begin(9600);
        for(int a = 11; a <=13; a++)
                pinMode(a, OUTPUT);
}
double VoltToCelcius(double val) // phat function telling vals
{
        return -1481.98+sqrt(2196200+(1.8639-val)/(0.00000388));
}
void loop() {   
        double G_TMP = VoltToCelcius((5.0*analogRead(A0))/1023.0); // set 
        digitalWrite(11, LOW);  
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
                if (G_TMP <= 4.4)
                        digitalWrite(11, HIGH); // leds being set
                 else if (G_TMP > 4.4 && G_TMP < 21.11)
                        digitalWrite(12, HIGH);  
                 else
                        digitalWrite(13, HIGH);
        Serial.print((5.0*analogRead(A0))/1023.0); //print raw voltage
        Serial.print(", C ");
        Serial.print(G_TMP); // print centigrade
        Serial.print(", F ");
        Serial.print(G_TMP*1.8 + 32); //print freedom units
        Serial.print("\n");
        delay(350); // to delay spam
}
