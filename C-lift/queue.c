//
//  queue.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>
#include "elevator.h"
#include "controller.h"


Order_t *head;

// internal header

/**
 Checks if parameter button is already in queue.
 
 @param button which is to be checked.
 
 @return bool true if button is already in queue, and false if its not in queue.
 */
bool check_already_in_queue(Button *button);


/**
 Helper function to push_to_queue. Adds button to list.
 
 @param queue, button. Button which is to be added to queue. 
 */
void add_to_queue(Order_t *queue, Button *button);


/**
 Helper function to pop_from_queue. Removes order_to_be_removed from list. 
 
 @param order_to_be_removed, last_order_element. Order_to_be_removed is the order to
  be removed, last_order_element is the element before order_to_be_removed, in the list.
 */
void remove_from_queue(Order_t *order_to_be_removed, Order_t *last_order_element);

// end internal header


Order_t* get_next_floor(){
    // get dir from elevator
    elev_motor_direction_t dir;
    dir = get_dir();
    elev_motor_direction_t last_dir;
    last_dir = get_last_dir();


    // get current floor from elevator
    int current_floor = get_current_floor();


    // finds the next floor 
    for (int i = 0; i<N_FLOORS; i++) {
        Order_t *check = head;
        while(check != NULL) {
            if(dir == DIRN_UP || last_dir == DIRN_UP){
                if (check->floor == current_floor + i) {
                    if (check->button_type == BUTTON_COMMAND || check->button_type == BUTTON_CALL_UP) {
                        if(last_dir == DIRN_UP && check->floor == current_floor) {
                            // do nothing
                        } else {
                            return check;
                        } 
                    }
                }
            } 
            else if (dir == DIRN_DOWN || last_dir == DIRN_DOWN) {
                if (check->floor == current_floor - i) {
                    if (check->button_type == BUTTON_COMMAND || check->button_type == BUTTON_CALL_DOWN) {
                        if (last_dir == DIRN_DOWN && check->floor == current_floor) {
                            // do nothing
                        } else {
                            return check;
                        } 
                    }
                }

            }
            // gets next element
            check = check->next;
        }
    }
    return head;    
}



bool check_already_in_queue(Button *button){
    Order_t *midl_queue;
    midl_queue = head;
    while (midl_queue->next != NULL) {
        if(midl_queue->floor == button->floor && midl_queue->button_type == button->button_type) {
            return true;
        }
        midl_queue = midl_queue->next;
    }
    if(midl_queue->floor == button->floor && midl_queue->button_type == button->button_type) {
            return true;
    }
    return false;
}


void add_to_queue(Order_t *queue, Button *button) {
    // adds button click to queue 
    Order_t *o;
    o = malloc(sizeof(Order_t));
    o->floor = button->floor;
    o->button_type = button->button_type;
    o->next = malloc(sizeof(Order_t));
    o->next = NULL;
    
    if (queue->floor == -1) {
        head = o;
        return;
    }

    // add to queue
    while (queue->next != NULL) {
        queue = queue->next;
    }
    
    queue->next = o;   
}


void push_to_queue(Button *button){
    // checks if elements is already in queue
    if(check_already_in_queue(button)) {
        return;
    }

    // adds element to queue
    add_to_queue(head, button);
}


void deletequeue(void){
    initialize_queue();
}


bool pop_from_queue(int floor){
    bool something_popped = false;

    // gets last_direction
    elev_motor_direction_t last_dir;
    last_dir = get_last_dir();

    // initialize order elements
    Order_t *last = NULL;
    Order_t *check = head;

    while (check != NULL) {
        if (floor == check->floor) { 
            if (get_next_floor()->floor == check->floor && get_next_floor()->button_type == check->button_type) {
                remove_from_queue(check, last);
                something_popped = true;
            } else if (floor == 0 || floor == 3) {
                remove_from_queue(check, last);
                something_popped = true;
            } else if (last_dir == DIRN_DOWN && check->button_type ==  BUTTON_CALL_UP) {
                // do nothing
            } else if (last_dir == DIRN_UP && check->button_type ==  BUTTON_CALL_DOWN) {
                // do nothing
            } else if (last_dir == DIRN_UP && check->button_type == BUTTON_CALL_UP) {
                remove_from_queue(check, last);
                something_popped = true;
            } else if (last_dir == DIRN_DOWN && check->button_type == BUTTON_CALL_DOWN) {
                remove_from_queue(check, last);
                something_popped = true;
            } else if (check->button_type == BUTTON_COMMAND) {
                remove_from_queue(check, last);
                something_popped = true;
            } else if (last_dir == DIRN_STOP) {
                remove_from_queue(check, last);
                something_popped = true;
            } else if (check->floor == floor && check->next == NULL) {
                remove_from_queue(check, last);
                something_popped = true;
            } 
        }
        last = check;
        check = check->next;
    } 
    
    if (something_popped) {
        pop_from_queue(floor);
    }

    
    if (head == NULL) {
        head = malloc(sizeof(Order_t));
        head->floor = -1;
        head->next = malloc(sizeof(Order_t));
        head->next = NULL;
    }

    return something_popped;
}


void initialize_queue(void){
    head = NULL;
    head = malloc(sizeof(Order_t));
    head->button_type = BUTTON_COMMAND; 
    head->floor = -1;
    head->next = malloc(sizeof(Order_t));
    head->next = NULL;
}

void remove_from_queue(Order_t *order_to_be_removed, Order_t *last_order_element) {
    if (last_order_element != NULL) { 
        if (order_to_be_removed->next != NULL) { 
            last_order_element->next = order_to_be_removed->next; 
        } else { 
            last_order_element->next = NULL;
        }
    } else { 
        if (head->next != NULL) {
            head = head->next;
        } else {
            head->floor = -1;
        }
    }
}
