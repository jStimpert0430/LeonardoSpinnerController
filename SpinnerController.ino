//Joshua Stimpert - Arduino Leonardo Spinner Controller code with button support for Arduino uno and Ky-040 rotary encoder module  - based upon the poll example found in 'brianlow''s rotary library.

#include <Rotary.h>
#include <Mouse.h>


int pushButton = 8;
int val;
bool buttonPushed = false;

// Rotary encoder is wired with the common to ground and the two
// outputs to pins 3 and 5.
Rotary rotary = Rotary(3 ,4);

// Counter that will be incremented or decremented by rotation.
int counter = 0;

void setup() {
    pinMode (pushButton, INPUT_PULLUP);
  Mouse.begin();
  
}

void loop() {
  unsigned char result = rotary.process();
  val = digitalRead(pushButton);
  if(val == LOW){
    buttonPushed = true;
    Mouse.press();
  }
  else{
    Mouse.release();
  }
  if (result == DIR_CW) {
         Mouse.move(20, 0);
  } else if (result == DIR_CCW) {
       Mouse.move(-20, 0);
  }
}
