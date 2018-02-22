//
//  button.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "button.h"
#include "controller.h"

void detect_button(Button *self){
    
    if (self->button_type == BUTTON_STOP) {
        handle_stop_button();
    } else {
        if (elev_get_stop_signal() == 0){
            elev_set_button_lamp(self->button_type, self->floor, 1);
            handle_button(self);
        }
    }
}
