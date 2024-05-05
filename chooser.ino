
Arrow chooser;

void initChooser(){
  chooser.current = 1;
  chooser.max = 6;
  chooser.x = 15;
  chooser.right = true;

}

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

  if(gb.buttons.released(BTN_DOWN)){
    chooser.current ++;
    if(chooser.current > chooser.max){
      chooser.current = 0;
    }
  }
  if(gb.buttons.released(BTN_UP)){
    if(chooser.current == 0){
      chooser.current = chooser.max;
    }else{
      chooser.current --;
    }
  }
}

void drawChooser(){
  byte y = chooser.current * 6;
  gb.display.drawBitmap(chooser.x,y,arrow,NOROT,NOFLIP);

}

void drawMenu(){  
  for (int i = 0; i <= chooser.max; i++) {
      gb.display.cursorX = 0;  // Set the position for each value
      gb.display.cursorY = i * 6;
      gb.display.print(diceValues[i]);  // Print dice value
  }
}

void showSelection(){
  gb.display.cursorX = 40;
  gb.display.cursorY = 18;
  gb.display.fontSize = 2;
  gb.display.print(diceValues[chooser.current]);
  gb.display.fontSize = 1;
}

int getChooserSelection(){
  return chooser.current;
}
