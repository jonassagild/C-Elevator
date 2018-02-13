//
//  controller.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "controller.h"
#include "door.h"

void handle_button(Button *button){
    printf("legger til %d button i køa\n", button->number);
    push_to_queue(button->number, true);
}

void set_floor_indicator(int floor){
    elev_set_floor_indicator(floor); 
}

void handle_sensor(Sensor *sensor){
    set_floor_indicator(sensor->floor); 
}
