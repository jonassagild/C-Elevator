//
//  controller.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "controller.h"
#include "door.h"

int current_floor;
elev_motor_direction_t last_motor_direction;


void handle_button(Button *button){
    push_to_queue(button);
}

void set_floor_indicator(int floor){
    current_floor = floor;
    elev_set_floor_indicator(floor); 
}

void handle_sensor(Sensor *sensor){
    set_floor_indicator(sensor->floor);
    
    elev_button_type_t button;

    // turns off command button lights
    button = BUTTON_COMMAND;
    elev_set_button_lamp(button, sensor->floor, 0);
    
    // turns off up and down button lights
    if (sensor->floor == 0){
        button = BUTTON_CALL_UP;
        elev_set_button_lamp(button, sensor->floor, 0);
    } else if (sensor->floor == 3){
        button = BUTTON_CALL_DOWN;
        elev_set_button_lamp(button, sensor->floor, 0);
    } else {
        if (get_dir() == 1){
            button = BUTTON_CALL_UP;
            elev_set_button_lamp(button, sensor->floor, 0);
        } else if (get_dir() == -1){
            button = BUTTON_CALL_DOWN;
            elev_set_button_lamp(button, sensor->floor, 0);
        } 
    } 
    if (get_next_floor()->floor == -1 && get_dir() == 0){
        elev_loop_lights_off();
    }


    // checks if this floor is in queue, and opens door
    if (pop_from_queue(current_floor)) {
        open_door();
    } 
}

void handle_stop_button(void){
    deletequeue();
    
    elev_motor_direction_t dir = DIRN_STOP;
    set_dir(dir);
    
    if (elev_get_floor_sensor_signal() != -1){
        open_door();
    }
    
    elev_loop_lights_off();
    
    while (elev_get_stop_signal()){
        elev_set_stop_lamp(1);
    }
    elev_set_stop_lamp(0);
    
}

void handle_next_in_line(){

    Order_t *next;
    next = get_next_floor();

    int next_floor = next->floor;
    elev_motor_direction_t dir;

    

    // checks if the elevator is moving towars next_floor
    if (next_floor != -1) { // a button have not been pressed 
        if(next_floor < current_floor) {
            last_motor_direction = DIRN_DOWN;
            dir = DIRN_DOWN;
            set_dir(dir);
        } else if (next_floor > current_floor) {
            last_motor_direction = DIRN_UP;
            dir = DIRN_UP;
            set_dir(dir);
        } else if (elev_get_floor_sensor_signal() == -1) {
            if (next_floor == current_floor && last_motor_direction == DIRN_DOWN){
                dir = DIRN_UP;
                set_dir(dir);
            }
            else if (next_floor == current_floor && last_motor_direction == DIRN_UP){
                dir = DIRN_DOWN;
                set_dir(dir);
            }
        } else {
            dir = DIRN_STOP;
            set_dir(dir);
        }    
    }
}

int get_current_floor(void) {
    return current_floor;
}

elev_motor_direction_t get_last_dir(void) {
    return last_motor_direction;
}
