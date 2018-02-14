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

#include <stdio.h>



/**
Handle button pushs. Adds floor to queue.
 
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

#endif /* controller_h */
