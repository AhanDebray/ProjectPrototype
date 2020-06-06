#include "Adafruit_DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

int temperature;
int humidity;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
    dht.begin();
  
}

void loop() {
    
    temperature = dht.getTempFarenheit();
    humidity = dht.getHumidity();
    
    if(temperature > 90){
        
        Particle.publish("temperature", "Very Hot", PUBLIC);
        
    }
    
    if(temperature < 45){
        
        Particle.publish("temperature", "Pretty Cold", PUBLIC);
        
    }
    
    if(temperature < 90 && temperature > 45){
        
        Particle.publish("temperature", "Normal", PUBLIC);
        
    }
    
    Particle.publish("humidity", String(humidity), PUBLIC);

  delay(1000);
  
} 
    
