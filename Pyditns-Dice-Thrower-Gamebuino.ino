//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;

const byte arrow[] PROGMEM = {8,5,
B00100000,
B01100000,
B11111100,
B01100000,
B00100000,
};


typedef struct {
  byte current;
  byte max;
  byte x;
  boolean right;
} Arrow;

typedef struct {
  int duration;
  int diceValue;
  int diceType;
  int startFrame;
  int currentFrame;
  int frameDelay;
} Solver;

typedef struct {
  int currentDice;
} DiceDisplay;

int diceValues[] = {4, 6, 8, 10, 12, 20, 100};  // Dice options
int displayControl = 0;


// the setup routine runs once when Gamebuino starts up
void setup(){
  // initialize the Gamebuino object
  gb.begin();
  initGame();
  
}

// the loop routine runs over and over again forever
void loop(){
  //updates the gamebuino (the display, the sound, the auto backlight... everything)
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update()){
    if(gb.buttons.pressed(BTN_C)){
      initGame();
    }
    
    drawMenu();
    updateChooser();
    drawChooser();

    if(gb.buttons.pressed(BTN_B) && gb.frameCount > 5){
      displayControl = 1;
      initSolver();
      startSolver(getChooserSelection(), 40);
      
    }

    if(displayControl == 0){
      showSelection();

    }
    if(displayControl == 1){
      animateThrow();
      showSolver();
      
    }
  }
  showDisplay();
}

void initGame(){
  gb.titleScreen(F("Pyditns Dice Thrower"));
  gb.pickRandomSeed(); //pick a different random seed each time for games to be different
  gb.battery.show = false; //hide the battery indicator
  
  displayControl = 0;
  initSolver();
  initChooser();
  initDisplay();
}