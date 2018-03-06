//
//  queue.h
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include <stdio.h>
#include "button.h"
#include "elev.h"

/**
 Finds the next floor.
 
 @return int which is the next floor.
 */
int get_next_floor(void);


/**
 Calls necessary functions to handle a detecting of a sensor.
 
 @param floor int number to floor to be visited.
 @param inside_elevator boolean which is true if the button is inside the elevator.
 */
void push_to_queue(Button *button);


/**
 Deletes the queue, and sets all light_indicators to false
 */
void deletequeue(void);

void initialize_queue(void); 

bool pop_from_queue(int floor);

// temporary, only for testing 
void print_queue_elements(void);


#endif /* queue_h */
