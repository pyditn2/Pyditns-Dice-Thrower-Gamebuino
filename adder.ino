
Adder adder;

void initAdder(){
  adder.total = 0;
  adder.offsetX = 0;
  
}

void moveAdder(int delta){
  adder.offsetX += delta;
}

void showAdder(){
  gb.display.cursorX = 0 + adder.offsetX;
  gb.display.cursorY = 42;
  gb.display.print("Adder working");
}
