
Arrow chooser;

void initChooser(){
  chooser.current = 1;
  chooser.max = 6;
  chooser.x = 15;
  chooser.right = true;

}

//Animates the arrow and goes up/down
void updateChooser(){
  if(chooser.right && gb.frameCount % 2 == 0){
    chooser.x ++;
  }else if(!chooser.right && gb.frameCount % 2 == 0){
    chooser.x --;
  }
  if(chooser.right && chooser.x > 16){
    chooser.right = false;
  }else if (!chooser.right && chooser.x < 14){
    chooser.right = true;
  }

  if(gb.buttons.repeat(BTN_DOWN, 4)){
    chooser.current ++;
    if(chooser.current > chooser.max){
      chooser.current = 0;
    }
  }
  if(gb.buttons.repeat(BTN_UP, 4)){
    if(chooser.current == 0){
      chooser.current = chooser.max;
    }else{
      chooser.current --;
    }
  }
}

//draws the arrow bitmap to the screen
void drawChooser(){
  byte y = chooser.current * 6;
  gb.display.drawBitmap(chooser.x,y,arrow,NOROT,NOFLIP);
  

}

//draws the different dice denominations to the screen
void drawMenu(){  
  for (int i = 0; i <= chooser.max; i++) {
      gb.display.cursorX = 0;  // Set the position for each value
      gb.display.cursorY = i * 6;
      gb.display.print(diceValues[i]);  // Print dice value
  }
}

//draws the current selection as a bigger number inside the dice to the screen
void showSelection(){
  gb.display.cursorX = 50;
  gb.display.cursorY = 10;
  gb.display.fontSize = 2;
  gb.display.print(diceValues[chooser.current]);
  gb.display.fontSize = 1;
  setDice(getChooserSelection());

}

//returns what the arrow is currently pointing to
int getChooserSelection(){
  return chooser.current;
}