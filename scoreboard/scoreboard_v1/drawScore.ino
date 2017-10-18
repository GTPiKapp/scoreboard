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

void scoreButtons(int curTime)
{
  homescoreState = digitalRead(HOME_PIN);
  awayscoreState = digitalRead(AWAY_PIN);

  // check home score button
  if(homescoreState == HIGH)
  {
    tone(buzzPin,700,30);
    homeScore++;
    print_time(curTime);
    delay(200);
    while(homescoreState == HIGH)
    {
      awayscoreState = digitalRead(AWAY_PIN);
      homescoreState = digitalRead(HOME_PIN);
      if(awayscoreState == HIGH)
      {
        tone(buzzPin,700,30);
        homeScore--;
        if(homeScore < 0) {homeScore = 0;}
        print_time(curTime);
        delay(200);
        while(awayscoreState == HIGH)
        {
          awayscoreState = digitalRead(AWAY_PIN);
        }
      }
    }
  }

  //check away score button
  if(awayscoreState == HIGH)
  {
    tone(buzzPin,700,30);
    awayScore++;
    print_time(curTime);
    delay(200);
    while(awayscoreState == HIGH)
    {
      homescoreState = digitalRead(HOME_PIN);
      awayscoreState = digitalRead(AWAY_PIN);
      if(homescoreState == HIGH)
      {
        tone(buzzPin,700,30);
        awayScore--;
        if(awayScore < 0) {awayScore = 0;}
        print_time(curTime);
        delay(200);
        while(homescoreState == HIGH)
        {
          homescoreState = digitalRead(HOME_PIN);
        }
      }
    }
  }
}

