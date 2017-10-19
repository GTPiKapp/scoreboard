void splashScreen()
{
  printHeader("splash screen");
  matrix.fillScreen(0);
  set_brightness(3);
  yellow = matrix.Color333(2,1,0);
  srand(millis());
  int r = rand() % 5;
  Serial.println(r);
  switch(r)
  {
    case 1:
      drawFlag();
      break;
    case 2: 
      drawPiKapp();
      break;
    case 3:
      fuckrUsty();
      break;
    case 4:
      drawThomas();
      break;
    default:
      drawCoors();
      break;
  }
  matrix.swapBuffers(false);
  delay(3000);
}

void fuckrUsty()
{
  matrix.setCursor(1,0);
  matrix.setTextSize(2);
  matrix.setTextColor(red);
  matrix.print("fuckrusty");
}

void drawCoors()
{
  
  // white background
  matrix.fillScreen(grey);
  // C in coors
  matrix.drawLine(9, 2, 9, 4, red);
  matrix.drawLine(10, 2, 10, 5, red);
  matrix.drawLine(10, 9, 10, 17, red);
  matrix.drawPixel(11, 2, red);
  matrix.drawLine(11, 5, 11, 18, red);
  matrix.drawLine(12, 5, 12, 19, red);
  matrix.drawLine(13, 4, 13, 10, red);
  matrix.drawLine(13, 16, 13, 19, red);
  matrix.drawLine(14, 3, 14, 7, red);
  matrix.drawLine(14, 17, 14, 19, red);
  matrix.drawLine(15, 2, 15, 6, red);
  matrix.drawLine(15, 17, 15, 19, red);
  matrix.drawLine(16, 2, 16, 3, red);
  matrix.drawPixel(16, 6, red);
  matrix.drawLine(16, 17, 16, 19, red);
  matrix.drawLine(17, 1, 17, 2, red);
  matrix.drawLine(17, 5, 17, 8, red);
  matrix.drawLine(17, 17, 17, 18, red);
  matrix.drawLine(19, 0, 21, 0, red);
  matrix.drawLine(17, 1, 22, 1, red);
  matrix.drawLine(18, 5, 18, 9, red);
  matrix.drawLine(18, 17, 18, 18, red);
  matrix.drawLine(19, 8, 20, 8, red);
  matrix.drawLine(19, 9, 20, 9, red);
  matrix.drawLine(19, 16, 19, 17, red);
  matrix.drawLine(20, 15, 20, 16, red);
  matrix.drawLine(21, 7, 21, 8, red);
  matrix.drawPixel(22, 2, red);
  matrix.drawLine(22, 5, 22, 7, red);
  matrix.drawLine(23, 2, 23, 5, red);
  // first o
  matrix.drawLine(21, 14, 21, 18, red);
  matrix.drawLine(22, 12, 22, 19, red);
  matrix.drawLine(23, 10, 23, 19, red);
  matrix.drawLine(24, 9, 24, 11, red);
  matrix.drawLine(24, 17, 24, 19, red);
  matrix.drawLine(25, 8, 28, 8, red);
  matrix.drawPixel(25, 9, red);
  matrix.drawLine(25, 17, 25, 19, red);
  matrix.drawLine(26, 17, 26, 18, red);
  matrix.drawLine(27, 16, 27, 17, red);
  matrix.drawLine(28, 8, 28, 11, red);
  matrix.drawLine(28, 14, 28, 15, red);
  matrix.drawLine(29, 9, 29, 13, red);
  matrix.drawLine(30, 11, 31, 11, red);
  // second o
  matrix.drawLine(31, 13, 31, 18, red);
  matrix.drawLine(32, 10, 32, 19, red);
  matrix.drawLine(33, 10, 33, 13, red);
  matrix.drawLine(33, 16, 33, 19, red);
  matrix.drawLine(34, 9, 34, 10, red);
  matrix.drawLine(34, 17, 34, 19, red);
  matrix.drawLine(35, 8, 35, 9, red);
  matrix.drawLine(35, 17, 35, 19, red);
  matrix.drawLine(36, 8, 38, 8, red);
  matrix.drawLine(36, 16, 36, 18, red);
  matrix.drawLine(37, 15, 37, 17, red);
  matrix.drawLine(38, 8, 38, 15, red);
  matrix.drawPixel(38, 12, white);
  matrix.drawLine(39, 9, 39, 13, red);
  // letter r
  matrix.drawLine(40, 10, 42, 8, red);
  matrix.drawLine(41, 15, 41, 19, red);
  matrix.drawLine(42, 13, 42, 19, red);
  matrix.drawLine(43, 6, 43, 8, red);
  matrix.drawLine(43, 11, 43, 19, red);
  matrix.drawLine(44, 8, 44, 13, red);
  matrix.drawLine(44, 17, 44, 19, red);
  matrix.drawLine(45, 9, 45, 11, red);
  matrix.drawLine(45, 17, 45, 18, red);
  // letter s
  matrix.drawLine(46, 17, 46, 18, red);
  matrix.drawLine(47, 15, 47, 16, red);
  matrix.drawPixel(48, 13, red);
  matrix.drawLine(48, 16, 48, 18, red);
  matrix.drawLine(49, 11, 49, 12, red);
  matrix.drawPixel(49, 15, red);
  matrix.drawLine(50, 9, 50, 10, red);
  matrix.drawLine(49, 17, 54, 17, red);
  matrix.drawLine(49, 18, 52, 18, red);
  matrix.drawLine(49, 19, 51, 19, red);
  matrix.drawLine(51, 16, 55, 16, red);
  matrix.drawPixel(51, 8, red);
  matrix.drawLine(52, 7, 52, 15, red);
  matrix.drawLine(53, 12, 53, 15, red);
  // L in light
  matrix.drawLine(18, 21, 18, 29, black);
  matrix.drawLine(19, 21, 19, 29, black);
  matrix.drawLine(20, 28, 22, 28, black);
  matrix.drawLine(20, 29, 21, 29, black);
  // letter I
  matrix.drawLine(24, 21, 24, 29, black);
  matrix.drawLine(25, 21, 25, 29, black);
  // letter G
  matrix.drawLine(27, 24, 27, 27, black);
  matrix.drawLine(28, 23, 28, 28, black);
  matrix.drawLine(29, 22, 29, 23, black);
  matrix.drawLine(29, 28, 29, 29, black);
  matrix.drawLine(29, 22, 33, 22, black);
  matrix.drawLine(29, 29, 32, 29, black);
  matrix.drawLine(29, 21, 32, 21, black);
  matrix.drawPixel(32, 23, black);
  matrix.drawPixel(31, 26, black);
  matrix.drawLine(32, 25, 32, 28, black);
  matrix.drawLine(33, 25, 33, 28, black);
  // letter H
  matrix.drawLine(35, 21, 35, 29, black);
  matrix.drawLine(36, 21, 36, 29, black);
  matrix.drawLine(37, 24, 39, 24, black);
  matrix.drawLine(37, 25, 39, 25, black);
  matrix.drawLine(40, 21, 40, 29, black);
  matrix.drawLine(41, 21, 41, 29, black);
  // letter T
  matrix.drawLine(43, 21, 47, 21, black);
  matrix.drawLine(43, 22, 46, 22, black);
  matrix.drawLine(44, 23, 44, 29, black);
  matrix.drawLine(45, 23, 45, 29, black);
}

