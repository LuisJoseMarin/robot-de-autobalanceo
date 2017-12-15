#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define rightf 7
#define rightb 8
#define leftf 9
#define leftb 10               
#define zpin A2
#define xpin A1
float zz;
float xx;
int frequencyR = 0;
int frequencyB = 0;
int frequencyG = 0;

 

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(rightf, OUTPUT);
  pinMode(rightb, OUTPUT);
  pinMode(leftf, OUTPUT);
  pinMode(leftb, OUTPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);
}

void loop(){
  //RGB();
  //color();
  equilibrio();
  acelerometro();
}

void acelerometro() {
  int x = analogRead(xpin);
  int z = analogRead(zpin);
  float zero_G = 338.0;
  float zero_Gx = 331.5;
  float zero_Gz = 340.0;
  float scale = 67.6;
  float scale_x = 65;
  float scale_z = 68;
  zz = ((float)z - zero_Gz)/scale_z;
  xx = ((float)x - zero_Gx)/scale_x;
  
  Serial.print(xx);
  Serial.print("\t");
  Serial.print(zz);
  Serial.print("\n");
} 
  
void equilibrio() {
 if (zz <= -0.04 && xx >= -1.08 ){
    digitalWrite(rightf, HIGH);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, HIGH);
    digitalWrite(leftb, LOW);
       
 } else if ( zz >= 0.00 && xx >= -1.08){
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, HIGH);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, HIGH); 
    
 }else{
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, LOW);
 }
}

void color(){
  if (frequencyR <= 270 && frequencyB <= 50 && frequencyG <= 250){
    equilibrio();
  }else{
    equilibrio();
  }
}
  
void RGB(){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequencyR = pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequencyG = pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequencyB = pulseIn(sensorOut, LOW);
  delay(100);
}
