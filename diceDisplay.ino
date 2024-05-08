
DiceDisplay display;

void initDisplay(){
  display.currentDice = 1;
}

//draws the dice image to the screen
void showDisplay(){
 //if(display.currentDice == 0){
 // gb.display.drawTriangle(53, 2, 64, 21, 42, 21);
 //} 
 switch (display.currentDice){
  case 0:
    gb.display.drawTriangle(53, 2, 65, 21, 41, 21);
    break;
  case 1:
    gb.display.drawRoundRect(43, 5, 20, 20, 3);
    gb.display.drawLine(44, 6, 49, 1);
    gb.display.drawLine(62, 6, 67, 1);
    gb.display.drawLine(62, 22, 67, 17);
    gb.display.drawLine(49, 1, 67, 1);
    gb.display.drawLine(67, 17, 67, 1);
    break;
  case 2:
    gb.display.drawTriangle(53, 2, 65, 21, 41, 21);
    gb.display.drawTriangle(53, 30, 65, 21, 41, 21);
    //side faces
    gb.display.drawTriangle(53, 2, 65, 21, 65, 10);
    gb.display.drawTriangle(53, 2, 41, 10, 41, 21);
    break;
  case 3:
    //number face
    gb.display.drawLine(56, 2, 71, 19);
    gb.display.drawLine(56, 2, 41, 19);
    gb.display.drawLine(41, 19, 56, 25);
    gb.display.drawLine(71, 19, 56, 25);
    //number adjacent right
    //gb.display.drawTriangle(56, 2, 71, 19, 78, 23);
    //gb.display.drawTriangle(56, 2, 41, 19, 34, 23);
    gb.display.drawLine(71, 19, 78, 23);
    gb.display.drawLine(78, 15, 78, 23);
    gb.display.drawLine(78, 15, 56, 2);
    //number adjacent left
    gb.display.drawLine(34, 23, 34, 15);
    gb.display.drawLine(34, 15, 56, 2);
    //bottom faces
    gb.display.drawLine(56, 25, 56, 37);
    gb.display.drawLine(78, 23, 56, 37);
    gb.display.drawLine(34, 23, 56, 37);
    gb.display.drawLine(34, 23, 41, 19);
    break;
  case 4:
    gb.display.drawRect(48, 6, 16, 2);
    gb.display.drawLine(48, 8, 41, 16);
    gb.display.drawLine(41, 16, 56, 26);
    gb.display.drawLine(64, 8, 71, 16);
    gb.display.drawLine(71, 16, 56, 26);
    gb.display.drawTriangle(48, 6, 41, 16, 42, 9);
    gb.display.drawTriangle(64, 6, 71, 16, 70, 9);
    gb.display.drawLine(56, 26, 56, 28);
    gb.display.drawLine(48, 28, 64, 28);
    gb.display.drawLine(48, 28, 41, 16);
    gb.display.drawLine(64, 28, 71, 16);
    break;
  case 5:
    //number side
    gb.display.drawTriangle(42, 9, 70, 9, 56, 27);
    //top middle
    gb.display.drawTriangle(42, 9, 70, 9, 56, 0);
    //left side
    gb.display.drawTriangle(42, 9, 56, 27, 38, 27);
    gb.display.drawTriangle(42, 9, 38, 9, 38, 27);
    //top left
    gb.display.drawTriangle(42, 9, 38, 9, 56, 0);
    //right side
    gb.display.drawTriangle(74, 27, 70, 9, 56, 27);
    gb.display.drawTriangle(74, 27, 70, 9, 74, 9);
    //top right
    gb.display.drawTriangle(56, 0, 70, 9, 74, 9);
    //bottom
    gb.display.drawTriangle(56, 36, 56, 27, 38, 27);
    gb.display.drawTriangle(74, 27, 56, 36, 56, 27);
    break;
  case 6:
    gb.display.drawCircle(60, 15, 15);
    break;
  default:
    gb.display.drawTriangle(53, 2, 64, 21, 42, 21);
 }
}

//sets the currently displayed dice type 
void setDice(int DiceType){
  display.currentDice = DiceType;
}