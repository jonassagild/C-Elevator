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


void start_timer(); 
 

//returns 1 if 3 second timer is finished  
int check_timer(double seconds);

#endif /* door.h */
