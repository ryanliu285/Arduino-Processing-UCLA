//www.elegoo.com
//2016.12.08
#include <Servo.h>
int x = 0;
int speed;
int oldspeed;
int looped = 0;

Servo leftservo;  // create servo object to control left servo
Servo rightservo; // create servo object to control right servo
// twelve servo objects can be created on most boards

int info = 123;

int leftnum=7;
int rightnum=9;

void setup() {
  leftservo.attach(leftnum);  // attaches the servo on pin 9 to the servo object
  rightservo.attach(rightnum);
  oldspeed = 90;
  Serial.begin(9600);
  
}
void forwardleft(){
      for (int pos = oldspeed; pos <= speed; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        leftservo.write(pos);            
      }
}

void forwardright(){ 
  for (int pos = oldspeed; pos >= speed; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(pos);              // tell servo to go to position in variable 'pos'
  }
}

void backwardleft() {
  for (int pos = oldspeed; pos >= speed; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftservo.write(pos);
  }
}

void backwardright(){
  for (int pos = oldspeed; pos <= speed; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(pos);              // tell servo to go to position in variable 'pos'
  }
}

void bothforward(){
  int x = oldspeed;
  for (int pos = oldspeed; pos <= speed; pos += 1) {
      leftservo.write(pos);
      rightservo.write(x);
      x--; 
  }
}

void bothbackward(){
  int x = oldspeed;
  for (int pos = oldspeed; pos >= speed; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(x);
    leftservo.write(pos);
    x++;
    Serial.println("going back");
  }
}
void later(){
  int x = oldspeed;
  for (int pos = oldspeed; pos <= speed; pos += 1) {
      leftservo.write(pos);
      rightservo.write(x);
      x--;   
  }
  x=0;
}

void laterj(){
  int x = oldspeed;
  for (int pos = oldspeed; pos >= speed; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(pos);
    leftservo.write(x);
    x++;
  }
  x=0;
}

void stopIt(){
  leftservo.write(90);
  rightservo.write(90);
  oldspeed=90;
  info=-1;
}

void loop() {
  int temp=(int)Serial.read();
  looped++;
  if(temp==-1){
    return;
  }
  if(speed == temp-7){
    return;
  }
  Serial.println(temp);
  if(temp <= 6 ){
    info = temp;
  }else if(temp>6){
    if(looped!=1){
    oldspeed = speed;}
    speed = temp-7;
  }
  /*if(speed == 999){
    return;
  }*/
  if(speed == 90){
    return;
  }
  
      if(info==3||info==4||info==5){
        if(speed>90){
          speed-=180;
          speed*=-1;
        }else{
          speed-=180;
          speed*=-1;
        }
      }
      
  if(info==0 && speed>=oldspeed){
    forwardleft();
    //speed = 999;
    return;
  }else if(info==0 && speed <oldspeed){
    backwardleft();
    //speed = 999;
    return;
  }
  if(info==1 && speed <=oldspeed){
         forwardright();
         Serial.println("Forward Right");
         //speed = 999;
         return;
    }else if (info == 1 && speed>oldspeed){
      backwardright();
  //speed = 999;
    return;
    }
  if(info==2 && speed >=oldspeed){
    bothforward();
  //speed = 999;
    return;
  }else if (info == 2 && speed <oldspeed){
    bothbackward();
  //speed = 999;
    return;
  }
  if(info==4 && speed >= oldspeed){
    backwardright();
    Serial.println("Backward Right");
  //speed = 999;
    return;
  }else if (info == 4 && speed <= oldspeed){
    forwardright();
  //speed = 999;
    return;
  }
  if(info==3 && speed >= oldspeed){
    backwardleft();
 // speed = 999;
    return;
  }else if (info ==3 && speed <oldspeed){
    forwardleft();
  //speed = 999;
    return;
  }
  if(info==5 && speed<=oldspeed){
    bothbackward();
  //speed = 999;
    return;  
  }else if (info==5&&speed>=oldspeed){
    bothforward();
  //speed = 999;
    return;
  }
  if(info==6){
    stopIt();
    //speed=999;
  }
  /*if(info==0){
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos=180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    leftservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  if(info==1){
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos=0; pos <= 90; pos += 1) { // goes from 180 degrees to 0 degrees
    rightservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  if(info==2){
    int x = 90;
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftservo.write(pos);
    rightservo.write(x);
    x--;
    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  x=0;
  for (pos=180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    leftservo.write(pos); 
    rightservo.write(x);
    x++;
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  if(info==4){
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos=180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    rightservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  if(info==3){
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos=0; pos <= 90; pos += 1) { // goes from 180 degrees to 0 degrees
    leftservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  if(info==5){
    int x = 90;
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightservo.write(pos);
    leftservo.write(x);
    x--;
    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  x=0;
  for (pos=180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    rightservo.write(pos); 
    leftservo.write(x);
    x++;
    delay(15);                       // waits 15ms for the servo to reach the position
  }}*/
}
