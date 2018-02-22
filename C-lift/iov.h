//
//  iov.h
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#ifndef iov_h
#define iov_h

// includes

#include <stdio.h>
#include "button.h"
#include "sensor.h"
#include "elev.h"
#include "controller.h"
#include "door.h"


/**
 Sets up all necessary variables
 */
void initialize_system(void);

/**
 Checks all IO's and call handle functions.
 */
void alert_system(void);

/**
 Checks if stop_button is pressed
 
 @return bool true if button is pressed, false if not
 */
bool check_stop_button(void);


#endif /* iov_h */
