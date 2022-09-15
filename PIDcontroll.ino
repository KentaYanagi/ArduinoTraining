void setup() {
  // put your setup code here, to run once:

  

}

const int Kp=1;
const int Ki=2;
const int Kd=3; 
int preValueDif=0;
int sumValueDif=0;

void loop() {
  // put your main code here, to run repeatedly:

int input=2;
int goal=3;
int ValueDif=goal-input;
sumValueDif+=ValueDif;
int DValueDif=ValueDif-preValueDif;
int output=Kp*ValueDif+Ki*sumValueDif+Kd*DValueDif;
preValueDif=ValueDif;

}
