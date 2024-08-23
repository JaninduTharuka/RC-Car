# define enR 9
# define enL 10
# define RB 2
# define RF 3
# define LB 4
# define LF 5
# define Side 13
# define Head 6
# define Tail 7
# define Horn 8
# define Interval 300
char in;
int Speed = 150;
long unsigned T;
long unsigned t = 0;
boolean X = 0;
boolean LED = LOW;

void Forward() {
  analogWrite(enR, Speed);
  analogWrite(enL, Speed);
  digitalWrite(RF,HIGH);digitalWrite(LF,HIGH);
  digitalWrite(RB,LOW);digitalWrite(LB,LOW);
}
void Reverse() {
  analogWrite(enR, Speed);
  analogWrite(enL, Speed);
  digitalWrite(RF,LOW);digitalWrite(LF,LOW);
  digitalWrite(RB,HIGH);digitalWrite(LB,HIGH);
}
void Right() {
  analogWrite(enR, 150);
  analogWrite(enL, 150);
  digitalWrite(RF,LOW);digitalWrite(LF,HIGH);
  digitalWrite(RB,HIGH);digitalWrite(LB,LOW);
}
void Left() {
  analogWrite(enR, 150);
  analogWrite(enL, 150);
  digitalWrite(RF,HIGH);digitalWrite(LF,LOW);
  digitalWrite(RB,LOW);digitalWrite(LB,HIGH);
}
void ForwardRight() {
  analogWrite(enR, Speed);
  analogWrite(enL, Speed);
  digitalWrite(RF,LOW);
}
void ForwardLeft() {
  analogWrite(enR, Speed);
  analogWrite(enL, Speed);
  digitalWrite(LF,LOW);
}
void BackRight() {
  analogWrite(enR, Speed);
  analogWrite(enL, Speed);
  digitalWrite(RB,LOW);
}
void BackLeft() {
  analogWrite(enR, Speed);
  analogWrite(enL, Speed);
  digitalWrite(LB,LOW);
}
void Stop() {
  digitalWrite(RF,LOW);digitalWrite(LF,LOW);
  digitalWrite(RB,LOW);digitalWrite(LB,LOW);
}
void HORN(boolean x) {
  if(x==1) {
    digitalWrite(Horn,HIGH);
  }else {
    digitalWrite(Horn,LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(Head, OUTPUT);
  pinMode(Tail,OUTPUT);
  pinMode(Side,OUTPUT);
  pinMode(Horn,OUTPUT);
  // Initialize motor speeds
  analogWrite(enR, 100);
  analogWrite(enL, 100);

  // Initialize Others
  HORN(0);
  digitalWrite(Head,LOW);
  digitalWrite(Tail,LOW);
  digitalWrite(Side,LOW);
}

void loop() {
  if(X==1) {
      T=millis();
      if( (T-t) >= Interval) {
        t=T;
        LED = !LED;
        digitalWrite(Side,LED);
        digitalWrite(Tail,LED);
        digitalWrite(Horn,LED);
      }
  }
  if (Serial.available() > 0) {
    in = Serial.read();

    switch (in) {
      case 'F':
        Forward();
        break;
      case 'B':
        Reverse();
        break;
      case 'R':
        Right();
        break;
      case 'L':
        Left();
        break;
      case 'I':
        ForwardRight();
        break;
      case 'G':
        ForwardLeft();
        break;
      case 'J':
        BackRight();
        break;
      case 'H':
        BackLeft();
        break;
      case 'S':
        Stop();
        break;
      case 'W':
        digitalWrite(Head, HIGH);
        digitalWrite(Side, HIGH);
        break;
      case 'w':
        digitalWrite(Head, LOW);
        digitalWrite(Side, LOW);
        break;
      case 'U':
        digitalWrite(Tail, HIGH);
        break;
      case 'u':
        digitalWrite(Tail, LOW);
        break;
      case 'X':
        X = 1;
        break;
      case 'x':
        X = 0;
        digitalWrite(Side,LOW);
        digitalWrite(Tail,LOW);
        digitalWrite(Horn,LOW);
        break;
      case 'V':
        HORN(1);
        break;
      case 'v':
        HORN(0);
        break;
      case '0':
        Speed = 0;
        break;
      case '1':
        Speed = 80;
        break;
      case '2':
        Speed = 100;
        break;
      case '3':
        Speed = 120;
        break;
      case '4':
        Speed = 140;
        break;
      case '5':
        Speed = 160;
        break;
      case '6':
        Speed = 180;
        break;
      case '7':
        Speed = 200;
        break;
      case '8':
        Speed = 220;
        break;
      case '9':
        Speed = 235;
        break;
      case 'q':
        Speed = 250;
        break;
      default:
        // Handle unknown commands or characters
        break;
    }
  }
}