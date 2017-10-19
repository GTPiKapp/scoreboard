void drawScore()
{
  double frac, intpart, temp;
  setCurs(0);
  // example: homeScore = 13
  frac = modf(homeScore/10.0, &intpart); // frac = 0.3, intpart = 1
  drawDigit(intpart);
  setCurs(1);
  temp = frac*10 + 0.5; // int conversion sees a floating 3.00 as 2.993882288... so we add arbitrary 0.5 to ensure it's above truncation point
  frac = modf(temp, &intpart); // frac = 0.0, intpart = 3
  drawDigit(intpart);

  setCurs(7);
  frac = modf(awayScore/10.0, &intpart);
  drawDigit(intpart);
  setCurs(8);
  temp = frac*10 + 0.5;
  frac = modf(temp, &intpart);
  drawDigit(intpart);
}

void score_buttons()
{
  // homescoreState = digitalRead(HOME_PIN);
  // awayscoreState = digitalRead(AWAY_PIN);

  // check home score button
  if(home_is_pressed())
  {
    short_buzzer();
    homeScore++;
    print_time();
    delay(200);
    while(home_is_pressed())
    {
      // awayscoreState = digitalRead(AWAY_PIN);
      // homescoreState = digitalRead(HOME_PIN);
      if(away_is_pressed())
      {
        short_buzzer();
        homeScore--;
        if(homeScore < 0) {homeScore = 0;}
        print_time();
        debounce(away_is_pressed);
      }
    }
  }

  //check away score button
  if(away_is_pressed())
  {
    short_buzzer();
    awayScore++;
    print_time();
    delay(200);
    while(away_is_pressed())
    {
      // homescoreState = digitalRead(HOME_PIN);
      // awayscoreState = digitalRead(AWAY_PIN);
      if(home_is_pressed())
      {
        short_buzzer();
        awayScore--;
        if(awayScore < 0)
        {
          awayScore = 0;
        }
        print_time();
        debounce(home_is_pressed);
      }
    }
  }
}

