/* 
Author: Juliana
Date: Mar 5 2020

Purpose: aid on reflex training using a visual queue and a response (pushing a button)

*/


/*--- Variable Definition ---*/  
  int buttonA = 2;
  int buttonB = 3;
  //int buttonC = 4;
  //int buttonD = 5;


  bool pressedA;                       // flag indicating state of button
  bool pressedB;

//  enum State_enum {DISPLAY, RESPONSE, CHECK};

// ********************* SET UP ********************* //
void setup() {
  /*--- Baud Rate ---*/ 
  Serial.begin(9600);  
  
  /*--- Pin Mode ---*/
  pinMode(buttonA, INPUT);          // define button as input
  pinMode(buttonB, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


// ********************** LOOP ********************** //
void loop() {

 // reflex_stateM_run();
  
  // Invert the state of pressed if pushbutton is high (has been pressed) Obs: if user presses the button for a little too long, the program detects a switch in state too fast, generating a false positive, so increased the delay time to 200
  if (digitalRead(buttonA) == HIGH) {         
    pressedA = !pressedA; 
    delay(200);            
  }

  if (digitalRead(buttonB) == HIGH) {
    pressedB = !pressedB;
    delay(200);
  }

  if(pressedA){
   newTargetNumber();
   delay(1000);
  }

  // Printing Results //
  //Serial.print("The button A is: "); //debug
  //Serial.println(pressedA); //degbug

  //Serial.print("The button B is: "); //debbug
  //Serial.println(pressedB); //debbug
}

// ********************* FUNCTIONS ********************* //
void reflex_stateM_run(){
  switch(state){
    case: DISPLAY
      newTargetNumber();
      state = RESPONSE;
    case: RESPONSE
      // check if the right button was pressed
      state = CHECK;
    case: CHECK
      state = DISPLAY;
  }
}

void newTargetNumber(){
  // Selecting a random number random(min, max) - not including max
  int target = random(1, 3);
  //Serial.print(target); //debbug 
  
  blink_builtin(tagret);
}

/*Blinkinh the built in LED a number of times*/
void blink_builtin(int times){
  int i = 0;
    for (i=0;i<times;i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
}
