//...
#define SAMPLE_DELAY (1000)   //  this gets 1 reading per second.
#define pin_A_encodeur 8
#define outputB 9//  adjust the delay to fit your needs
#define PULSES_PER_TURN (32)  //  32 state changes per turn on 1 line, 
unsigned int pulseCount;
bool lastState;
unsigned int lastTime; 
float rpm;                    // speed in turns/minute, doesn't have to be floating point.

void setup()
{
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
    pinMode(pin_A_encodeur, INPUT);
    lastState = digitalRead(pin_A_encodeur);
    Serial.begin(9600);
}

void loop()
{
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
    bool curState = digitalRead(pin_A_encodeur);
    if (curState != lastState)
    {
      if(digitalRead(outputB) != curState)
      {
        pulseCount++;
        }else{
          pulseCount++;
        }
        lastState = curState;
    }

    if ((unsigned int)millis() - lastTime >= SAMPLE_DELAY)  
    {
         rpm = (pulseCount * (60000.f / ((unsigned int)millis() - lastTime))) / PULSES_PER_TURN;
         pulseCount = 0;
         lastTime = (unsigned int)millis();
    }
    Serial.println(rpm);
    
    //...
}
