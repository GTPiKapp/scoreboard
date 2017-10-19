void drawScore()
{
  double frac, intpart, temp;
  setCurs(0);
  // example: homeScore = 13
  frac = modf(homeScore / 10.0, &intpart); // frac = 0.3, intpart = 1
  drawDigit(intpart);
  setCurs(1);
  temp = frac * 10 + 0.5; // int conversion sees a floating 3.00 as 2.993882288... so we add arbitrary 0.5 to ensure it's above truncation point
  frac = modf(temp, &intpart); // frac = 0.0, intpart = 3
  drawDigit(intpart);

  setCurs(7);
  frac = modf(awayScore / 10.0, &intpart);
  drawDigit(intpart);
  setCurs(8);
  temp = frac * 10 + 0.5;
  frac = modf(temp, &intpart);
  drawDigit(intpart);
}

void drawTeams()
{
  // H
  matrix.drawLine(0, 4, 0, 10, color);
  matrix.drawLine(0, 7, 4, 7, color);
  matrix.drawLine(4, 4, 4, 10, color);
  // o
  matrix.drawCircle(8, 8, 2, color);
  // m
  matrix.drawLine(12, 6, 12, 10, color);
  matrix.drawPixel(13, 6, color);
  matrix.drawLine(14, 7, 14, 10, color);
  matrix.drawPixel(15, 6, color);
  matrix.drawLine(16, 7, 16, 10, color);
  // e
  matrix.drawLine(18, 7, 18, 9, color);
  matrix.drawLine(19, 10, 20, 10, color);
  matrix.drawLine(19, 6, 20, 6, color);
  matrix.drawLine(21, 7, 21, 8, color);
  matrix.drawLine(20, 8, 19, 8, color);
  
  // A
  int s = 42;

  matrix.drawLine(s, 6, s, 10, color);
  matrix.drawLine(s,6,s+2, 4, color);
  matrix.drawLine(s+2,4,s+4, 6, color);
  matrix.drawLine(s,8,s+4, 8, color);
  matrix.drawLine(s+4,6,s+4, 10, color);
  // w
  matrix.drawLine(s+6,6,s+6, 9, color);
  matrix.drawLine(s+7,10,s+8, 9, color);
  matrix.drawLine(s+9,10,s+10, 9, color);
  matrix.drawLine(s+10,9,s+10, 6, color);
  matrix.drawPixel(s+8, 8, color);
  // a
  matrix.drawLine(s+13,10,s+16, 10, color);
  matrix.drawLine(s+15,10,s+15, 7, color);
  matrix.drawLine(s+13,8,s+15, 8, color);
  matrix.drawPixel(s+12, 9, color);
  matrix.drawLine(s+13,6,s+14, 6, color);
  // y
  matrix.drawLine(s+17,6,s+17, 8, color);
  matrix.drawLine(s+18,9,s+21, 9, color);
  matrix.drawLine(s+21,6,s+21, 12, color);
  matrix.drawLine(s+20,13,s+18, 13, color);
  matrix.drawPixel(s+17, 12, color);
}

void drawTemp()
{
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  if (temperature >= 60)
  {
    color = yellow;
  }
  else
  {
    color = blue;
  }
  // display temp numbers
  double frac, intpart, temp;
  char str1;
  frac = modf(temperature / 10.0, &intpart);
  setCurs(2);
  drawDigit(intpart);

  
  temp = temperature - intpart*10;
  frac = modf(temp, &intpart);
  setCurs(3);
  drawDigit(intpart);
  
  matrix.drawPixel(40,2,color);
  matrix.drawPixel(39,1,color);
  matrix.drawPixel(39,3,color);
  matrix.drawPixel(38,2,color);
}