void drawFlag()
{
  set_brightness(1);
  int k = 1;
  for(i=0;i<31;i+=4)
  {
    matrix.drawLine(0,i,63,i,white);
    matrix.drawLine(0,i+1,63,i+1,white);
  }
  for(i=2;i<32;i+=4)
  {
    matrix.drawLine(0,i,63,i,red);
    matrix.drawLine(0,i+1,63,i+1,red);
  }
  for(i=0;i<27;i++)
  {
    matrix.drawLine(i,0,i,16,blue);
  }
  set_brightness(3);
  for(i=1;i<26;i+=3)
  {
    if(k>0)
    {
      k=0;
    }
    else
    {
      k=1;
    }
    for(j=1;j<16-k;j+=2)
    {
      matrix.drawPixel(i,j+k,white);
    }
  }
}

void drawPenis()
{
  // Top half
  int color = red;
  matrix.drawLine(0,3,0,13,color);
  matrix.drawLine(8,4,25,4,color);
  matrix.drawLine(1,1,1,3,color);
  matrix.drawLine(2,0,2,1,color);
  matrix.drawLine(3,0,5,0,color);
  matrix.drawLine(6,0,6,1,color);
  matrix.drawLine(7,1,7,3,color);
  matrix.drawLine(8,3,8,4,color);
  matrix.drawLine(9,4,25,4,color);
  matrix.drawLine(26,3,28,3,color);
  matrix.drawLine(29,4,31,6,color);
  matrix.drawLine(31,7,31,9,color);
  
  // Bottom Half
  matrix.drawLine(1,13,1,14,color);
  matrix.drawLine(2,14,2,15,color);
  matrix.drawLine(3,15,6,15,color);
  matrix.drawLine(6,14,6,15,color);
  matrix.drawLine(7,12,7,14,color);
  matrix.drawLine(8,11,8,12,color);
  matrix.drawLine(9,11,25,11,color);
  matrix.drawLine(26,12,28,12,color);
  matrix.drawLine(29,11,30,10,color);
  
  //Middle
  matrix.drawLine(2,8,2,9,color);
  matrix.drawLine(3,7,5,7,color);
  matrix.drawLine(6,8,6,9,color);
  matrix.drawPixel(7,9,color);
  matrix.drawLine(9,8,24,8,color);
}

