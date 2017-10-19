void getTemp()
{
  int val = analogRead(5);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  float fahrenheit = (cel*9)/5 + 32;
  newTemp = 0.1*fahrenheit + 0.9*oldTemp;
  oldTemp = newTemp;
  temperature = newTemp - 4;
}

void drawTemp()
{
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  if(temperature >= 60)
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
  Serial.println(temp);
  Serial.println(intpart);
  
  matrix.drawPixel(40,2,color);
  matrix.drawPixel(39,1,color);
  matrix.drawPixel(39,3,color);
  matrix.drawPixel(38,2,color);
}
