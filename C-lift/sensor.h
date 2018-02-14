#ifndef sensor_h
#define sensor_h

#include <stdio.h>

typedef struct Sensor {
    int floor;
}Sensor;


/**
 Calls necessary functions to handle a detecting of a sensor.
 
 @param *self which sensor that has been detected.
 */
void detect_sensor(Sensor *self);



#endif /* sensor.h */
