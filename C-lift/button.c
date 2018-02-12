//
//  button.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "button.h"
#include "controller.h"

bool light_indicator;
bool button_pushed;


void detect_button(Button *self){
    printf("lys i %d blir skrudd på \n", self->number);
    light_indicator = true;
    printf("handle_button i controller blir kalt: \n");
    handle_button(self);
    
    
}
