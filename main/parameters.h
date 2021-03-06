
#define SYS_NAME_VERSION "GreenButler v0.3"
#define SYS_GREETING "Hello Karoo!"

#define LCD_CHARS 16
#define LCD_LINES 2

#define TIMER_READ 5000

#define NAME_PUMP_A "P1"
#define NAME_PUMP_B "P2"
#define NAME_FAN "Fan"
#define NAME_SOLENOID "Flow"

#define PIN_RELAY1_SOLENOID  8
#define PIN_RELAY2_FAN  9
#define PIN_RELAY3_PUMP_A  10
#define PIN_RELAY4_PUMP_B  11

#define PIN_LCD_RS 2
#define PIN_LCD_ENABLE 3
#define PIN_LCD_D4 4
#define PIN_LCD_D5 5
#define PIN_LCD_D6 6
#define PIN_LCD_D7 7

#define PIN_DISPLAY_MODE_TOGGLESW A3

// Sensors
#define PIN_SENSOR_DHT11 12
#define PIN_SOIL_MOISTURE_ANALOG A2

// Values to calibrate the soil moisture probe by testing!
#define SOIL_MOIST_MAP_DRY 1020
#define SOIL_MOIST_MAP_SOAK 130

/* Timer Constants & Variables */
const int COUNTER_1S = 1;
const int COUNTER_10S = 10;
const int COUNTER_1M = 60;
const int COUNTER_15M = 900;

