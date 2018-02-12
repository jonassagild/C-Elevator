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

int get_next_floor(Queue *q);
void push_to_queue(int floor, bool inside_elevator);

#endif /* queue_h */
