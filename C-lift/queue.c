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


int floors = 3; 

typedef struct Order{
    int floor;
    elev_button_type_t button_type;
    struct Order *next;
}Order_t;

Order_t *head;


bool check_already_in_queue(Button *button);

void add_to_queue(Order_t *queue, Button *button);

void remove_from_queue(Order_t *order_to_be_removed, Order_t *last_order_element);


// finds next floor
int get_next_floor(){
    // get dir of elevator
    elev_motor_direction_t dir;
    dir = get_dir();
    elev_motor_direction_t last_dir;
    last_dir = get_last_dir();

    // get current floor of elevator
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
                            return check->floor;
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
                            return check->floor;
                        } 
                    }
                }

            }
            // gets next element
            check = check->next;
        }
    }
    return head->floor;    
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

    // // checks if elevator is in a defined state - why?
    // if (head->floor == -1){
    //     head = head->next;
    // } 
}


void deletequeue(void){
    initialize_queue();
}


void print_queue_elements(){
    Order_t *midl_queue;
    midl_queue = head;
    int i = 0;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("%dte køelement er %d, %d\n", i, midl_queue->floor, midl_queue->button_type);
    
    while(midl_queue->next != NULL) {
        midl_queue = midl_queue->next;
        printf("%dte køelement er %d, %d\n", i, midl_queue->floor, midl_queue->button_type);
        i++;
    }
}


bool pop_from_queue(int floor){
    // sets return
    bool something_popped = false;

    // get last_direction
    elev_motor_direction_t last_dir;
    last_dir = get_last_dir();


    // initialize order elements
    Order_t *last = NULL;
    Order_t *check = head;

    while (check != NULL) {
        if (floor == check->floor) {
            if (floor == 0 || floor == 3) {
                remove_from_queue(check, last);
                something_popped = true;
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


    // probably never ?
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
    head->button_type = BUTTON_COMMAND; // could have been anything
    head->floor = -1;
    head->next = malloc(sizeof(Order_t));
    head->next = NULL;
}

void remove_from_queue(Order_t *order_to_be_removed, Order_t *last_order_element) {
    if (last_order_element != NULL) { // if there is a last_order_element
        if (order_to_be_removed->next != NULL) { // hvis order_to_be_removed har et element etter seg
            last_order_element->next = order_to_be_removed->next; // 
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