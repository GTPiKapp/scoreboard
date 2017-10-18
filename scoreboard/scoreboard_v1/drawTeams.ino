void drawTeams()
{
  // H
  matrix.drawLine(0,4,0,10,col);
  matrix.drawLine(0,7,4,7,col);
  matrix.drawLine(4,4,4,10,col);
  // o
  matrix.drawCircle(8,8,2,col);
  // m
  matrix.drawLine(12,6,12,10,col);
  matrix.drawPixel(13,6,col);
  matrix.drawLine(14,7,14,10,col);
  matrix.drawPixel(15,6,col);
  matrix.drawLine(16,7,16,10,col);
  // e
  matrix.drawLine(18,7,18,9,col);
  matrix.drawLine(19,10,20,10,col);
  matrix.drawLine(19,6,20,6,col);
  matrix.drawLine(21,7,21,8,col);
  matrix.drawLine(20,8,19,8,col);
  
  // A
  int s = 42;
  matrix.drawLine(s,6,s,10,col);
  matrix.drawLine(s,6,s+2,4,col);
  matrix.drawLine(s+2,4,s+4,6,col);
  matrix.drawLine(s,8,s+4,8,col);
  matrix.drawLine(s+4,6,s+4,10,col);
  // w
  matrix.drawLine(s+6,6,s+6,9,col);
  matrix.drawLine(s+7,10,s+8,9,col);
  matrix.drawLine(s+9,10,s+10,9,col);
  matrix.drawLine(s+10,9,s+10,6,col);
  matrix.drawPixel(s+8,8,col);
  // a
  matrix.drawLine(s+13,10,s+16,10,col);
  matrix.drawLine(s+15,10,s+15,7,col);
  matrix.drawLine(s+13,8,s+15,8,col);
  matrix.drawPixel(s+12,9,col);
  matrix.drawLine(s+13,6,s+14,6,col);
  // y
  matrix.drawLine(s+17,6,s+17,8,col);
  matrix.drawLine(s+18,9,s+21,9,col);
  matrix.drawLine(s+21,6,s+21,12,col);
  matrix.drawLine(s+20,13,s+18,13,col);
  matrix.drawPixel(s+17,12,col);
}
