### Control de ilumunacion RGB

## Memoria descriptiva

Mi sistema representa un control de iluminación RGB. El funcionamiento del mismo se basa en un
temporizador, el cual determine cuanto tiempo se mantendrá cada ciclo de iluminación, y un
pulsador con el cual el usuario puede interactuar para poder alternar como desee por los diferentes
ciclos.
Primero se enciende el sistema, encendiendo el Led rojo y seteando un contador en 0. Despues de determinado tiempo o si el
usuasrio interactua con el pulsador se cambia al siguiente ciclo de color. Entre ciclo y ciclo el
contador suma uno (excepto despues del ultimo ciclo donde el contador vuelve a 0) y a cada ciclo se le puede configurar el tiempo de accion.

## Esquema

![Maquina de estado 1](https://github.com/user-attachments/assets/ca002a67-5676-420e-a162-5925f92ab6d3)
