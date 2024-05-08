
Adder adder;

void initAdder(){
  adder.total = 0;
  adder.offsetX = 0;
  adder.diceType[6];
  adder.values[6];
  adder.index = 0;
}

void moveAdder(int delta){
  adder.offsetX += delta;
}

void showAdder(){
  gb.display.cursorX = 0 + adder.offsetX;
  gb.display.cursorY = 42;

  gb.display.cursorX = 73;
  gb.display.cursorY = 37;
  gb.display.print("T:");

  gb.display.cursorX = 73;
  gb.display.cursorY = 43;
  gb.display.print(adder.total);
}

void addValue(int value, int diceType){
  adder.values[adder.index] = value;
  adder.diceType[adder.index] = diceType;
  adder.total += value;
  adder.index++;
}
