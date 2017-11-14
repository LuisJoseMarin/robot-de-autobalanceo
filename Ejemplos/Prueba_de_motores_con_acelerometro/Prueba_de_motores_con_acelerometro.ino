const int rightf = 11;
const int rightb = 10;
const int leftf = 9;
const int leftb = 8;               
const int zpin = A2; 
String out = "";

void setup() {
  pinMode(rightf, OUTPUT);
  pinMode(rightb, OUTPUT);
  pinMode(leftf, OUTPUT);
  pinMode(leftb, OUTPUT);
  Serial.begin(9600);

}

void loop() {
 int z = analogRead(zpin);
 float zero_G = 338.0;
 float zero_Gz=340.0;
 float scale_z = 68;

 Serial.println(out);

 if (((float)z - zero_Gz)/scale_z >= 0.3){
    digitalWrite(rightf, HIGH);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, HIGH);
    digitalWrite(leftb, LOW);
    out = "Forward";   
 } else if (((float)z - zero_Gz)/scale_z <= -0.1){
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, HIGH);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, HIGH); 
    out = "Backward";
 }else{
    digitalWrite(rightf, LOW);
    digitalWrite(rightb, LOW);
    digitalWrite(leftf, LOW);
    digitalWrite(leftb, LOW);
    out = "Center";
 }
}
