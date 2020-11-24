//Written By Nikodem Bartnik - nikodembartnik.pl
// modified by Phil Martel
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

int step_number = 0;
long delay_u = 1800;

void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {
  int i;
  OneStep(false);
  //delayMicroseconds(delay_u);
  delay(100);
}


void OneStep(bool dir){
  static byte phase = 1;
  
  digitalWrite(STEPPER_PIN_1, phase & 1);
  digitalWrite(STEPPER_PIN_2, phase & 2);
  digitalWrite(STEPPER_PIN_3, phase & 4);
  digitalWrite(STEPPER_PIN_4, phase & 8);
  if(dir){
    phase <<= 1;
    if ( phase > 8 ) {
      phase = 1;
    }
  }
  else {
    phase >>= 1;
    if ( phase < 1 ) {
      phase = 8;
    }
  }
}
