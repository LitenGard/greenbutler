
#define SYS_NAME_VERSION "GreenButler v0.5"
#define SYS_GREETING "Hello Karoo!"

#define LCD_CHARS 16
#define LCD_LINES 2

#define TIMER_READ 5000

#define NAME_PUMP_A "P1"
#define NAME_PUMP_B "P2"
#define NAME_FAN "Fans"
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

// ----- RUNNING PARAMETERS -----
// -- This is the daily watering alarm
#define ALARM_DAILY_HOUR 16
#define ALARM_DAILY_MINUTE 03

// -- How many minutes the pumps must run
#define RUNTIME_SECONDS_PUMP_A 12
#define RUNTIME_SECONDS_PUMP_B 8

// -- Disabling any pumps? (1 = disable)
#define PUMP_DISABLE_A 0
#define PUMP_DISABLE_B 0

// -- If the soil is at this percentage of dryness, the alarm is permitted to start watering
#define DRY_SOIL_THRESHOLD_PERCENT 30

// -- If the soil is at this percentage of dryness, pumps are started in spite of alarm time
#define DRY_SOIL_TRIGGER_PERCENT 20

// -- Start the fans if temperature or humidity is higher than this:
#define START_FAN_AT_DEGREES 31
#define START_FAN_AT_HUMID 80

// -- Stop the fans if the temperature or humidity is lower than this:
#define STOP_FAN_AT_DEGREES 29
#define STOP_FAN_AT_HUMID 60

// -- If the temperature gets this low, do not start pumps, as they may be iced up.
#define PUMP_ICE_PROTECTION_DEGREES 2


/* Timer Constants & Variables */
const int COUNTER_1S = 1;
const int COUNTER_10S = 10;
const int COUNTER_1M = 60;
const int COUNTER_15M = 900;

