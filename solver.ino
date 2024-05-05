
Solver solver;

void initSolver(){
  solver.duration = 0;
  solver.diceType = 0;
  solver.diceValue = 0;
  solver.startFrame = 0;
  solver.currentFrame = 0;
  solver.frameDelay = 2;
}

int throwDice(int max) {
    return (rand() % diceValues[max]) + 1;
}

void animateThrow(){

  if (solver.currentFrame < solver.duration || solver.currentFrame == solver.duration) {
    if(gb.frameCount % solver.frameDelay == 0){
      solver.diceValue = throwDice(solver.diceType);
      solver.frameDelay++;
    }
    solver.currentFrame++;
    
  }
}

void startSolver(int diceType, int duration){
  setDice(getChooserSelection());
  solver.diceType = diceType;
  solver.duration = duration;
  solver.startFrame = gb.frameCount;
}

void showSolver(){
  gb.display.cursorX = 40;
  gb.display.cursorY = 18;
  gb.display.fontSize = 2;
  gb.display.print(solver.diceValue);
  gb.display.fontSize = 1;
}

int getDiceValue(){
  return solver.diceValue;
}