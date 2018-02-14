//
//  button.h
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#ifndef button_h
#define button_h

#include <stdio.h>
#include "elev.h"

typedef enum {false, true}bool;

typedef struct Button {
    int floor;
    elev_button_type_t button_type;
}Button;

/**
 Calls functions to handle a detection of a button. 
 
 @param self Button which has been pushed.
 */
void detect_button(Button *self);



#endif /* button_h */
