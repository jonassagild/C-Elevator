#include "door.h"
#include "elev.h"


void open_door(void){
    start_timer();
    elev_set_door_open_lamp(1);
    elev_motor_direction_t dirn = DIRN_STOP; 
    set_dir(dirn);     
}


void start_timer(){
    time(&start_value); 
}


int check_timer(double seconds){

    time(&end_value);
    if (seconds - difftime(end_value, start_value) < 0) {
        elev_set_door_open_lamp(0);
        return 1;
    } else {
        return 0;
    }
}
