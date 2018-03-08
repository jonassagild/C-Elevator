//
//  elevator.h
//  C-lift
//
//  Created by Jonas Åsnes  Sagild on 21.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#ifndef elevator_h
#define elevator_h

#include <stdio.h>
#include "elev.h"


/**
 Calls method to handle a change of direction of the elevator.
 
 @param dirn desired direction of the elevator.
 */
void set_dir(elev_motor_direction_t dirn);


/**
 Returns the direction of the elevator
 
 @return direction.
 */
elev_motor_direction_t get_dir(void);

#endif /* elevator_h */
