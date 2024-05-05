
DiceDisplay display;

void initDisplay(){
  display.currentDice = 1;
}

void showDisplay(){
 if(display.currentDice == 0){
  gb.display.drawTriangle(43, 10, 54, 30, 32, 30);
 } 
}

void setDice(int DiceType){
  display.currentDice = DiceType;
}