/*
 * File:   main.c
 * Author: Admin
 *
 */


//-----------------------------------
#include "../Inc/ApplicationExample.h"
//-----------------------------------

void main(void) 
{
    
    SystemInit();
    
    while(1)
    {
        SystemTask();
    }
}
