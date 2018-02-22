//
//  queue.c
//  heisprosjekt
//
//  Created by Jonas Åsnes  Sagild on 07.02.2018.
//  Copyright © 2018 Jonas Åsnes  Sagild. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>
int floors = 3; 

typedef struct Order{
    int floor;
    elev_button_type_t button_type;
    struct Order *next;
}Order_t;

Order_t *head;


int get_next_floor(){
    return head->floor;
}



void push_to_queue(Button *button){
    // checks if elements is already in queue

    Order_t *midl_queue;
    midl_queue = head;
    while (midl_queue->next != NULL) {
        if(midl_queue->floor == button->floor && midl_queue->button_type == button->button_type) {
            return;
        }
        midl_queue = midl_queue->next;
    }
    if(midl_queue->floor == button->floor && midl_queue->button_type == button->button_type) {
            return;
    }
    midl_queue = head; 
    
     // adds button click to queue 
    Order_t *o;
    o = malloc(sizeof(Order_t));
    o->floor = button->floor;
    o->button_type = button->button_type;
    o->next = malloc(sizeof(Order_t));
    o->next = NULL;
    midl_queue->next = o;
    
    /*if(midl_queue->floor == -1){
        midl_queue->next = o; 
    }
    
    
    while (midl_queue->next != NULL) {
        
        if (midl_queue->floor == button->floor && midl_queue->button_type == BUTTON_COMMAND){
            return; 
        }
        if ((midl_queue->next->floor - midl_queue->floor) > 0){
                int i; 
                for(i = midl_queue->floor; i < floors; i++){
                    if (button->floor == i && button->button_type != BUTTON_CALL_DOWN){
                        Order_t *midl_midle_queue;
                        midl_midle_queue = midl_queue->next;
                        o->next = midl_midle_queue;
                        midl_queue->next = o;
                    }
                }
                if(button->floor == (i+1)){
                        Order_t *midl_midle_queue;
                        midl_midle_queue = midl_queue->next;
                        o->next = midl_midle_queue;
                        midl_queue->next = o;
                }
        } else{
                int i;           
                for(i = floors;i > midl_queue->floor; i--){
                    if (button->floor == i && button->button_type != BUTTON_CALL_DOWN){
                        Order_t *midl_midle_queue;
                        midl_midle_queue = midl_queue->next;
                        o->next = midl_midle_queue;
                        midl_queue->next = o;
                    }
                }
                if ((i >= 0) && button->floor == (i-1)){
                        Order_t *midl_midle_queue;
                        midl_midle_queue = midl_queue->next;
                        o->next = midl_midle_queue;
                        midl_queue->next = o;
                }
        }
        midl_queue = midl_queue->next;

    }*/

    // checks if elevator is in a defined state
    if (head->floor == -1){
        head = head->next;
    }
}


void deletequeue(void){
    initialize_queue();
}


void pop_from_queue(void){
    head = head->next;
    if (head == NULL) {
        head = malloc(sizeof(Order_t));
        head->floor = -1;
        head->next = malloc(sizeof(Order_t));
        head->next = NULL;
    }
}


void initialize_queue(void){
    head = NULL;
    head = malloc(sizeof(Order_t));
    head->button_type = BUTTON_COMMAND; // could have been anything
    head->floor = -1;
    head->next = malloc(sizeof(Order_t));
    head->next = NULL;
}