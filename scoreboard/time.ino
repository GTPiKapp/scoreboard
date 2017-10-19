void reset_time()
{
  time = 300;
}

int increment_time()
{
  if(time >= 420)
  {
    time = 30;
  }
  else
  {
    time += 30;
  }
  return time;
}

void select_time()
{
  set_brightness(brightness);
  getTemp();
  // print_time(time);
  // startState = digitalRead(PP_PIN);
  tempMillis = millis();
  
  while(!pause_play_is_pressed())
  {
    //read button states (only need two because we can only start and add min at this state
    // startState = digitalRead(PP_PIN);
    // minState = digitalRead(RESET_PIN);
  
    // check score buttons
    check_score_buttons();
    
    // check add minute state
    if(reset_is_pressed())
    {
      short_buzzer();
      delay(200);
      increment_time();
      print_screen();
      while(reset_is_pressed())
      {
        // minState = digitalRead(RESET_PIN);
        // startState = digitalRead(PP_PIN);

        // while the reset button is down once I click pause play then increase the brightness
        if(pause_play_is_pressed())
        {
          brightness++;
          if(brightness > 7)
          {
            brightness = 1;
          }
          set_brightness(brightness);
          print_screen();

          // while the reset button is being held down and I hold down the pause play then
          // only increase brightness by 1 and then wait
          while(pause_play_is_pressed());
        }
      }
    }

    // timeout check (turn screen off after 3 min)
    currentMillis = millis();
    if(currentMillis - tempMillis > 180000) {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
      while(!reset_is_pressed());
      tempMillis = millis();
    }
  }
  short_buzzer();
  previousMillis = 0; 
  delay(300); // debounce start button
  // count_down_time();
}

void pauseTime()
{
  debug("time is paused");
  // startState = digitalRead(PP_PIN);
  tempMillis = millis();
  while(!pause_play_is_pressed()) // wait for start button
  {
    // startState = digitalRead(startstopPin);
    // resetState = digitalRead(RESET_PIN); // check reset while waiting for start button
    
    // check score
    check_score_buttons();
    
    // check reset button
    if(reset_is_pressed())
    {
      short_buzzer();
      debounce(reset_is_pressed);
      splashScreen();
    }
    
    // timeout check (turn screen off after 3 min)
    currentMillis = millis();
    if(currentMillis - tempMillis > 180000)
    {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
      while(!reset_is_pressed());
      tempMillis = millis();
      short_buzzer();
      print_screen();
      delay(200);
    }
  }
  short_buzzer();
  debounce(pause_play_is_pressed);
}

int count_down_time()
{
  if (time > 0) // while not out of time
  {
    // short_buzzer warnings
    if (time == 60) // 1 min warning -- beep twice-ish
    {
      long_buzzer();
      delay(400);
    }
    if (time <= 30) {
      red = yellow;
    }
    
    // 10 second shake
    currentMillis = millis();
    if (time <= 10)
    {
      if (currentMillis - shakeMillis > 100) // if 1 second has passed
      {
        shakeMillis = currentMillis; // save the current time
        r += dir;
        rb += dir;
        if (r > 2)
        {
          r -= 2;
          dir =- dir;
          rb -= 2;
        }
        if (r < 1)
        {
          r += 2;
          rb += 2;
          dir = -dir;
        }
        print_screen();
      }
    }
    
    //start 1-second timer
    if (currentMillis - previousMillis > interval) // if 1 second has passed
    {
      previousMillis = currentMillis; // save the current time
      time--; //decrement time time by 1

      if (time % 27 == 0)
      {
        getTemp();
      }

      print_screen();
      
      if (time <= 3)
      {
        short_buzzer();
      }
    }
    
    //button check
    // pauseState = digitalRead(startstopPin);
   
    check_score_buttons();
  }
  return time;
}

