
Adder adder;

void initAdder(){
  adder.total = 0;
  adder.offsetX = 0;
  adder.index = 0;
  adder.text = "";
  adder.resetProgress = 0;
}

void moveAdder(int delta){
  adder.offsetX += delta;
}

void showAdder(){
  gb.display.cursorX = 0 + adder.offsetX;
  gb.display.cursorY = 43;
  gb.display.print(adder.text);

  gb.display.cursorX = 73;
  gb.display.cursorY = 30;
  if(adder.index < 8){
    gb.display.print(String(adder.index) + ":");
  }else{
    gb.display.print("!:");
  }

  gb.display.cursorX = 73;
  gb.display.cursorY = 36;
  gb.display.print(adder.total);

  gb.display.drawFastHLine(0, 41, 84);
  gb.display.drawRect(71, 28, 14, 14);

  if(gb.buttons.repeat(BTN_B, resetTime / 20)){
    adder.resetProgress += LCDWIDTH / 25;
  }
  if(gb.buttons.released(BTN_B)){
    adder.resetProgress = 0;
  }
  gb.display.drawFastHLine(0, 42, adder.resetProgress);
}

void addValue(int value, int diceType){
  if(adder.index < 8){
    adder.text = String(value) + "/" + "d" + String(diceValues[diceType]) + " " + adder.text;
    adder.total += value;
    adder.index++;
  }
}