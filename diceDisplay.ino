
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
    gb.display.drawTriangle(48, 2, 60, 21, 36, 21);
    break;
  case 1:
    gb.display.drawRoundRect(38, 5, 20, 20, 3);
    gb.display.drawLine(39, 6, 44, 1);
    gb.display.drawLine(57, 6, 62, 1);
    gb.display.drawLine(57, 22, 62, 17);
    gb.display.drawLine(44, 1, 62, 1);
    gb.display.drawLine(62, 17, 62, 1);
    break;
  case 2:
    gb.display.drawTriangle(48, 2, 60, 21, 36, 21);
    gb.display.drawTriangle(48, 30, 60, 21, 36, 21);
    // side faces
    gb.display.drawTriangle(48, 2, 60, 21, 60, 10);
    gb.display.drawTriangle(48, 2, 36, 10, 36, 21);
    break;
  case 3:
    // number face
    gb.display.drawLine(51, 2, 66, 19);
    gb.display.drawLine(51, 2, 36, 19);
    gb.display.drawLine(36, 19, 51, 25);
    gb.display.drawLine(66, 19, 51, 25);
    // number adjacent right
    gb.display.drawLine(66, 19, 73, 23);
    gb.display.drawLine(73, 15, 73, 23);
    gb.display.drawLine(73, 15, 51, 2);
    // number adjacent left
    gb.display.drawLine(29, 23, 29, 15);
    gb.display.drawLine(29, 15, 51, 2);
    // bottom faces
    gb.display.drawLine(51, 25, 51, 37);
    gb.display.drawLine(73, 23, 51, 37);
    gb.display.drawLine(29, 23, 51, 37);
    gb.display.drawLine(29, 23, 36, 19);
    break;
  case 4:
    // number face
    gb.display.drawLine(43, 8, 59, 8);
    gb.display.drawLine(43, 8, 37, 16);
    gb.display.drawLine(37, 16, 51, 26);
    gb.display.drawLine(59, 8, 65, 16);
    gb.display.drawLine(65, 16, 51, 26);
    // 2 downward faces
    gb.display.drawLine(51, 26, 51, 30);
    gb.display.drawLine(38, 28, 51, 30);
    gb.display.drawLine(38, 28, 32, 18);
    gb.display.drawLine(37, 16, 32, 18);

    gb.display.drawLine(64, 28, 51, 30);
    gb.display.drawLine(64, 28, 70, 18);
    gb.display.drawLine(65, 16, 70, 18);
    // right face
    gb.display.drawLine(70, 18, 70, 10);
    gb.display.drawLine(70, 10, 64, 4);
    gb.display.drawLine(59, 8, 64, 4);

    // left face
    gb.display.drawLine(32, 18, 32, 10);
    gb.display.drawLine(32, 10, 38, 4);
    gb.display.drawLine(43, 8, 38, 4);

    // top face
    gb.display.drawLine(51, 0, 64, 4);
    gb.display.drawLine(51, 0, 38, 4);

    break;
  case 5:
    // number side
    gb.display.drawTriangle(37, 9, 65, 9, 51, 27);
    // top middle
    gb.display.drawTriangle(37, 9, 65, 9, 51, 0);
    // left side
    gb.display.drawTriangle(37, 9, 51, 27, 33, 27);
    gb.display.drawTriangle(37, 9, 33, 9, 33, 27);
    // top left
    gb.display.drawTriangle(37, 9, 33, 9, 51, 0);
    // right side
    gb.display.drawTriangle(69, 27, 65, 9, 51, 27);
    gb.display.drawTriangle(69, 27, 65, 9, 69, 9);
    // top right
    gb.display.drawTriangle(51, 0, 65, 9, 69, 9);
    // bottom
    gb.display.drawTriangle(51, 36, 51, 27, 33, 27);
    gb.display.drawTriangle(69, 27, 51, 36, 51, 27);
    break;
  case 6:
    gb.display.drawCircle(55, 15, 15);
    break;
  default:
    gb.display.drawTriangle(48, 2, 59, 21, 37, 21);
  }
}

//sets the currently displayed dice type 
void setDice(int DiceType){
  display.currentDice = DiceType;
}