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
    printf("legger til %d button i køa\n", button->floor);
    push_to_queue(button->floor, true);
}

void set_floor_indicator(int floor){
    elev_set_floor_indicator(floor); 
}

void handle_sensor(Sensor *sensor){
    set_floor_indicator(sensor->floor); 
}

void handle_stop_button(void){
    deletequeue();
    
    elev_motor_direction_t dir = DIRN_STOP;
    set_dir(dir);
    
    // sjekker om noen av sensorene er høy
    if (elev_get_floor_sensor_signal() != -1){
        open_door();
    }
    
    //
    if (elev_get_stop_signal()){
        //lys på mens knapp er holdt inn
    }
}
