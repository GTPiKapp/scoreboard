/*
  this doesn't need to take in a parameter as far as I can see. We have the global variable for time.
*/

int time = 300; // initialize at 5 min

void print_time()
{
  double frac, int1, int2, int3, temp;

  // Clear Screen
  matrix.fillScreen(0);
  col = white;
  drawTeams();
  drawScore();
  drawTemp();
  col = red;
  
  // Minutes digit                    ex: num = 345
  temp = (double) time / 60; //                   temp=5.75
  frac = modf(temp, &int1); //     frac=.75, intpart=5
  
  // Tens digit
  temp = (time - 60 * int1)/10; //    temp= 4.5
  frac = modf(temp, &int2); //     frac=.5, intpart=4
  
  // Seconds digit
  temp = frac * 10; //                  temp=5
  int3 = temp + 0.5; // int conversion inside drawDigit sees a floating 5.00 as 4.993882288134081 or whatever, for some reason. Add arbitrary 0.5 to ensure it's above truncation point

  setCurs(4);
  drawDigit(int1);
  // colon 
  matrix.drawPixel(c + 9, r + 3, col);
  matrix.drawPixel(c + 9, r + 4, col);
  matrix.drawPixel(c + 9, r + 8, col);
  matrix.drawPixel(c + 9, r + 9, col);
  setCurs(5);
  drawDigit(int2);
  setCurs(6);
  drawDigit(int3);
  
  matrix.swapBuffers(false);
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
  setLumosity(lumosity);
  getTemp();
  // print_time(time);
  // startState = digitalRead(PP_PIN);
  tempMillis = millis();
  
  while(!pause_play())
  {
    //read button states (only need two because we can only start and add min at this state
    // startState = digitalRead(PP_PIN);
    // minState = digitalRead(RESET_PIN);
  
    // check score buttons
    scoreButtons(time);
    
    // check add minute state
    if(reset())
    {
      buzzer();
      delay(200);
      increment_time();
      print_time();
      Serial.print("Select @: ");
      Serial.println(time);
      while(reset())
      {
        // minState = digitalRead(RESET_PIN);
        // startState = digitalRead(PP_PIN);

        // while the reset button is down once I click pause play then increase the lumosity
        if(pause_play())
        {
          lumosity++;
          if(lumosity > 7)
          {
            lumosity = 1;
          }
          setLumosity(lumosity);
          print_time();

          // while the reset button is being held down and I hold down the pause play then
          // only increase lumosity by 1 and then wait
          while(pause_play());
        }
      }
    }

    // timeout check (turn screen off after 3 min)
    currentMillis = millis();
    if(currentMillis - tempMillis > 180000) {
      matrix.fillScreen(0);
      matrix.swapBuffers(false);
      while(!reset());
      tempMillis = millis();
    }
  }
  buzzer();
  previousMillis = 0;
  count = time;
  delay(300); // debounce start button
  // runClock();
}
