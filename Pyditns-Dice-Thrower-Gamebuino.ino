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

const byte ingamelogo[] PROGMEM = {64,30,
B00000000,B00000000,B00000000,B00010000,B00000000,B00000000,B00000000,B00000000,
B00000111,B00000001,B01001000,B00100000,B00011111,B11100011,B00100000,B00000000,
B00000101,B00000001,B00001000,B00000000,B00100000,B01100010,B10000000,B00000000,
B00000101,B00000001,B00011101,B00000000,B01000000,B10100010,B10000000,B00000000,
B00000111,B01010111,B01001001,B11011100,B11111111,B00100010,B10101110,B11100000,
B00000100,B01010101,B01001001,B01010000,B10000001,B00100010,B10101000,B11100000,
B00000100,B01010101,B01001001,B01001100,B10111101,B00100010,B10101000,B10000000,
B00000100,B01110111,B01001101,B01011100,B10100001,B00100011,B00101110,B11100000,
B00000000,B00010000,B00000000,B00000000,B10111101,B00100000,B00000000,B00000000,
B00000000,B00010000,B00000000,B00000000,B10100101,B00100000,B00000000,B00000000,
B00000000,B01110000,B00000000,B00000000,B10111101,B01000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B10000001,B10000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111100,B00000101,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B10111101,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B10111101,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B10111101,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B10111100,B00110101,B00001011,B10100001,B01011111,B11111111,
B11111111,B11111111,B10111101,B10110011,B01101010,B10101101,B00111111,B11111111,
B11111111,B11111111,B10111101,B10110111,B01101010,B10100001,B01111111,B11111111,
B11111111,B11111111,B10111101,B10110111,B01101010,B10101111,B01111111,B11111111,
B11111111,B11111111,B10111101,B10110111,B00001001,B00100001,B01111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
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

const uint16_t dice_sound[] PROGMEM = {0x0045, 0x012C, 0x0000};

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
    //gb.display.cursorX = 70;
    //gb.display.print(gb.getCpuLoad());
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
  gb.titleScreen(F("Digi Dice Deluxe"), ingamelogo);
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