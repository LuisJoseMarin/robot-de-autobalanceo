const int buttonf = 3;
const int buttonb = 2;
const int buttonleft = 4;
const int buttonright = 5;
int buttonstatef = 0;
int buttonstateb = 0;
int buttonstateleft = 0;
int buttonstateright = 0;

const int rightf = 11;
const int rightb = 10;
const int leftf = 9;
const int leftb = 8;

void setup() {
  // put your setup code here, to run once:

  pinMode(buttonf, INPUT);
  pinMode(buttonb, INPUT);
  pinMode(buttonleft, INPUT);
  pinMode(buttonright, INPUT);
  pinMode(rightf, OUTPUT);
  pinMode(rightb, OUTPUT);
  pinMode(leftf, OUTPUT);
  pinMode(leftb, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonstatef = digitalRead(buttonf);
  buttonstateb = digitalRead(buttonb);
  buttonstateleft = digitalRead(buttonleft);
  buttonstateright = digitalRead(buttonright);


  if (buttonstatef == HIGH && buttonstateb == LOW && buttonstateleft == LOW && buttonstateright == LOW){
    digitalWrite(rightf, HIGH);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, HIGH);
    digitalWrite(leftb, LOW);   
  } else if (buttonstatef == LOW && buttonstateb == HIGH && buttonstateleft == LOW && buttonstateright == LOW ){
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, HIGH);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, HIGH); 
  } else if (buttonstatef == LOW && buttonstateb == LOW && buttonstateleft == HIGH && buttonstateright == LOW){
    digitalWrite(rightf, HIGH);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, HIGH);
  } else if (buttonstatef == LOW && buttonstateb == LOW && buttonstateleft == LOW && buttonstateright == HIGH){
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, HIGH);
    digitalWrite(leftf, HIGH);
    digitalWrite(leftb, LOW);
  } else {
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, LOW);
  }

}
