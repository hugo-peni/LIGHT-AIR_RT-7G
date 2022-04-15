int PUSH_PINK = 3;
int PUSH_GREEN = 2;
int LIGHT = 5;
int BUBBLE = 4;

int trigg = 10;
int THRO_LIGHT = 30;
int THRO_BUBBLE = 255;
int cycle_count;

int PREV_STATE_PINK, STATE_PINK;
int PREV_STATE_GREEN, STATE_GREEN;
int EN_LIGHT;
int EN_BUBBLE;

void setup() {
  // put your setup code here, to run once:
pinMode(PUSH_PINK, INPUT_PULLUP);
pinMode(PUSH_GREEN, INPUT_PULLUP);
pinMode(LIGHT, OUTPUT);
pinMode(BUBBLE, OUTPUT);

analogWriteFrequency(LIGHT, 40000);
analogWriteFrequency(BUBBLE, 40000);

analogWriteResolution(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  PREV_STATE_PINK = STATE_PINK;
  STATE_PINK = digitalRead(PUSH_PINK);
  PREV_STATE_GREEN = STATE_GREEN;
  STATE_GREEN = digitalRead(PUSH_GREEN);

  
  if(PREV_STATE_PINK && !STATE_PINK){
      EN_LIGHT = !EN_LIGHT;
      if(EN_LIGHT){
        analogWrite(LIGHT, THRO_LIGHT);
      }
      else{
        analogWrite(LIGHT, 0);
      }
    }

    if(PREV_STATE_GREEN && !STATE_GREEN){
      EN_BUBBLE = !EN_BUBBLE;
      if(EN_BUBBLE){
        analogWrite(BUBBLE, THRO_BUBBLE);       
      }
      else{
        analogWrite(BUBBLE, 0);
      }
    }

  
  delay(10);
}

/*void FALL_PINK(){
    if(PREV_STATE_PINK && !STATE_PINK){
      EN_LIGHT = !EN_LIGHT;
      if(EN_LIGHT){
        analogWrite(LIGHT, THRO_LIGHT);
      }
      else{
        analogWrite(LIGHT, 0);
      }
    }
}

void FALL_GREEN(){
    if(PREV_STATE_GREEN && !STATE_GREEN){
      EN_BUBBLE = !EN_BUBBLE;
      if(EN_BUBBLE){
        analogWrite(BUBBLE, THRO_BUBBLE);
        
      }
      else{
        analogWrite(BUBBLE, 0);
      }
    }
}

/*void FALL_PINK(){
  if(cycle_count > trigg){
    PREV_STATE_PINK = STATE_PINK;
    STATE_PINK = digitalRead(PUSH_PINK);
    if(PREV_STATE_PINK && !STATE_PINK){
      EN_LIGHT = !EN_LIGHT;
      if(EN_LIGHT){
        //analogWrite(LIGHT, THRO_LIGHT);
      }
      else{
        //analogWrite(LIGHT, 0);
      }
    }
  }
}

void FALL_GREEN(){
  if(cycle_count > trigg){
    cycle_count = 0;
    PREV_STATE_GREEN = STATE_GREEN;
    STATE_GREEN = digitalRead(PUSH_GREEN);
    if(PREV_STATE_GREEN && !STATE_GREEN){
      EN_BUBBLE = !EN_BUBBLE;
      if(EN_BUBBLE){
        //analogWrite(BUBBLE, THRO_BUBBLE);
        
      }
      else{
        //analogWrite(BUBBLE, 0);
      }
    }
  }
}*/
