#ifndef GPIOEVENT_H
#define GPIOEVENT_H

/*
 * Functions for controlling event detection for Raspberry Pi GPIO.
 *
 * Author: Pat Hanrahan <hanrahan@cs.stanford.edu>
 *         Philip Levis <pal@cs.stanford.edu>
 *         Julie Zelenski <zelenski@cs.stanford.edu>
 *
 * Last edited: Jan 2018
 */

#include "gpio.h"

enum gpio_event {
    GPIO_DETECT_RISING_EDGE = 0,
    GPIO_DETECT_FALLING_EDGE,
    GPIO_DETECT_HIGH_LEVEL,
    GPIO_DETECT_LOW_LEVEL,
    GPIO_DETECT_ASYNC_RISING_EDGE,
    GPIO_DETECT_ASYNC_FALLING_EDGE,
};

/*
 * Enables detection of GPIO `event` for GPIO pin number `pin`.
 *
 * If `pin` or `event` is invalid, does nothing.
 */
void gpio_enable_event_detection(unsigned int pin, unsigned int event);

/*
 * Disables detection of GPIO `event` for GPIO pin number `pin`.
 *
 * If `pin` or `event` is invalid, does nothing.
 */
void gpio_disable_event_detection(unsigned int pin, unsigned int event);

/*
 * Gets the state of detection of GPIO `event` for GPIO pin number `pin`.
 * Returns 0 if event detection is not enabled for `event`,
 * or 1 if event detection is enabled.
 *
 * If `pin` or `event` is invalid, returns GPIO_INVALID_REQUEST.
 */
unsigned int gpio_get_event_detection(unsigned int pin, unsigned int event);

/*
 * Disables detection of all GPIO events for GPIO pin number `pin`. 
 *
 * If `pin` is invalid, does nothing.
 */
void gpio_disable_all_event_detection(unsigned int pin);

/*
 * Returns the event status for GPIO pin number `pin`. 
 * The event status is 1 if an event has been detected for `pin` 
 * and the event has not been cleared, status is 0 otherwise.
 *
 * If `pin` is invalid, returns GPIO_INVALID_REQUEST.
 */
unsigned int gpio_check_event(unsigned int pin);

/*
 * Clears the event status for GPIO pin number `pin`. Note that if the
 * event detected is high or low level and the level is still high or low,
 * clearing the event makes no change in event status.  The event 
 * status remains 1 as long as the high or low level is in effect.
 *
 * If `pin` is invalid, does nothing.
 */
void gpio_clear_event(unsigned int pin);

/*
 * Returns the event status for GPIO pin number `pin` and clears the
 * event status.
 *
 * If `pin` is invalid, does nothing and returns GPIO_INVALID_REQUEST.
 */
unsigned int gpio_check_and_clear_event(unsigned int pin);

#endif
