void pauseTime()
{
  Serial.println("Time paused");
  startState = digitalRead(startstopPin);
  tempMillis = millis();
  while(startState == LOW) // wait for start button
  {
    startState = digitalRead(startstopPin);
    resetState = digitalRead(resetPin); // check reset while waiting for start button
    
    // check score
    scoreButtons(count);
    
    // check reset button
    if(resetState == HIGH)
    {
      tone(buzzPin,700,30);
      delay(200);
      while(resetState == HIGH)
      {
        resetState = digitalRead(resetPin);
      }
      splashScreen();
    }
    
    // timeout check (turn screen off after 3 min)
    currentMillis = millis();
    if(currentMillis - tempMillis > 180000) {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
      while(resetState == LOW)
      {
        resetState = digitalRead(resetPin);
      }
      tempMillis = millis();
      tone(buzzPin,700,30);
      printTime(count);
      delay(200);
    }
  }
  tone(buzzPin,700,30);
  while(startState == HIGH)
  {
    startState = digitalRead(startstopPin);
  }
  delay(200);
}
