#include <LiquidCrystal.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "parameters.h"
#include "Display.h"
#include "Relay.h"

Display display;
Relay relay;

volatile uint16_t timercount;
int updateTimers = 0;

void setup() {
  Serial.begin(9600);
  
  display.begin();
  delay(500);
  display.reset();
  relay.begin();
  display.reset();
  display.runScreen();
  
  delay(600);
  display.updateStatuses(true,false,false,false);

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

/* The handler for timer1 compare match interrupt */
ISR(TIMER1_COMPA_vect)
{
  updateTimers = 1;
}

void checkScheduler()
{
  if ((timercount % COUNTER_2S) == 0) task_2S();
  if ((timercount % COUNTER_5S) == 0) task_5S();
  if ((timercount % COUNTER_1M) == 0) task_1M();
  if ((timercount % COUNTER_5M) == 0) task_5M();
  if ((timercount % COUNTER_15M) == 0) task_15M();     
}

// Every 2 Seconds
void task_2S()
{
  Serial.println("2S fired");
}

// This function is called every 5 seconds
void task_5S()
{
  Serial.println("5S fired");
}

// This function is called every minute
void task_1M()
{
  Serial.println("1M fired");
}

// This function is called every  5 minutes
void task_5M()
{
  Serial.println("5M fired");
}

// This function is called every 15 minutes
void task_15M()
{
  Serial.println("15M fired");
}

