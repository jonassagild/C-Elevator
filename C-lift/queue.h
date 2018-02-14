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

typedef struct Queue Queue;

struct Queue {
    int next_floor;
};


/**
 Finds the next floor.
 
 @param *q reference to Queue
 @return int which is the next floor.
 */
int get_next_floor(Queue *q);


/**
 Calls necessary functions to handle a detecting of a sensor.
 
 @param floor int number to floor to be visited.
 @param inside_elevator boolean which is true if the button is inside the elevator.
 */
void push_to_queue(int floor, bool inside_elevator);

#endif /* queue_h */
