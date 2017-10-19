void drawDigit(int x)
{
  switch(x)
  {
    case 1:
      drawOne();
      break;
    case 2:
      drawTwo();
      break;
    case 3:
      drawThree();
      break;
    case 4:
      drawFour();
      break;
    case 5:
      drawFive();
      break;
    case 6:
      drawSix();
      break;
    case 7:
      drawSeven();
      break;
    case 8:
      drawEight();
      break;
    case 9:
      drawNine();
      break;
    default:
      drawZero();
      break;
  }
}

void drawZero()
{
  // top left down
  matrix.drawLine(c,r+1,c,rb- 1, color); 
  // top right down
  matrix.drawLine(cp,r+1,cp,rb- 1, color);
  // top left to top right
  matrix.drawLine(c+1,r,cp-1, r, color);
  // bottom left to bottom right
  matrix.drawLine(c+1,rb,cp-1, rb, color);
}

void drawOne()
{
  if(cp == c + 4)
  {
    cp = c + 2;
  }
  else
  {
    cp = c + 4;
  }
  matrix.drawLine(cp,r,cp, rb, color);
}

void drawTwo()
{
  int rp = r+(rb-r)/2; // middle row
  // top left to top right
  matrix.drawLine(c,r,cp-1, r, color);
  // top right down
  matrix.drawLine(cp,r+1,cp,rp- 1, color);
  // middle right to middle left
  matrix.drawLine(c+1,rp,cp-1, rp, color);
  // middle left down
  matrix.drawLine(c,rp+1,c,rb- 1, color);
  // bottom left to bottom right
  matrix.drawLine(c+1,rb,cp, rb, color);
}

void drawThree()
{
  int rp = r+(rb-r)/2;
  // top left to top right
  matrix.drawPixel(c, r+1, color);
  matrix.drawLine(c+1,r,cp-1, r, color); 
  // top right down
  matrix.drawLine(cp,r+1,cp,rp- 1, color);
  matrix.drawLine(cp,rp+1,cp,rb- 1, color);
  // middle right to middle left
  matrix.drawLine(c+1,rp,cp-1, rp, color);
  // bottom left to bottom right
  matrix.drawPixel(c, rb-1, color);
  matrix.drawLine(c+1,rb,cp-1, rb, color);
}

void drawFour()
{
  int rp = r+(rb-r)/2; // middle row
  // top right down
  matrix.drawLine(cp,r,cp, rb, color);
  // middle right to middle left
  matrix.drawLine(c,rp,cp, rp, color);
  // top left down
  matrix.drawLine(c,r,c, rp, color);
}

void drawFive()
{
  int rp = r+(rb-r)/2; // middle row
  // top left to top right
  matrix.drawLine(c,r,cp, r, color);
  // top left down
  matrix.drawLine(c,r,c, rp, color);
  // middle right to middle left
  matrix.drawLine(c,rp,cp-1, rp, color);
  // middle right down
  matrix.drawLine(cp,rp+1,cp,rb- 1, color);
  // bottom left to bottom right
  matrix.drawLine(c,rb,cp-1, rb, color);
}

void drawSix()
{
  int rp = r+(rb-r)/2; // middle row
  // top left down
  matrix.drawLine(c,r+1,c,rb- 1, color);
  // middle right to middle left
  matrix.drawLine(c,rp,cp-1, rp, color);
  // middle right down
  matrix.drawLine(cp,rp+1,cp,rb- 1, color);
  // bottom left to bottom right
  matrix.drawLine(c+1,rb,cp-1, rb, color);
  // top left to top right
  matrix.drawLine(c+1,r,cp-1, r, color);
  matrix.drawPixel(cp,r+1, color);
}

void drawSeven()
{
  int seven_col; // local column variable for changing width of seven depending on digit size
  // top left to top right
  matrix.drawLine(c,r,cp, r, color);
  // top right to bottom left
  if(cp == c + 7)
  {
    seven_col = c + 2;
  }
  else
  {
    seven_col = c + 1;
  }
  matrix.drawLine(cp,r,seven_col, rb, color);
}

void drawEight()
{
  int rp = r+(rb-r)/2;
  // top left down
  matrix.drawLine(c,r+1,c,rb-1, color); 
  // top right down
  matrix.drawLine(cp,r+1,cp,rb- 1, color);
  // top left to top right
  matrix.drawLine(c+1,r,cp-1, r, color);
  // bottom left to bottom right
  matrix.drawLine(c+1,rb,cp-1, rb, color);
  // middle line
  matrix.drawLine(c+1,rp,cp-1, rp, color);
}

void drawNine()
{
  int rp = r+(rb-r)/2; // middle row
  // top right down
  matrix.drawLine(cp,r+1,cp, rb, color);
  // top left down to middle
  matrix.drawLine(c,r+1,c,rp- 1, color);
  // middle line
  matrix.drawLine(c+1,rp,cp-1, rp, color);
  // top line
  matrix.drawLine(c+1,r,cp-1, r, color);
}

