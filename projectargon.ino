int led2 = D7; 

int lightsensor = A0;
int lightLevel;

void setup() {

  pinMode(led2, OUTPUT);
  pinMode(lightsensor, INPUT);

}

void loop() {
    
    lightLevel = analogRead(lightsensor);
    String light = String(lightLevel);
    
    if (lightLevel < 10){
        
        digitalWrite(led2, HIGH); 
        Particle.publish("light", "Dim", PUBLIC);
        
    } 
    
    else{
        
        digitalWrite(led2, LOW); 
        Particle.publish("light", "Bright", PUBLIC);
        
    }
    
    Particle.publish("light", String(lightLevel), PUBLIC);
    
    delay(5000);

}
