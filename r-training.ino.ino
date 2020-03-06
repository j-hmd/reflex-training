/* 
Author: Juliana
Date: Mar 5 2020

Purpose: aid on reflex training using a visual queue and a response (pushing a button)

*/


/*--- Variable Definition ---*/  
  int buttonA = 2;
  int buttonB = 3
//int buttonC = 4
//int buttonD = 5


bool pressedA;                       // flag indicating state of button
bool pressedB;

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
  // Selecting a random number random(min, max)
  int target = random(1, 2);
  int i;   // counter
  
  // Blinking LED
  for (i=0;i<target;i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  
  // Invert the state of pressed if pushbutton is high (has been pressed) Obs: if user presses the button for a little too long, the program detects a switch in state too fast, generating a false positive, so increased the delay time to 200
  if (digitalRead(buttonA) == HIGH) {         
    pressedA = !pressedA; 
    delay(200);            
  }

  if (digitalRead(buttonB) == HIGH) {
    pressedB = !pressedB;
    delay(200);
  }

  // Printing Results //
  //Serial.print("The button is: ");
  Serial.println(pressed);
}
