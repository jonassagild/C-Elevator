//
//  elevator.c
//  C-lift
//
//  Created by Jonas Åsnes  Sagild on 21.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "elevator.h"

elev_motor_direction_t dir;

void set_dir(elev_motor_direction_t dirn){
    dir = dirn;
    elev_set_motor_direction(dirn);
}

elev_motor_direction_t get_dir(){
    return dir;
}
