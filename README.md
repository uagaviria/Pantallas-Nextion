# PANTALLAS NEXTION

## Envio de entero desde boton:
Las pantallas de Nextion tienen varios tamaños desde 2.4 hasta 7 pulgadas y tienen en su interfaz una pantalla táctil a color.
Cuenta con un software especializado para diseñar de manera más fácil una interfaz  para el usuario.
Las pantallas Nextion son una solución diseñada para complementar las necesidades de sus aplicaciones.
El editor de nextion provee una plataforma de desarrollo de software integrado para toda la familia de nextion.
podemos ir a la pagina de descargas donde encontrarar ejemplos y software necesario para trabajar con dichos dispositivos. 
## Mas informacion en: http://www.nextionec.com/descargas.html

Quiero compartir un ejemplo cuyos botones en pantalla envian un dato variable. 



## El programa y la interface:

```cpp
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

}

void b0p1PopCallback(void *ptr)
{ 
    Serial.println();
    recvRetNumber(&valorp1);
    Serial.print ("Variable valor0 pagina 1 = ");
    Serial.print(valorp1);
}

void setup()
{
      nexInit();
    b0.attachPop(b0PopCallback);
    b1.attachPop(b1PopCallback);
    b0p1.attachPop(b0p1PopCallback);
}
void loop()
{
   nexLoop(nex_listen_list);
}       

```

![Aplicacion web Hecha en bootstrap y guardada en progme, del esp32](https://github.com/uagaviria/ESP32_WEBSERVER/blob/master/imagenes/app.jpg) 
![WifiManagerAsync ](https://github.com/uagaviria/ESP32_WEBSERVER/blob/master/imagenes/wifimanager.png)

### Arduinojson y SPIFFS.
- Desafortunadamente desde Atom no esta implementado subir archivos a la flash del ESP32, solo al  ESP8266. Pero desde el entorno de arduino si añadiendo ciertos archivos.
una imagen vale mas que mil palabras. Allí vas a poner los archivos .jar que te voy a dar para que puedas subir lo que desees a la flash.
una vez esten alli vas al entorno de arduino y veras dos nuevas lineas en herramientas. lo veras en la imagen a continuación.
el ESP32FS y el ESP8266FS.
[Link de descarga ](https://github.com/uagaviria/ESP32_WEBSERVER/tree/master/SPIFFS_UPLOAD)


![Subir archivos a la flash](https://raw.githubusercontent.com/uagaviria/ESP32_WEBSERVER/master/imagenes/spiffs.png)

Una vez cumpliendo con estos requerimientos debemos subir el archivo config.json que se encuentra dentro del proyecto en la carpeta data.

### Cómo usar SPIFFS para ESP32 en el IDE Arduino:
Sencillamente se ha de crear una carpeta llamada "data" en la carpeta del Sketch y pulsar el menú "Herramientas" --> "ESP32 Sketch Data Upload". En la barra de estado veremos el progreso de la operación.
Advertencia: ¡Esta operación borra todo el contenido y sube lo que haya en la carpeta data, no conserva los otros archivos si los tiene allí!

```cpp
// Archivo Config.json que deberas subir.
{
  
  "Usuario": "ssid",
  "Contrasena": "password",
  "MqttUsername":"mqttusername",
  "MqttPassword":"mqttpassword",
  "ClientId":"clientid",
  "ConfigPass":"2475"
}  

```

- El programa principal completo se ha subido al repositorio para ser usado libremente.
