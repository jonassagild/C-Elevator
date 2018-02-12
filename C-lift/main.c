//
//  main.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include <stdio.h>
#include "controller.h"
#include "io.h"

int main(int argc, const char * argv[]) {
    initialize_system();
    alert_system();
   
    return 0;
}
