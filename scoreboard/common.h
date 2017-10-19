// Time prototypes
void reset_time();
void print_time();
int increment_time();
void select_time();
void pause_time();
int count_down_time();

// IO prototypes
void io_setup();
void buzz(int pitch, int duration);
void short_buzzer();
void long_buzzer();
void end_of_inning_buzzer();
void debounce(bool (*func)(void));
bool check_pin(int pin);
bool reset_is_pressed();
bool pause_play_is_pressed();
bool home_is_pressed();
bool away_is_pressed();