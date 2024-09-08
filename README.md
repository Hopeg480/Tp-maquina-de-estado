# Control de ilumunacion RGB

## Memoria descriptiva

Mi sistema representa un control de iluminación RGB. El funcionamiento del mismo se basa en un
temporizador, el cual determine cuanto tiempo se mantendrá cada ciclo de iluminación, y un
pulsador con el cual el usuario puede interactuar para poder alternar como desee por los diferentes
ciclos.
Primero se enciende el sistema, encendiendo el Led rojo. Despues de determinado tiempo o si el usuasrio interactua con el pulsador se cambia al siguiente ciclo de color. A cada ciclo se le puede configurar el tiempo de en el cual se mantenga activo.

### Ciclos 
1. Todos los leds se encienden en color rojo.
2. Todos los leds se encienden en color azul.
3. Todos los leds se encienden en color verde.
4. Se realiza una combinacion de colores y su duracion es mayor a los ciclos de unico color.
5. Se realiza una combinacion de colores y su duracion es mayor a los ciclos de unico color.
6. Se realiza una combinacion de colores y su duracion es mayor a los ciclos de unico color.
 
## Esquema

![Esquema maquina de estados](https://github.com/user-attachments/assets/07ec5efb-2aaa-4310-a8d6-fe946eaefea0)

