enum states{SPLASH_SCREEN, INIT_TIME, COUNT_DOWN, PAUSE_TIME};


void run_state_machine()
{
  int current_state = SPLASH_SCREEN;
  printHeader("entering state machine");

  for (;;)
  {
    switch (current_state) {
      case SPLASH_SCREEN:
        debug("splash screen");
        splashScreen();
        current_state = INIT_TIME;
        break;
      case INIT_TIME:
        debug("init time");
        
        print_time();
        select_time();
        // if (pause_play())
        // {
        //   current_state = COUNT_DOWN;
        // } 
        // else if (reset())
        // {
        //   debug("incrementing time");
        //   delay(200);
        //   increment_time();
        //   print_time();
        // }
        current_state = COUNT_DOWN;
        break;
      case COUNT_DOWN:
        debug("count down");
        if (pause_play())
        {
          current_state = PAUSE_TIME;
        }
        break;
      case PAUSE_TIME:
        debug("pause_time");
        if (pause_play)
        {
          current_state = COUNT_DOWN;
        } else if (reset())
        {
          current_state = SPLASH_SCREEN;
        }
        break;
      default:
        error("entered default state, looping idly");
        for (;;);
    }
  }
}
