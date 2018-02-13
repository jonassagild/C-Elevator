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




void handle_button(Button *button);
void handle_sensor(Sensor *sensor); 
void handle_next_in_line(void); 
void handle_stop_button(void); 
void set_floor_indicator(int floor); 

#endif /* controller_h */
