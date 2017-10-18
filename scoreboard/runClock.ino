void runClock()
{
  while(count > 0) // while not out of time
  {
    // buzzer warnings
    if(count == 60) // 1 min warning -- beep twice-ish
    {
      tone(buzzPin,700,200);
      delay(400);
    }
    if(count<=30){red = yellow;}
    
    // 10 second shake
    currentMillis = millis();
    if(count <= 10)
    {
      if(currentMillis - shakeMillis > 100) // if 1 second has passed
      {
        shakeMillis = currentMillis; // save the current time
        r+=dir;
        rb+=dir;
        if(r > 2)
        {
          r-=2;
          dir=-dir;
          rb-=2;
        }
        if(r < 1)
        {
          r+=2;
          rb+=2;
          dir = -dir;
        }
        print_time(count);
      }
    }
    
    //start 1-second timer
    if(currentMillis - previousMillis > interval) // if 1 second has passed
    {
      previousMillis = currentMillis; // save the current time
      count--; //decrement count time by 1
      getTemp();
      print_time(count);
      Serial.print("Current count: ");
      Serial.println(count);
      
      if(count <=3){tone(buzzPin,700,30);}
    }
    
    //button check
    pauseState = digitalRead(startstopPin);
    if(pauseState == HIGH)
    {
      tone(buzzPin,700,30);
      // debounce
      while(pauseState == HIGH)
      {
        pauseState = digitalRead(startstopPin);
      }
      delay(200);
      // go to pause time state
      pauseTime();
    }
    scoreButtons(count);
  }
  tone(buzzPin,350,1700);  // end beep notice
  resetState = digitalRead(RESET_PIN);
  while(resetState == LOW) // let 0:00 sit untill button press
  {
    resetState = digitalRead(RESET_PIN);

    // timeout check (turn screen off after 3 min)
    currentMillis = millis();
    if(currentMillis - previousMillis > 180000) {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
    }
    else {
      // want to ensure that scorebuttons can't affect timeout of display - only reset button can
      scoreButtons(count);
    }
  }
  // no need for debounce, not returning to loop immediately
  // splashScreen();
}
