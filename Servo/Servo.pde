import processing.serial.*;
import java.nio.ByteBuffer;
String status;
Serial port;
HScrollbar slider; 

void setup(){
  size(1800,800);
  port = new Serial(this, "COM6", 9600);
  port.bufferUntil('\n');
   slider = new HScrollbar(0,700,width,40,20);
}

void draw(){
   background(123);
   fill(200);
   rect(4,4,800,100);
   rect(4,110,800,100);
   rect(4,215,800,100);
   rect(4,320,800,100);
   rect(4,425,800,100);
   rect(4,530,800,100);
   rect(810,530,800,100);
   fill(0);
   textSize(50);
   text("LEFT SERVO FRWD",100,70);
   textSize(50);
   text("RIGHT SERVO FRWD",100,180);
   textSize(50);
   text("BOTH SERVOS FRWD",100,280);  
   textSize(50);
   text("LEFT SERVO BACK",100,390);
   textSize(50);
   text("RIGHT SERVO BACK",100,500);
   textSize(50);
   text("BOTH SERVOS BACK",100,600);  
   text("STOP",1150,600);  
   textSize(20);
   text("-100%",0,750);
   text("0%",890,750);
   text("100%",1750,750);
   port.write((int)slider.getPos()/10+7);
   slider.update();
   slider.display();
}
void serialEvent(Serial port){
  status = (String)(port.readStringUntil('\n'));
  println(status);
}
void mouseClicked()
{
  println(slider.getPos());
   port.write((int)slider.getPos()/10+7);
   if((mouseY>=4&&mouseY<=104)&&(mouseX>=4&&mouseX<=800)){
     port.write(0);
     //println(0);
     fill(155,155,155,155);
     rect(4,4,800,100);
   }else if((mouseY>=110&&mouseY<=210)&&(mouseX>=4&&mouseX<=800)){
     port.write(1);
     //println(1);
     fill(155,155,155,155);
     rect(4,110,800,100);
   }else if((mouseY>=215&&mouseY<=315)&&(mouseX>=4&&mouseX<=800)){
     port.write(2);
     //println(2);
     fill(155,155,155,155);
     rect(4,215,800,100);   
   }else if((mouseY>=320&&mouseY<=420)&&(mouseX>=4&&mouseX<=800)){
     port.write(3);
     //println(3);
     fill(155,155,155,155);
     rect(4,320,800,100);
   }else if((mouseY>=425&&mouseY<=525)&&(mouseX>=4&&mouseX<=800)){
     port.write(4);
     //println(4);
     fill(155,155,155,155);
     rect(4,425,800,100);
   }else if((mouseY>=530&&mouseY<=630)&&(mouseX>=4&&mouseX<=800)){
     port.write(5);
     //println(5);
     fill(155,155,155,155);
     rect(4,530,800,100);
   }else if(((mouseY>=530&&mouseY<=630)&&(mouseX>=810&&mouseX<=1610))){
      port.write(6);
     //println(6);
   slider = new HScrollbar(0,700,width,40,20);
     fill(155,155,155,155);
     rect(810,530,800,100);
   }
}
void hideSlider(){
  
}
class HScrollbar {
  int swidth, sheight;    // width and height of bar
  float xpos, ypos;       // x and y position of bar
  float spos, newspos;    // x position of slider
  float sposMin, sposMax; // max and min values of slider
  int loose;              // how loose/heavy
  boolean over;           // is the mouse over the slider?
  boolean locked;
  float ratio;

  HScrollbar (float xp, float yp, int sw, int sh, int l) {
    swidth = sw;
    sheight = sh;
    int widthtoheight = sw - sh;
    ratio = (float)sw / (float)widthtoheight;
    xpos = xp;
    ypos = yp-sheight/2;
    spos = xpos + swidth/2 - sheight/2;
    newspos = spos;
    sposMin = xpos;
    sposMax = xpos + swidth - sheight;
    loose = l;
  }

  void update() {
    if (overEvent()) {
      over = true;
    } else {
      over = false;
    }
    if (mousePressed && over) {
      locked = true;
    }
    if (!mousePressed) {
      locked = false;
    }
    if (locked) {
      newspos = constrain(mouseX-sheight/2, sposMin, sposMax);
    }
    if (abs(newspos - spos) > 1) {
      spos = spos + (newspos-spos)/loose;
    }
  }

  float constrain(float val, float minv, float maxv) {
    return min(max(val, minv), maxv);
  }

  boolean overEvent() {
    if (mouseX > xpos && mouseX < xpos+swidth &&
       mouseY > ypos && mouseY < ypos+sheight) {
      return true;
    } else {
      return false;
    }
  }

  void display() {
    noStroke();
    fill(204);
    rect(xpos, ypos, swidth, sheight);
    if (over || locked) {
      fill(0, 0, 0);
    } else {
      fill(102, 102, 102);
    }
    rect(spos, ypos, sheight, sheight);
  }

  float getPos() {
    // Convert spos to be values between
    // 0 and the total width of the scrollbar
    return spos * ratio;
  }
}
public byte [] convert (float value)
{  
     return ByteBuffer.allocate(4).putFloat(value).array();
}