#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "./common.h"

#define OE   9
#define LAT 10
#define CLK 11
#define A   A0
#define B   A1
#define C   A2
#define D   A3
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

// Digit variables
int r = 1,
    red,
    blue,
    white,
    green,
    yellow,
    grey,
    black,
    color,
    dir = 1, // direction bit for clock bounce at <= 3 seconds
    rb = r+12,
    c = 0,
    cp = c + 7,
    brightness = 2,
    i,
    j;

// Clock Variables
float temperature;
float newTemp;
float oldTemp = 75;

unsigned long currentMillis;
long previousMillis;
long tempMillis;
long shakeMillis;
long interval = 1000;


int awayScore = 0;
int homeScore = 0;
int startState, pauseState, minState, resetState, homescoreState, awayscoreState; // variables to hold button states


// SETUP
void setup()
{
  matrix.begin();       // Initialize the matrix.
  Serial.begin(9600);
  io_setup();
  set_brightness(0);
}

// main loop --> jump into state machine
void loop()
{
  run_state_machine();
}





