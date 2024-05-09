
Handler effect;

void initEffect(){
  effect.numParticles = 0;
  effect.originX = 0;
  effect.originY = 0;
  effect.delta = 0;
}

void spawnEffect(int originX, int originY){
  effect.originX = originX,
  effect.originY = originY;
  effect.delta = 5;
  showParticle = true;
}

void animateEffect(){
  if(gb.frameCount % 2 == 0){
    effect.delta += 1;
  }
}

void showEffect(){
  gb.display.drawBitmap(effect.originX + effect.delta, effect.originY + effect.delta, spark);
  gb.display.drawBitmap(effect.originX + effect.delta, effect.originY + (effect.delta * -1), spark);
  gb.display.drawBitmap(effect.originX + (effect.delta * -1), effect.originY + effect.delta, spark);
  gb.display.drawBitmap(effect.originX + (effect.delta * -1), effect.originY + (effect.delta * -1), spark);
}