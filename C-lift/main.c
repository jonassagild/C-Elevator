#include "elev.h"
#include <stdio.h>
#include "controller.h"
#include "iov.h"
#include "queue.h"
#include "door.h" 


int main() {

   
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

     // sets speed to 0, and waits for ready signal
    elev_motor_direction_t dirn = DIRN_STOP;
    elev_set_motor_direction(dirn);

    printf("Trykk enter for å starte\n");
    int i;
    scanf("%d", &i);



    printf("Press STOP button to stop elevator and exit program.\n");
    
    initialize_queue();
    initialize_system();
    alert_system();

    return 0;
}
