// Auxilary pins
const int BUZZ_PIN = 3;

// Button pins
const int HOME_PIN = 7; // Orange wire (pin 7)
const int AWAY_PIN = 5; // Blue wire (pin 5
const int PP_PIN = 6; // Green wire (pin 6)
const int RESET_PIN = 4; // Brown wire (pin 4)

void buzzer()
{
  tone(BUZZ_PIN, 700, 30);
}

char check_pin(int pin)
{
  if (digitalRead(pin) == HIGH)
  {
    buzzer();
    return 1;
  }
  return 0;
}

char reset()
{
  return check_pin(RESET_PIN);
}

char pause_play()
{
  return check_pin(PP_PIN);
}

char home()
{
  return check_pin(HOME_PIN);
}

char away()
{
  return check_pin(AWAY_PIN);
}