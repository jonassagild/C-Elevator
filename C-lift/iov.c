//
//  iov.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "iov.h"

Button b1;

void initialize_system(void){
    b1.number = 1;
    
    
}

void alert_system(void){
    
    int etasje_vil;
    
    while(1){
        // sjekk om noen av IO er endret, og kall riktig metode, i tilfellet ja.
        
        printf("Hvilken etasje vil du til?\n");
        scanf("%d\n", &etasje_vil);
        
        b1.number = etasje_vil;
        
        printf("sier i fra til b1: \n");
        detect_button(&b1);
        
        
    }
}
