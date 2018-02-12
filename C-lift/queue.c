//
//  queue.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "queue.h"



int get_next_floor(Queue *q){
    return  q->next_floor;
    
}



void push_to_queue(int floor, bool inside_elevator){
    // function receives a floor number and decides where in the queue to place it.
    printf("etasje %d ble nå lagt til. Knapp var %u heisen\n", floor, inside_elevator);
    
}
