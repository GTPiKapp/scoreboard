// Auxilary pins
const int BUZZ_PIN = 3;
const int TEMP_PIN = 5;

// Button pins
const int HOME_PIN = 7; // Orange wire (pin 7) (yellow button)
const int AWAY_PIN = 5; // Blue wire (pin 5) (blue button)
const int PP_PIN = 6; // Green wire (pin 6) (green button)
const int RESET_PIN = 4; // Brown wire (pin 4) (black button)



void io_setup()
{
  pinMode(PP_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(RESET_PIN, INPUT);
}

void buzz(int pitch, int duration)
{
  tone(BUZZ_PIN, pitch, duration);
}

void short_buzzer()
{
  buzz(700, 30);
}

void long_buzzer()
{
  buzz(700, 200);
}

void end_of_inning_buzzer()
{
  buzz(350, 1700);
}

void debounce(bool (*func)(void))
{
  delay(200);
  while(func());
}

bool check_pin(int pin)
{
  return digitalRead(pin) == HIGH;
}

bool reset_is_pressed()
{
  return check_pin(RESET_PIN);
}

bool pause_play_is_pressed()
{
  return check_pin(PP_PIN);
}

bool home_is_pressed()
{
  return check_pin(HOME_PIN);
}

bool away_is_pressed()
{
  return check_pin(AWAY_PIN);
}

void getTemp()
{
  int val = analogRead(TEMP_PIN);
  float mv = (val / 1024.0) * 5000; 
  float cel = mv / 10;
  float fahrenheit = (cel * 9) / 5 + 32;
  newTemp = 0.1 * fahrenheit + 0.9 * oldTemp;
  oldTemp = newTemp;
  temperature = newTemp - 4;
}
