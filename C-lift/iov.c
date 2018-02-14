//
//  iov.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "iov.h"

// declares all buttons
Button b0up;
Button b0com;

Button b1up;
Button b1down;
Button b1com;

Button b2up;
Button b2down;
Button b2com;

Button b3down;
Button b3com;

Button bstop;

// declares all sensors
Sensor s0;
Sensor s1;
Sensor s2;
Sensor s3;

// array containing all buttons
Button buttons[10];

void initialize_system(void){
    // sets all buttons
    b0up.floor = 0;
    b0up.button_type = BUTTON_CALL_UP;
    b0com.floor = 0;
    b0com.button_type = BUTTON_COMMAND;

    b1up.floor = 1;
    b1up.button_type = BUTTON_CALL_UP;
    b1down.floor = 1;
    b1down.button_type = BUTTON_CALL_DOWN;
    b1com.floor = 1;
    b1com.button_type = BUTTON_COMMAND;

    
    b2up.floor = 2;
    b2up.button_type = BUTTON_CALL_UP;
    b2down.floor = 2;
    b2down.button_type = BUTTON_CALL_DOWN;
    b2com.floor = 2;
    b2com.button_type = BUTTON_COMMAND;

    b3down.floor = 3;
    b3down.button_type = BUTTON_CALL_DOWN;
    b0com.floor = 3;
    b0com.button_type = BUTTON_COMMAND;

    // adds all buttons to buttons list
    buttons[0] = b0up;
    buttons[1] = b0com;
    buttons[2] = b1up;
    buttons[3] = b1down;
    buttons[4] = b1com;
    buttons[5] = b2up;
    buttons[6] = b2down;
    buttons[7] = b2com;
    buttons[8] = b3down;
    buttons[9] = b3com;

    // sets stop button
    bstop.floor = 0; // irrelevant
    bstop.button_type = BUTTON_STOP;

    // sets all floor variables
    s0.floor = 0;
    s1.floor = 1;
    s2.floor = 2;
    s3.floor = 3;
    

}

void alert_system(void){
    
    while(1){
        // sjekk om noen av IO er endret, og kall riktig metode, i tilfellet ja.
       

        // sjekker sensorer, og kaller på handle funksjonen. 
        int floor = elev_get_floor_sensor_signal();
        switch(floor) {
            case -1: // kan fjernes 
                break;
            case 0:
                detect_sensor(&s0);
                break;
            case 1:
                detect_sensor(&s1);
                break;
            case 2:
                detect_sensor(&s2);
                break;
            case 3:
                detect_sensor(&s3);
                break;
        }
    
        // sjekker knapper, og kaller på handle funksjonene
        for (int i = 0; i<10; i++){
            if(elev_get_button_signal(buttons[i].button_type, buttons[i].floor)){
                detect_button(&buttons[i]);
            }
        }

        
        // UNTESTED CODE
        // sjekker stopp-knapp, og kaller på handle funksjon
        if (elev_get_stop_signal()){
            detect_button(&bstop);
        }
        

        // MIDLERTIDLIG: bare for å teste koden over.. 

        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        
        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }
}