void drawPiKapp()
{
  int gold = matrix.Color333(2, 1, 0);
  // blue background
  matrix.fillScreen(blue);
  // white space
  matrix.fillRect(21, 0, 22, 32, white);
  // star
  matrix.drawLine(6, 5, 14, 5, gold);
  matrix.drawLine(10, 2, 10, 7, gold);
  matrix.drawLine(8, 6, 12, 6, gold);
  matrix.drawLine(8, 7, 12, 7, gold);
  matrix.drawLine(9, 4, 11, 4, gold);
  matrix.drawLine(8, 8, 12, 8, gold);
  matrix.drawPixel(10, 8, blue);
  matrix.drawLine(7, 9, 8, 9, gold);
  matrix.drawLine(12, 9, 13, 9, gold);
  // letters
  // pi
  matrix.drawLine(27, 2, 36, 2, blue);
  matrix.drawLine(28, 3, 28, 8, blue);
  matrix.drawLine(29, 3, 29, 8, blue);
  matrix.drawLine(34, 3, 34, 8, blue);
  matrix.drawLine(35, 3, 35, 8, blue);
  // kappa
  matrix.drawLine(28, 12, 28, 18, blue);
  matrix.drawLine(29, 12, 29, 18, blue);
  matrix.drawPixel(30, 15, blue);
  matrix.drawLine(31, 14, 32, 14, blue);
  matrix.drawLine(32, 13, 33, 13, blue);
  matrix.drawLine(34, 12, 35, 12, blue);
  matrix.drawLine(31, 16, 32, 16, blue);
  matrix.drawLine(32, 17, 33, 17, blue);
  matrix.drawLine(34, 18, 35, 18, blue);
  // phi
  matrix.drawLine(30, 21, 33, 21, blue);
  matrix.drawLine(31, 22, 31, 29, blue);
  matrix.drawLine(32, 22, 32, 29, blue);
  matrix.drawLine(30, 30, 33, 30, blue);
  matrix.drawLine(29, 28, 34, 28, blue);
  matrix.drawLine(29, 23, 34, 23, blue);
  matrix.drawLine(28, 24, 28, 27, blue);
  matrix.drawLine(35, 24, 35, 27, blue);
  matrix.drawLine(27, 25, 27, 26, blue);
  matrix.drawLine(36, 25, 36, 26, blue);
  // lamp
  matrix.drawLine(48, 29, 57, 29, gold);
  matrix.drawLine(50, 28, 55, 28, gold);
  matrix.drawLine(48, 27, 57, 27, gold);
  matrix.drawLine(47, 26, 59, 26, gold);
  matrix.drawLine(50, 25, 57, 25, gold);
  matrix.drawLine(51, 24, 55, 24, gold);
  matrix.drawLine(57, 24, 59, 24, gold);
  matrix.drawPixel(59, 25, gold);
  matrix.drawPixel(53, 23, gold);
  matrix.drawLine(46, 25, 48, 25, gold);
  matrix.drawLine(46, 24, 47, 24, gold);
}

