#ifndef door_h
#define door_h

#include <stdio.h>
#include "button.h"
#include "elevator.h"
#include <time.h>


time_t start_value; 
time_t end_value;

/**
  Sets open_door_light, and calls starts timer.
*/
void open_door(void);


/**
 Starts the timer.
 */
void start_timer(void);
 

/**
 Returns 1 if the input seconds has passed since the timer started.
 
 @param seconds. The number of seconds you want to check wheter has passed since the clock started.
 
 @return int. 1 if the number of seconds has passed, 0 else.
 */
int check_timer(double seconds);

#endif /* door.h */
