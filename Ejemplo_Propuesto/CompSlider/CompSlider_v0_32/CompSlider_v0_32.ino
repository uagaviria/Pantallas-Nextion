#include "Nextion.h" /*Libreria para Pantalla Nexion*/

// pagina 0
NexButton b0 = NexButton(0,4,"b0");
NexButton b1 = NexButton(0,6,"b1");

//pagina 1
NexButton b0p1 = NexButton(1,1,"b0");

NexTouch *nex_listen_list[] =  // si no adiciona el objeto a esta lista no recibe datos
{

    &b0p1,
    &b0,
    &b1,
    NULL
};

uint32_t numeros;
uint32_t valor;
uint32_t valorp1;
char texto[100];

void b0PopCallback(void *ptr)
{ 
    Serial.println();
    recvRetNumber(&numeros);
    Serial.print ("Variable numeros = ");
    Serial.print(numeros);
}
   
void b1PopCallback(void *ptr)
{ 
    Serial.println();
    recvRetNumber(&valor);
    Serial.print ("Variable valor = ");
    Serial.print(valor);
    // Serial.println();
    // texto[recvRetString(texto, 100)] = 0;
    // Serial.print ("Variable texto = ");
    // Serial.print (texto);
}

void b0p1PopCallback(void *ptr)
{ 
    Serial.println();
    recvRetNumber(&valorp1);
    Serial.print ("Variable valor0 pagina 1 = ");
    Serial.print(valorp1);
    // Serial.println();
    // texto[recvRetString(texto, 100)] = 0;
    // Serial.print ("Variable texto = ");
    // Serial.print (texto);
}

void setup()
{
      nexInit();
    b0.attachPop(b0PopCallback);
    b1.attachPop(b1PopCallback);
    b0p1.attachPop(b0p1PopCallback);
//     dbSerialPrintln("setup done");
}
void loop()
{
   nexLoop(nex_listen_list);
}




// /**

// 735/5000
// * @example CompSlider.ino
//   *
//   * @par Cómo usar
//   * Este ejemplo muestra que, cuando se lanza el componente del control deslizante en la pantalla de Nextion,
//   * el valor de texto del componente de texto se cambiará cada vez.
//   *
//   * @author Wu Pengfei (correo electrónico: <pengfei.wu@itead.cc>)
//   * @date 2015/8/11
//   * @updated 2016/12/25 lleva HMI hasta v0.32 para evitar problemas demasiado antiguos
//   * @convert por Patrick Martin, no se hicieron otros cambios
//   * @copyright
//   * Derechos de autor (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \ n
//   * Este programa es software libre; puedes redistribuirlo y / o
//   * modificarlo bajo los términos de la Licencia Pública General de GNU como
//   * publicado por la Free Software Foundation; ya sea la versión 2 de
//   * la Licencia, o (a su elección) cualquier versión posterior.
//  */
 
// #include "Nextion.h"

// NexText t0 = NexText(0, 2, "t0");
// NexSlider h0 = NexSlider(0, 1, "h0");
// NexButton b0  = NexButton(0, 4,  "b0");

// int valor;

// NexTouch *nex_listen_list[] = 
// {
//     &b0,
//     &h0,
//     NULL
// };

// void b0PopCallback(void *ptr);

// void h0PopCallback(void *ptr)
// {
//     uint32_t number = 0;
//     char temp[10] = {0};
    
//     dbSerialPrintln("h0PopCallback");

//     h0.getValue(&number);
//     utoa(number, temp, 10);
//     t0.setText(temp);
// }

// void b0PopCallback(void *ptr)
// {
//     // uint32_t number;
    
//     // dbSerialPrintln("b0PopCallback");

//     // n0.getValue(&number);
//     Serial.print("valor: ");
//     Serial.println(valor);
//     b0.attachPop(b0PopCallback);
    
//    // n0.setValue(number);
// }

// void setup(void)
// {
//     nexInit();
//     h0.attachPop(h0PopCallback);
//     dbSerialPrintln("setup done");
// }

// void loop(void)
// {
//     nexLoop(nex_listen_list);
// }

