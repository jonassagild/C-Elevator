#include "elev.h"
#include <stdio.h>
#include "controller.h"
#include "iov.h"



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
    
    // starts the elevator when user is ready
    dirn = DIRN_UP;
    elev_set_motor_direction(dirn);


    printf("Press STOP button to stop elevator and exit program.\n");

    elev_set_motor_direction(DIRN_UP);

    
    initialize_system();
    alert_system();

    while (1) {
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

    return 0;
}
