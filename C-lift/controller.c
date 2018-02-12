//
//  controller.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "controller.h"

void print_queue(){
    Queue q;
    q.next_floor = 2;
    
    printf("%d\n", get_next_floor(&q));
    
}


void handle_button(Button *button){
    printf("legger til %d button i køa\n", button->number);
    push_to_queue(button->number, true);
}
