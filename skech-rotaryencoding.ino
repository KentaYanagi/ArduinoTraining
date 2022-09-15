int pinA=2;
int pinB=4;

int preValA=-1;
int preValB=-1;
int rotation=0;

int JudgeHighLow(int a){
  if(a==HIGH)return 1;
  else return 0;
}

int JudgeRotate(int a,int b, int preA, int preB){
  if(preA==0 && preB==0){
    if(a==1 && b==0)return 1;
    else if(a== 0 && b==1)return -1;
    else return 0;
  }
  if(preA==1 && preB==0){
    if(a==1 && b==1)return 1;
     else if(a== 0 && b==0)return -1;
    else return 0;
  }
  if(preA==1 && preB==1){
    if(a==0 && b==1)return 1;
     else if(a== 1 && b==0)return -1;
    else return 0;
  }
  if(preA==0 && preB==1){
    if(a==0 && b==0)return 1;
     else if(a== 1 && b==1)return -1;
    else return 0;
  }
}

void setup() {                //一回だけ実行
  pinMode(13, OUTPUT);        //LEDを接続した13番ピンを出力用に設定する
  Serial.begin(9600);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  preValA=JudgeHighLow(digitalRead(pinA));
  preValB=JudgeHighLow(digitalRead(pinB));
}


void loop() {                 //{}内を無限ループで実行
  //digitalWrite(13, HIGH);
  int valA=JudgeHighLow(digitalRead(pinA));
  int valB=JudgeHighLow(digitalRead(pinB));
  rotation += JudgeRotate(valA, valB, preValA, preValB);
  if (rotation<0) rotation+=5000;
  else rotation%=5000;
  Serial.println(rotation, DEC);
  preValA=valA;
  preValB=valB;
  /*
  Serial.write('0' + valA);
  Serial.write(' ');
  Serial.write('0' + valB);
  Serial.write(n);
  */
  //delay(500);                //1000ms(1秒)待ちます
}
