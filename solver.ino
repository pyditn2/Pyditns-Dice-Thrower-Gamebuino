
Solver solver;

void initSolver(){
  solver.input = 0;
  solver.isRolling = false;
  solver.diceValue = 0;
  solver.solverControl = false;
}

int throwDice(int max) {
    return (rand() % diceValues[max]) + 1;
}

void animateThrow(int max){
  int updateCadence = 1;
  int counter = 0;

  if(gb.frameCount % updateCadence == 0){
    gb.display.cursorX = 40;
    gb.display.cursorY = 18;
    gb.display.fontSize = 2;
    gb.display.print(throwDice(max));
    gb.display.fontSize = 1;
    counter ++;
    if (counter == 5){
      updateCadence++;
      if(updateCadence == 6){
        solver.isRolling = false;
      }
    }
  }
}

void startSolver(int diceType){
  solver.solverControl = true;
  int initUpdateCadence = 1;
  int initCounter = 0;
  animateThrow(diceType);
}

boolean getRolling(){
  return solver.isRolling;
}

void setRolling(boolean rolling){
  solver.isRolling = rolling;
}

boolean getControl(){
  return solver.solverControl;
}

void setControl(boolean control){
  solver.solverControl = control;
}

int getDiceValue(){
  return solver.diceValue;
}