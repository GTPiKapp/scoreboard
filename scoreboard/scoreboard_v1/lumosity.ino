void setLumosity(int lum)
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

