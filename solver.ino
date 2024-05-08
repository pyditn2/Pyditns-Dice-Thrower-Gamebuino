
Solver solver;

void initSolver(){
  solver.duration = 0;
  solver.diceType = 0;
  solver.diceValue = 0;
  solver.startFrame = 0;
  solver.currentFrame = 0;
  solver.frameDelay = 2;
  solver.offsetX = 0;
}

//generates a random number between 1 and max
int throwDice(int max) {
    return (rand() % diceValues[max]) + 1;
}

//animates the throw by cycling throw random possible numbers, until it lands on a final number
void animateThrow(){

  if (solver.currentFrame < solver.duration || solver.currentFrame == solver.duration) {
    if(gb.frameCount % solver.frameDelay == 0){
      solver.diceValue = throwDice(solver.diceType);
      solver.frameDelay++;
    }
    solver.currentFrame++;
    
  }
}

//prepares the solver for the animation by setting the required parameters
void startSolver(int diceType, int duration){
  setDice(getChooserSelection());
  solver.diceType = diceType;
  solver.duration = duration;
  solver.startFrame = gb.frameCount;
}

//draws the current diceValue to the screen
void showSolver(){
  if(solver.diceType != 0 || solver.diceType != 1 || solver.diceType != 2 || solver.diceType != 6){
    if(solver.diceValue < 10){
      solver.offsetX = 4;
    }
  }
  if(solver.diceType == 6){
    if(solver.diceValue < 100){
      solver.offsetX = 4;
      if(solver.diceValue < 10){
        solver.offsetX = 8;
      }
    }
  }

  gb.display.cursorX = 50 + solver.offsetX;
  gb.display.cursorY = 10;
  gb.display.fontSize = 2;
  gb.display.print(solver.diceValue);
  gb.display.fontSize = 1;

  solver.offsetX = 0;
}

//returns the current diceValue
int getDiceValue(){
  return solver.diceValue;
}