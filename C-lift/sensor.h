#ifndef sensor_h
#define sensor_h

#include <stdio.h>

typedef struct Sensor {
    int floor;
}Sensor;


void detect_sensor(Sensor *self);



#endif /* sensor.h */
