enum states{SPLASH_SCREEN, INIT_TIME, COUNT_DOWN, PAUSE_TIME, TIME_ZERO};

void run_state_machine()
{
  int current_state = SPLASH_SCREEN;
  printHeader("entering state machine");

  for (;;)
  {
    switch (current_state) 
    {
      case SPLASH_SCREEN:
        debug("splash screen");
        splashScreen();
        current_state = INIT_TIME;
        break;

      case INIT_TIME:
        debug("init time");
        
        print_screen();
        select_time();
        current_state = COUNT_DOWN;
        break;

      case COUNT_DOWN:
        debug("count down");

        if (count_down_time() > 0)
        {
          if (pause_play_is_pressed())
          {
            short_buzzer();
            debounce(pause_play_is_pressed);
            current_state = PAUSE_TIME;
          }  
        }
        else
        {
          current_state = TIME_ZERO;  
        }
        break;

      case PAUSE_TIME:
        debug("pause_time");

        if (pause_play_is_pressed())
        {
          short_buzzer();
          delay(200);
          while (pause_play_is_pressed());
          current_state = COUNT_DOWN;
        }
        else if (reset_is_pressed())
        {
          short_buzzer();
          delay(200);
          while (reset_is_pressed());
          reset_time();   
          current_state = SPLASH_SCREEN;
        }
        else
        {
          check_score_buttons();
        }
        break;

      case TIME_ZERO:
        debug("time is zero");
        if (reset_is_pressed())
        {
          short_buzzer();
          reset_time();
          current_state = SPLASH_SCREEN;
        }
        else // let 0:00 sit untill button press
        {
          // timeout check (turn screen off after 3 min)
          currentMillis = millis();
          if (currentMillis - previousMillis > 180000) {
            matrix.fillScreen(0);
            matrix.swapBuffers(false);
          }
          else 
          {
            // want to ensure that score_buttons can't affect timeout of display - only reset button can
            check_score_buttons();
          }
        }
        break;

      default:
        error("entered default state, looping idly");
        for (;;);
    }
  }
}

void check_score_buttons()
{  if(home_is_pressed())
  {
    short_buzzer();
    homeScore++;
    print_screen();
    delay(200);
    while(home_is_pressed())
    {
      if(away_is_pressed())
      {
        short_buzzer();
        homeScore--;
        if (homeScore < 0)
        {
          homeScore = 0;
        }
        print_screen();
        debounce(away_is_pressed);
      }
    }
  }

  if (away_is_pressed())
  {
    short_buzzer();
    awayScore++;
    print_screen();
    delay(200);
    while (away_is_pressed())
    {
      if (home_is_pressed())
      {
        short_buzzer();
        awayScore--;
        if (awayScore < 0)
        {
          awayScore = 0;
        }
        print_screen();
        debounce(home_is_pressed);
      }
    }
  }
}