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
const byte spark[] PROGMEM = {5,5,
B00100,
B01110,
B11111,
B01110,
B00100,
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
  int offsetX;
} Solver;

typedef struct {
  int currentDice;
} DiceDisplay;

typedef struct {
  int total;
  int offsetX;
  int index;
  String text;
  int resetProgress;
} Adder;

typedef struct {
  int numParticles;
  int originX;
  int originY;
  int delta;
} Handler;

int diceValues[] = {4, 6, 8, 10, 12, 20, 100};  // Dice options
int displayControl = 0;
int resumeTime = 0;
bool showParticle = false;
int particleStart = 0;
int resetTime = 30;

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
    gb.display.cursorX = 70;
    gb.display.print(gb.getCpuLoad());
    drawMenu();
    updateChooser();
    drawChooser();

    if(gb.buttons.pressed(BTN_A) && (gb.frameCount - resumeTime) > 5){
      displayControl = 1;
      initSolver();
      startSolver(getChooserSelection(), 40);
    }
    if(gb.buttons.timeHeld(BTN_B) == resetTime){
      initAdder();
    }

    if (displayControl == 0) {
      showSelection();
    } else if (displayControl == 1) {
      animateThrow();
      showSolver();
    } else if (displayControl == 2) {
      showSolver();
      if(gb.frameCount - particleStart < 12 && showParticle){
        animateEffect();
        showEffect();
      }else{
        showParticle = false;
      }
    }
    showDisplay();
    
    if(gb.buttons.repeat(BTN_LEFT, 2)){
      moveAdder(-2);
    }else if(gb.buttons.repeat(BTN_RIGHT, 2)){
      moveAdder(2);
    }
    showAdder();
  }
  
}

void initGame(){
  gb.titleScreen(F("Pyditns Dice Thrower"));
  gb.pickRandomSeed(); //pick a different random seed each time for games to be different
  gb.battery.show = false; //hide the battery indicator
  
  displayControl = 0;
  resumeTime = gb.frameCount;
  initSolver();
  initChooser();
  initDisplay();
  initAdder();
  initEffect();
}