void gtFlag()
{
  int black = matrix.Color333(0,0,0);
  matrix.fillScreen(white);
  int yellow = matrix.Color333(0,1,0);
  //T
  matrix.drawLine(26,10,49,10,black);
  matrix.drawLine(26,10,26,17,black);
  matrix.drawLine(49,10,49,17,black);
  matrix.drawLine(26,17,28,17,black);
  matrix.drawLine(47,17,49,17,black);
  matrix.drawLine(34,15,36,15,black);
  matrix.drawLine(41,15,45,15,black);
  matrix.drawLine(36,15,36,27,black);
  matrix.drawLine(41,15,41,27,black);
  matrix.drawLine(36,27,34,27,black);
  matrix.drawLine(41,27,43,27,black);
  matrix.drawLine(34,27,34,31,black);
  matrix.drawLine(34,31,43,31,black);
  matrix.drawLine(43,27,43,31,black);
  matrix.drawPixel(29,16,black);
  matrix.drawPixel(30,15,black);
  matrix.drawPixel(46,16,black);
  //G
  matrix.drawLine(34,0,34,8,black);
  matrix.drawLine(34,0,30,0,black);
  matrix.drawLine(34,8,30,8,black);
  matrix.drawLine(30,0,30,3,black);
  matrix.drawLine(28,2,30,2,black);
  matrix.drawLine(27,1,25,1,black);
  matrix.drawLine(24,0,22,0,black);
  matrix.drawLine(21,1,20,1,black);
  matrix.drawPixel(19,2,black);
  matrix.drawLine(18,3,17,3,black);
  matrix.drawLine(17,4,16,4,black);
  matrix.drawPixel(15,5,black);
  matrix.drawPixel(14,6,black);
  matrix.drawLine(14,7,13,7,black);
  matrix.drawLine(13,8,12,8,black);
  matrix.drawLine(12,8,12,11,black);
  matrix.drawLine(11,11,11,16,black);
  matrix.drawLine(12,17,12,18,black);
  matrix.drawLine(13,18,13,19,black);
  matrix.drawLine(14,20,14,21,black);
  matrix.drawLine(14,22,15,22,black);
  matrix.drawPixel(16,23,black);
  matrix.drawLine(17,24,18,24,black);
  matrix.drawLine(19,25,20,25,black);
  matrix.drawLine(21,26,25,26,black);
  matrix.drawLine(26,25,28,25,black);
  matrix.drawLine(28,24,29,24,black);
  matrix.drawLine(30,25,34,25,black);
  matrix.drawLine(34,25,34,15,black);
  matrix.drawLine(34,15,36,15,black);
  matrix.drawLine(29,7,28,7,black);
  matrix.drawLine(28,6,26,6,black);
  matrix.drawLine(26,5,23,5,black);
  matrix.drawLine(22,6,21,6,black);
  matrix.drawLine(21,7,20,7,black);
  matrix.drawLine(19,8,18,8,black);
  matrix.drawPixel(18,9,black);
  matrix.drawLine(17,10,17,16,black);
  matrix.drawLine(18,17,18,19,black);
  matrix.drawLine(19,19,19,20,black);
  matrix.drawLine(20,21,21,21,black);
  matrix.drawLine(22,22,25,22,black);
  matrix.drawLine(25,21,27,21,black);
  matrix.drawLine(28,20,28,19,black);
  matrix.drawPixel(29,19,black);
  matrix.drawPixel(30,18,black);
  matrix.drawLine(31,17,31,16,black);
  matrix.fillRect(31,1,3,7,yellow);
  matrix.fillRect(27,11,22,4,yellow);
  matrix.fillRect(37,15,4,15,yellow);
  matrix.fillRect(35,28,7,3,yellow);
  matrix.drawLine(27,15,29,15,yellow);
  matrix.drawLine(27,16,28,16,yellow);
  matrix.drawLine(46,15,48,15,yellow);
  matrix.drawLine(47,16,48,16,yellow);
  matrix.drawPixel(31,15,yellow);
  matrix.fillRect(32,15,2,9,yellow);
  matrix.drawPixel(31,18,yellow);
  matrix.fillRect(30,19,2,5,yellow);
  matrix.drawLine(29,20,29,23,yellow);
  matrix.drawLine(28,21,28,23,yellow);
  matrix.fillRect(26,22,2,3,yellow);
  matrix.fillRect(21,23,5,3,yellow);
  matrix.drawPixel(21,22,yellow);
  matrix.drawLine(20,22,20,24,yellow);
  matrix.drawLine(19,21,19,24,yellow);
  matrix.drawLine(18,20,18,23,yellow);
  matrix.drawLine(17,17,17,23,yellow);
  matrix.drawLine(16,5,16,21,yellow);
  matrix.drawLine(15,6,15,21,yellow);
  matrix.drawLine(14,8,14,19,yellow);
  matrix.drawLine(13,9,13,17,yellow);
  matrix.drawLine(12,12,12,16,yellow);
  matrix.drawLine(17,5,17,9,yellow);
  matrix.drawLine(18,4,18,7,yellow);
  matrix.drawLine(19,3,19,7,yellow);
  matrix.drawLine(20,2,20,6,yellow);
  matrix.fillRect(21,2,6,3,yellow);
  matrix.drawLine(22,1,24,1,yellow);
  matrix.drawLine(20,5,22,5,yellow);
  matrix.drawPixel(27,5,yellow);
  matrix.drawLine(28,3,28,5,yellow);
  matrix.drawLine(29,3,29,6,yellow);
  matrix.drawLine(30,4,30,7,yellow);
  matrix.drawLine(48,11,48,16,yellow);
  matrix.drawLine(30,24,33,24,yellow);
  matrix.drawLine(27,2,27,5,yellow);
  matrix.drawLine(42,28,42,30,yellow);
  matrix.drawPixel(16,22,yellow);
}

