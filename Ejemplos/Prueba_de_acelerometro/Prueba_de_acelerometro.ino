const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models)
void setup()
{
 // initialize the serial communications:
 Serial.begin(9600);
}
void loop()
{
 int x = analogRead(xpin);  //read from xpin
 delay(1); //
 int y = analogRead(ypin);  //read from ypin
 delay(1);  
 int z = analogRead(zpin);  //read from zpin
 
 float zero_G = 338.0; //ADXL335 power supply by Vs 3.3V:3.3V/5V*1024=676/2=338
//Serial.print(x); 
//Serial.print("\t");
//Serial.print(y);
//Serial.print("\t");
//Serial.print(z);  
//Serial.print("\n");
float zero_Gx=331.5;//the zero_G output of x axis:(x_max + x_min)/2
float zero_Gy=329.5;//the zero_G outgput of y axis:(y_max + y_min)/2
float zero_Gz=340.0;//the zero_G output of z axis:(z_max + z_min)/2

float scale = 67.6;//power supply by Vs 3.3V:3.3v /5v *1024/3.3v *330mv/g =67.6g
float scale_x = 65;//the scale of x axis: x_max/3.3v*330mv/g
float scale_y = 68.5;//the scale of y axis: y_max/3.3v*330mv/g
float scale_z = 68;//the scale of z axis: z_max/3.3v*330mv/g

Serial.print(((float)x - zero_Gx)/scale_x);  //print x value on serial monitor
Serial.print("\t");
Serial.print(((float)y - zero_Gy)/scale_y);  //print y value on serial monitor
Serial.print("\t");
Serial.print(((float)z - zero_Gz)/scale_z);  //print z value on serial monitor
Serial.print("\n");
delay(100);  //wait for 1 second 
}
