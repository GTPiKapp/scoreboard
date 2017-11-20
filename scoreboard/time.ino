enum innings{
  BOTTOM_OF_FIRST,
  TOP_OF_FIRST,
  BOTTOM_OF_SECOND,
  TOP_OF_SECOND,
  THIRD
};

void reset_time()
{
  static int current_inning = BOTTOM_OF_FIRST;
  switch (current_inning)
  {
    case BOTTOM_OF_FIRST:
      time = 300;
      current_inning = TOP_OF_FIRST;
      break;
    case TOP_OF_FIRST:
      time = 300;
      current_inning = BOTTOM_OF_SECOND;
      break;
    case BOTTOM_OF_SECOND:
      time = 360;
      current_inning = TOP_OF_SECOND;
      break;
    case TOP_OF_SECOND:
      time = 360;
      current_inning = THIRD;
      break;
    case THIRD:
      time = 420; // lol
      break;
    default:
      error("current inning is unknown, looping idly");
      for (;;);
  }
}

int increment_time()
{
  if (time >= 420)
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
  print_screen();
  tempMillis = millis();
  
  while(!pause_play_is_pressed())
  {
    check_score_buttons();
    
    if(reset_is_pressed())
    {
      short_buzzer();
      delay(200);
      increment_time();
      print_screen();
      while(reset_is_pressed())
      {
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
          debounce(pause_play_is_pressed);
        }
      }
    }

    // timeout check (turn screen off after 3 min)
    // THIS IS THE RIGHT WAY TO HANDLE TIMEOUT GIVEN THE DEBOUNCE AND PRINT SCREEN
    currentMillis = millis();
    if(currentMillis - tempMillis > TIMEOUT) {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
      while(!reset_is_pressed());
      debounce(reset_is_pressed);
      print_screen();
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
  tempMillis = millis();
  while(!pause_play_is_pressed()) // wait for start button
  { 
    check_score_buttons();

    if (reset_is_pressed())
    {
      short_buzzer();
      debounce(reset_is_pressed);
      splashScreen();
    }
    
    // timeout check (turn screen off after 3 min)
    currentMillis = millis();
    debug("" + (currentMillis - tempMillis));
    if (currentMillis - tempMillis > TIMEOUT)
    {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
      while(!reset_is_pressed());
      debounce(reset_is_pressed);
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
  if (time == 60) // 1 min warning -- beep twice-ish
  {
    long_buzzer();
    delay(400);
  }
  if (time <= 30) {
    red = yellow;
  }
  
  // 10 second shake
  // CURRENTLY DOESNT WORK
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
 
  check_score_buttons();
  
  return time;
}