void drawThomas()
{
  //colors
  //red,orange,yellow,green,blue,purple 
  //black,white,grey,brown,peach,wood,lips
  set_brightness(7);
  int peach = matrix.Color444(7,4,1);
  int brown = matrix.Color444(0,0,0);
  int wood = matrix.Color444(3,1,0);
  int lips = matrix.Color444(3,0,2);
  int orange = matrix.Color444(5,1,0);
  int purple = matrix.Color444(2,0,3);
  int yellow = matrix.Color444(3,3,0);
  int black = matrix.Color444(0, 0, 0);
  int grey = matrix.Color444(1, 1, 1);
  matrix.fillScreen(peach);
  //flag
  //red
  matrix.fillRect(0,0,19,5,red);
  matrix.drawLine(19,0,19,3,red);
  matrix.drawLine(20,0,20,2,red);
  matrix.drawLine(21,0,21,3,red);
  matrix.drawLine(22,0,22,2,red);
  matrix.drawLine(23,0,23,1,red);
  matrix.drawLine(24,0,25,0,red);
  matrix.drawPixel(36,0,red);
  matrix.drawLine(37,0,37,1,red);
  matrix.fillRect(38,0,3,3,red);
  matrix.drawLine(41,0,41,1,red);
  matrix.drawLine(42,0,42,2,red);
  matrix.drawLine(43,0,43,3,red);
  matrix.fillRect(44,0,20,5,red);
  //orange
  matrix.fillRect(0,5,19,6,orange);
  matrix.drawLine(19,8,19,10,orange);
  matrix.fillRect(20,9,2,2,orange);
  matrix.drawLine(42,9,42,10,orange);
  matrix.drawLine(43,6,43,10,orange);
  matrix.fillRect(44,5,20,6,orange);
  //yellow
  matrix.fillRect(0,11,22,5,yellow);
  matrix.fillRect(42,11,22,5,yellow);
  //green
  matrix.fillRect(0,16,22,5,green);
  matrix.drawLine(22,17,22,20,green);
  matrix.drawLine(41,19,41,20,green);
  matrix.fillRect(42,16,22,5,green);
  //blue
  matrix.fillRect(0,21,22,6,blue);
  matrix.drawLine(22,21,23,21,blue);
  matrix.drawLine(22,23,22,26,blue);
  matrix.drawLine(23,24,23,26,blue);
  matrix.drawLine(24,25,24,26,blue);
  matrix.drawLine(39,22,40,22,blue);
  matrix.drawLine(40,21,41,21,blue);
  matrix.drawLine(40,25,40,26,blue);
  matrix.drawLine(41,23,41,26,blue);
  matrix.fillRect(42,21,22,6,blue);
  //purple
  matrix.fillRect(0,27,26,5,purple);
  matrix.drawLine(26,29,26,31,purple);
  matrix.drawPixel(40,27,purple);
  matrix.drawLine(41,27,41,29,purple);
  matrix.drawLine(42,27,42,30,purple);
  matrix.fillRect(43,27,21,5,purple);
  //hair
  matrix.drawLine(19,4,19,7,brown);
  matrix.drawLine(20,3,20,8,brown);
  matrix.drawLine(21,4,22,8,brown);
  matrix.drawLine(22,3,22,11,brown);
  matrix.drawLine(23,2,23,13,brown);
  matrix.drawLine(24,1,24,10,brown);
  matrix.drawLine(25,1,25,10,brown);
  matrix.drawLine(26,0,26,7,brown);
  matrix.drawLine(27,0,27,5,brown);
  matrix.drawLine(28,0,28,4,brown);
  matrix.drawLine(29,0,29,3,brown);
  matrix.drawLine(30,0,30,5,brown);
  matrix.drawLine(31,0,31,7,brown);
  matrix.drawLine(32,0,32,8,brown);
  matrix.drawLine(33,0,33,8,brown);
  matrix.drawLine(34,0,34,7,brown);
  matrix.drawLine(35,0,35,6,brown);
  matrix.drawLine(36,1,36,6,brown);
  matrix.drawLine(37,2,37,10,brown);
  matrix.drawLine(38,3,38,10,brown);
  matrix.drawLine(39,3,39,13,brown);
  matrix.drawLine(40,3,40,18,brown);
  matrix.drawLine(22,15,22,16,brown);
  matrix.drawLine(38,18,38,20,brown);
  matrix.drawLine(41,2,41,18,brown);
  matrix.drawLine(42,3,42,8,brown);
  matrix.drawLine(43,4,43,5,brown);
  matrix.fillRect(38,23,2,3,brown);
  matrix.drawLine(40,23,40,24,brown);
  matrix.drawPixel(41,22,brown);
  matrix.drawLine(21,8,21,7,brown);
  matrix.drawLine(39,16,39,19,brown); 
  //moustache
  matrix.drawLine(22,22,23,22,brown);
  matrix.drawLine(23,23,29,23,brown);
  matrix.drawLine(24,24,27,24,brown);
  matrix.drawLine(27,22,29,22,brown);
  matrix.drawLine(32,22,33,22,brown);
  matrix.drawLine(31,23,36,23,brown);
  matrix.drawLine(32,24,35,24,brown);
  matrix.drawPixel(37,22,brown);
  
  //mouth
  matrix.drawLine(28,24,31,24,lips);
  
  //glasses
  matrix.drawLine(22,12,22,14,wood);
  matrix.drawLine(23,14,23,17,wood);
  matrix.drawLine(24,14,24,15,wood);
  matrix.drawLine(24,18,24,19,wood);
  matrix.drawLine(25,13,36,13,wood);
  matrix.drawLine(27,12,28,12,wood);
  matrix.drawLine(33,12,35,12,wood);
  matrix.fillRect(29,14,3,3,wood);
  matrix.drawLine(25,20,27,20,wood);
  matrix.drawPixel(28,19,wood);
  matrix.drawLine(29,17,29,18,wood);
  matrix.drawLine(31,17,31,18,wood);
  matrix.drawLine(32,18,32,19,wood);
  matrix.drawLine(33,19,33,20,wood);
  matrix.drawLine(33,20,35,20,wood);
  matrix.drawLine(36,18,36,19,wood);
  matrix.drawLine(37,15,37,18,wood);
  matrix.drawPixel(36,14,wood);
  matrix.drawLine(38,15,38,16,wood);
  matrix.drawLine(39,14,39,15,wood);
  
  //eyes
  //left
  matrix.fillRect(25,14,4,5,white);
  matrix.drawLine(24,16,24,17,white);
  matrix.drawLine(25,19,27,19,white);
  //right
  matrix.fillRect(32,14,4,4,white);
  matrix.drawLine(33,18,35,18,white);
  matrix.drawLine(34,19,35,19,white);
  matrix.drawLine(36,15,36,17,white);
  //pupils
  matrix.drawLine(26,16,26,17, black);
  matrix.drawLine(34,16,34,17, black);
  
  
  //neck
  matrix.drawPixel(25,26,wood);
  matrix.drawPixel(26,28,wood);
  matrix.drawPixel(27,29,wood);
  matrix.drawLine(28,30,29,30,wood);
  matrix.drawLine(29,31,35,31,wood);
  matrix.drawLine(31,30,35,30,wood);
  matrix.drawLine(34,29,36,29,wood);
  matrix.drawLine(35,28,37,28,wood);
  matrix.drawLine(36,27,37,27,wood);
  matrix.drawPixel(37,26,wood);
  
  //shirt
  matrix.drawLine(36,30,36,31,grey);
  matrix.drawLine(37,29,37,31,grey);
  matrix.drawLine(38,26,38,31,grey);
  matrix.drawPixel(39,30,grey);
  
  //jacket
  matrix.drawLine(39,26,39,29,black);
  matrix.drawLine(40,28,40,31,black);
  matrix.drawLine(41,30,41,31,black);
  matrix.drawPixel(42,31,black);
  matrix.drawPixel(39,31,black);
  
  //nose
  matrix.drawLine(30,17,30,18,black);
  matrix.drawLine(29,19,29,21,black);
  matrix.drawLine(30,22,31,22,black);
  matrix.drawPixel(28,21,black);
  matrix.drawPixel(32,21,black);
}

