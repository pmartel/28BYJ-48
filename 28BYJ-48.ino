//Written By Nikodem Bartnik - nikodembartnik.pl
// modified by Phil Martel
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

#define STEPPER2_PIN_1 5
#define STEPPER2_PIN_2 6
#define STEPPER2_PIN_3 7
#define STEPPER2_PIN_4 8

int step_number = 0;
long delay_u = 1800;

void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  pinMode(STEPPER2_PIN_1, OUTPUT);
  pinMode(STEPPER2_PIN_2, OUTPUT);
  pinMode(STEPPER2_PIN_3, OUTPUT);
  pinMode(STEPPER2_PIN_4, OUTPUT);
}

void loop() {
  int i;
#ifdef PHIL
  for( i = 0; i <2048; i++ ){
    OneStep(false);
    delayMicroseconds(delay_u);
  }
  for( i = 0; i <2048; i++ ){
    OneStep(true);
    delayMicroseconds(delay_u);
  }
#endif
  OneStep(false);
  delayMicroseconds(delay_u);
}


void OneStep(bool dir){
  if(dir){
    switch(step_number){
    case 0:
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      digitalWrite(STEPPER2_PIN_1, HIGH);
      digitalWrite(STEPPER2_PIN_2, LOW);
      digitalWrite(STEPPER2_PIN_3, LOW);
      digitalWrite(STEPPER2_PIN_4, LOW);
      break;
    case 1:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      digitalWrite(STEPPER2_PIN_1, LOW);
      digitalWrite(STEPPER2_PIN_2, HIGH);
      digitalWrite(STEPPER2_PIN_3, LOW);
      digitalWrite(STEPPER2_PIN_4, LOW);
      break;
    case 2:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      digitalWrite(STEPPER2_PIN_1, LOW);
      digitalWrite(STEPPER2_PIN_2, LOW);
      digitalWrite(STEPPER2_PIN_3, HIGH);
      digitalWrite(STEPPER2_PIN_4, LOW);
      break;
    case 3:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      digitalWrite(STEPPER2_PIN_1, LOW);
      digitalWrite(STEPPER2_PIN_2, LOW);
      digitalWrite(STEPPER2_PIN_3, LOW);
      digitalWrite(STEPPER2_PIN_4, HIGH);
      break;
    } 
  }
  else {
    switch(step_number){
    case 0:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      digitalWrite(STEPPER2_PIN_1, LOW);
      digitalWrite(STEPPER2_PIN_2, LOW);
      digitalWrite(STEPPER2_PIN_3, LOW);
      digitalWrite(STEPPER2_PIN_4, HIGH);
      break;
    case 1:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      digitalWrite(STEPPER2_PIN_1, LOW);
      digitalWrite(STEPPER2_PIN_2, LOW);
      digitalWrite(STEPPER2_PIN_3, HIGH);
      digitalWrite(STEPPER2_PIN_4, LOW);
      break;
    case 2:
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      digitalWrite(STEPPER2_PIN_1, LOW);
      digitalWrite(STEPPER2_PIN_2, HIGH);
      digitalWrite(STEPPER2_PIN_3, LOW);
      digitalWrite(STEPPER2_PIN_4, LOW);
      break;
    case 3:
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      digitalWrite(STEPPER2_PIN_1, HIGH);
      digitalWrite(STEPPER2_PIN_2, LOW);
      digitalWrite(STEPPER2_PIN_3, LOW);
      digitalWrite(STEPPER2_PIN_4, LOW);
    } 
  }
  step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
