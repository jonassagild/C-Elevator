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

typedef enum {false, true}bool;

typedef struct Button {
    int number;
}Button;


void detect_button(Button *self);



#endif /* button_h */