void print_screen()
{
  double frac, int1, int2, int3, temp;

  // Clear Screen
  matrix.fillScreen(0);
  color = white;
  drawTeams();
  drawScore();
  drawTemp();
  color = red;
  
  // Minutes digit                    ex: num = 345
  temp = (double) time / 60; //                   temp=5.75
  frac = modf(temp, &int1); //     frac=.75, intpart=5
  
  // Tens digit
  temp = (time - 60 * int1)/10; //    temp= 4.5
  frac = modf(temp, &int2); //     frac=.5, intpart=4
  
  // Seconds digit
  temp = frac * 10; //                  temp=5
  int3 = temp + 0.5; // int conversion inside drawDigit sees a floating 5.00 as 4.993882288134081 or whatever, for some reason. Add arbitrary 0.5 to ensure it's above truncation point

  setCurs(4);
  drawDigit(int1);
  // colon 
  matrix.drawPixel(c + 9, r + 3, color);
  matrix.drawPixel(c + 9, r + 4, color);
  matrix.drawPixel(c + 9, r + 8, color);
  matrix.drawPixel(c + 9, r + 9, color);
  setCurs(5);
  drawDigit(int2);
  setCurs(6);
  drawDigit(int3);
  
  matrix.swapBuffers(false);
}

void set_brightness(int lum)
{
//  int photocellReading = analogRead(A5);
//  photocellReading = 1023 - photocellReading;
//  if(lum == 0)
//  {
//    lum = map(photocellReading, 0, 1023, 0, 7);
//    lum = 7 - lum;
//    Serial.print("Brightness: ");
//    Serial.println(photocellReading);
//    Serial.println(lum);
//  }
  red = matrix.Color333(lum, 0, 0);
  blue = matrix.Color333(0,0,lum);
  white = matrix.Color333(lum,lum,lum);
  yellow = matrix.Color333(lum,lum,0);
  green = matrix.Color333(0, lum, 0);
  grey = matrix.Color333(1,1,1);
  black = matrix.Color333(0,0,0);
  
}


