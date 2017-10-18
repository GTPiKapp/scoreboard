#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

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
    col,
    dir = 1, // direction bit for clock bounce at <= 3 seconds
    rb = r+12,
    c = 0,
    cp = c + 7,
    lumosity = 2,
    i,
    j;

// Clock Variables
float temperature;
float newTemp;
float oldTemp = 75;

int count = 300;
unsigned long currentMillis;
long previousMillis;
long tempMillis;
long shakeMillis;
long interval = 1000;


int awayScore = 0;
int homeScore = 0;
int startState, pauseState, minState, resetState, homescoreState, awayscoreState; // variables to hold button states


enum log_levels{ERROR, INFO, DEBUG};

// change this to change the log leve
const int LOG_LEVEL = DEBUG;

// SETUP
void setup()
{
  matrix.begin();       // Initialize the matrix.
  Serial.begin(9600);
  pinMode(PP_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(RESET_PIN, INPUT);
  setLumosity(0);
}

// main loop --> jump into state machine
void loop()
{
  run_state_machine();
}




