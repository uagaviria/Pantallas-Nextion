/**
 * @example CompNumber.ino
 *
 * @par How to Use
 * This example shows that ,when the "+" component on the Nextion screen is released,
 * the value of number component will plus 1,when the "-" component released ,the value of 
 * number component will minus 1 every time.
 *
 * @author  huang xianming (email:<xianming.huang@itead.cc>)
 * @date    2015/11/10
 * @updated 2016/12/25 bring HMI up to v0.32 to avoid too old issues
 * @convert by Patrick Martin, no other changes made
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "Nextion.h"

void n0PopCallback(void *ptr);
void b0PopCallback(void *ptr);
void b1PopCallback(void *ptr);

/*
 * Declare a number object [page id:0,component id:3, component name: "n0"]. 
 */
NexNumber n0 = NexNumber(0, 12, "n1");

/*
 * Declare a button object [page id:0,component id:1, component name: "b0"]. 
 */
NexButton b0 = NexButton(0, 1, "b0");

/*
 * Declare a button object [page id:0,component id:2, component name: "b1"]. 
 */
NexButton b1 = NexButton(0, 2, "b1");

char buffer[100] = {0};

/*
 * Register object n0, b0, b1, to the touch event list.  
 */
NexTouch *nex_listen_list[] = 
{
    &n0,
    &b0,
    &b1,
    NULL
};

/*
 * number component pop callback function. 
 */
void n0PopCallback(void *ptr)
{
    dbSerialPrintln("n0PopCallback");
    n0.setValue(50);
}

/*
  * Función de devolución de llamada del componente Button0.
  * En este ejemplo, el valor del componente numérico será más uno cada vez que se suelte el botón0.
 */
void b0PopCallback(void *ptr)
{
    uint32_t number;
    
    dbSerialPrintln("b0PopCallback");

    n0.getValue(&number);
    
    number += 1;
    
    n0.setValue(number);
}

/*
  * Función de devolución de llamada pop del componente Button1.
  * En este ejemplo, el valor del componente numérico será menos uno cada vez que se suelte el botón1.
 */
void b1PopCallback(void *ptr)
{
     uint32_t number;
    
    dbSerialPrintln("b1PopCallback");

    n0.getValue(&number);
    
    number -= 1;
    
    n0.setValue(number);
}

void setup(void)
{
    /* Establezca la velocidad en baudios que es para la depuración y comuníquese con la pantalla de Nextion. */
    nexInit();

    /* Registre la función de devolución de llamada del evento pop del componente numérico actual. */
    n0.attachPop(n0PopCallback);

    /* Registre la función de devolución de llamada del evento pop del componente button0 actual. */
    b0.attachPop(b0PopCallback);

    /* Registre la función de devolución de llamada del evento pop del componente button1 actual. */
    b1.attachPop(b1PopCallback);

    dbSerialPrintln("setup done");
}

void loop(void)
{
    /*
      * Cuando ocurre un evento pop o push cada vez,
      * se le pedirá el componente correspondiente [ID de la página derecha y el ID del componente] en la lista de eventos táctiles.
     */
    nexLoop(nex_listen_list);
}


