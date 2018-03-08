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
 Adds buttons floor to queue, if the button is not already in queue.
 
 @param button which represents the button that is pushed.
 */
void push_to_queue(Button *button);


/**
 Deletes the queue, and sets all light_indicators to false
 */
void deletequeue(void);


/**
 Initiliaze the head of the queue.
 */
void initialize_queue(void);


/**
 Adds buttons floor to queue, if the button is not already in queue.
 
 @param floor which is to be removed from the queue.
 
 @return bool true if something was popped, and bool false if nothing was popped.
 */
bool pop_from_queue(int floor);


/**
 For printing queue elements. Only for developing.
 */
void print_queue_elements(void);


#endif /* queue_h */
