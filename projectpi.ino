int led = D1;
int boardLed = 18;

void setup() {
    
    pinMode(led,OUTPUT); 
    pinMode(boardLed,OUTPUT); 
    
    digitalWrite(led,LOW);
    digitalWrite(boardLed,LOW);
    
    Particle.subscribe("ahans_project_handler_2000", myHandler);
    
}

void loop() {

}

void myHandler(const char *event, const char *data)
{
    
    if (strcmp(data,"led-off")==0) {
        
        digitalWrite(led,LOW);
        digitalWrite(boardLed,LOW);
        
    }
    
    else if (strcmp(data,"led-on")==0) {
        
        digitalWrite(led,HIGH);
        digitalWrite(boardLed,HIGH);
        
    }

}
