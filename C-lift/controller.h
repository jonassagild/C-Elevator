//
//  controller.h
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#ifndef controller_h
#define controller_h

#include "button.h"
#include "queue.h"
#include "sensor.h"
#include "elev.h"
#include "elevator.h"

#include <stdio.h>


/**
Handle button pushes. Adds floor to queue.
 
 @param button Button which is pushed.
 */
void handle_button(Button *button);


/**
 Handle sensors. Opens door and removes floor from queue, if floor is in queue.
 
 @param sensor Sensor which is high.
 */
void handle_sensor(Sensor *sensor);


/**
 Checks which floor is next in line, and calls methods to handle direction and speed.
 */
void handle_next_in_line(void);


/**
 Handles pushs on the stop button. Calls method necessary from dropping queue and waiting.
 */
void handle_stop_button(void);


/**
 Calls methods necessary for setting the floor indicator.
 
 @param floor int number of floor to set the floor indicator to.
 */
void set_floor_indicator(int floor); 


/**
 Returns this floor, or the last vistited floor.
 */
int get_current_floor(void);


/**
 Returns a elev_motor_direction_t which represents the last direction of the elevator
 */
elev_motor_direction_t get_last_dir(void);

#endif /* controller_h */
