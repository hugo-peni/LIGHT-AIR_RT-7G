int PUSH_PINK = 3;
int PUSH_GREEN = 2;
int LIGHT = 5;
int BUBBLE = 4;

int trigg = 10;
int THRO_LIGHT = 30;
int THRO_BUBBLE = 235;
int cycle_count;

int PREV_STATE_PINK, STATE_PINK;
int PREV_STATE_GREEN, STATE_GREEN;
int EN_LIGHT;
int EN_BUBBLE;



unsigned long T1, T2;
unsigned long T1_FIRE = 4320000;
unsigned long T2_FIRE =  100000;

int BUBBLE_AUTH = 0, LIGHT_AUTH = 0;


void POWER_BUBBLE(){
   if(EN_BUBBLE){
       analogWrite(BUBBLE, THRO_BUBBLE);       
    }
    else{
       analogWrite(BUBBLE, 0);
    }
}

void POWER_LIGHT(){
   if(EN_LIGHT){
       analogWrite(LIGHT, THRO_LIGHT);
   } 
   else{
       analogWrite(LIGHT, 0);
   }  
}


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
 
  PREV_STATE_PINK = STATE_PINK;
  STATE_PINK = digitalRead(PUSH_PINK);
  PREV_STATE_GREEN = STATE_GREEN;
  STATE_GREEN = digitalRead(PUSH_GREEN);

  
    if(PREV_STATE_PINK && !STATE_PINK){
      EN_LIGHT = !EN_LIGHT;
      LIGHT_AUTH = !LIGHT_AUTH;
      T1 = 0;
      POWER_LIGHT();
    }

    if(PREV_STATE_GREEN && !STATE_GREEN){
      EN_BUBBLE = !EN_BUBBLE;
      BUBBLE_AUTH = !BUBBLE_AUTH;
      T2 = 0;
      POWER_BUBBLE();
    }

    if(T1 == T1_FIRE && LIGHT_AUTH){
      T1 = 0;
      EN_LIGHT = !EN_LIGHT;
      POWER_LIGHT();
    }
    if(T2 == T2_FIRE && BUBBLE_AUTH){
      T2 = 0;
      EN_BUBBLE = !EN_BUBBLE;
      POWER_BUBBLE();
    }
    if(!LIGHT_AUTH){
      //T1 = 0;
      EN_LIGHT = 0;
      POWER_LIGHT();
    }
    if(!BUBBLE_AUTH){
      //T2 = 0;
      EN_BUBBLE = 0;
      POWER_BUBBLE();
    }
   
  T1++;
  T2++;
  delay(10);
}
