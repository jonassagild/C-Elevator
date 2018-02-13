#include "door.h"
#include "elev.h"
#include <time.h>

bool open_door(void){
   printf("Her venter vi i 3 sekunder\n");
    elev_set_door_open_lamp(1);
    return true;     
}

