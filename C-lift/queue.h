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
 Struct represents a linked list and an element. 
 *next is pointer to next queue element. 
 */
typedef struct Order{
    int floor;
    elev_button_type_t button_type;
    struct Order *next;
}Order_t;


/**
 Finds the next floor.
 
 @return int which is the next floor.
 */
Order_t* get_next_floor(void);


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
 Removes floor from queue.
 
 @param floor which is to be removed from the queue.
 
 @return bool true if something was popped, and bool false if nothing was popped.
 */
bool pop_from_queue(int floor);


#endif /* queue_h */
