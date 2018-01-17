#include <LiquidCrystal.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "parameters.h"
#include "Display.h"
#include "Relay.h"
#include "Sensors.h"

Display display;
Relay relay;
Sensors sensors;

volatile uint16_t timercount;
int updateTimers = 0;

void setup() {
  Serial.begin(9600);

  // In the beginnining...
  relay.begin();
  display.begin();
  sensors.begin();

  delay(500);
  display.runScreen();

  wdt_enable(WDTO_8S);  // watchdog threshold to 8 secs
  configureTimers();
}

void loop() {
  wdt_reset();  // reset watchdog, still ok here.

  if (updateTimers != 0)
  {
    timercount++;
    checkScheduler();
    updateTimers = 0;
  }

}

/*
  Configure the timer/s and interrupts.
  This goes out of sight and out of mind quick, read about it, remember it!
*/
void configureTimers()
{
  cli();                  // disable global interrupts
  TCCR1A = TCCR1B = 0;    // set entire TCCR1A and B registers to 0

  OCR1A = 15624;          // set interrupt to desired timer value
  // 16 000 000 cpu clock / (1024 prescaler * 1 hz desired interrupt frequency) - 1

  TIMSK1 |= (1 << OCIE1A);  // set the OCIE1A bit to enable timer compare interrupt

  TCCR1B |= (1 << WGM12);   // set WGM12 bit to enable CTC mode

  TCCR1B |= (1 << CS10);    // setting the CS10 bit on the TCCR1B register, the timer is running.

  // ISR(TIMER1_OVF_vect) will be called when it overflows.
  // ISR(TIMER1_COMPA_vect) will be called when it compare matches.

  TCCR1B |= (1 << CS12);    // Setting CS10 and CS12 bits = clock/1024 prescaling

  sei();                    // enable global interrupts
}

/**
  The handler for timer1 compare match interrupt
*/
ISR(TIMER1_COMPA_vect)
{
  updateTimers = 1;
}

/**
   This function checks the timercount variable as it is ticked by the interupt compares, and fires off the task functions.
   Do not over-read this, it is simple.
*/
void checkScheduler()
{
  if ((timercount % COUNTER_5S) == 0) task_5S();
  if ((timercount % COUNTER_10S) == 0) task_10S();
  if ((timercount % COUNTER_1M) == 0) task_1M();
  if ((timercount % COUNTER_5M) == 0) task_5M();
  if ((timercount % COUNTER_15M) == 0) task_15M();
}

// This function is called every 5 seconds
void task_5S()
{
  Serial.println(F("5S fired"));
}

// This function is called every 10 Seconds
void task_10S()
{
  Serial.println(F("10S fired"));
  sensors.getTemperature();
}

// This function is called every minute
void task_1M()
{
  Serial.println(F("1M fired"));
}

// This function is called every  5 minutes
void task_5M()
{
  Serial.println(F("5M fired"));
}

// This function is called every 15 minutes
void task_15M()
{
  Serial.println(F("15M fired"));
}

