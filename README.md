Este repositorio contiene 3 ejemplos de programación en C++ que exploran el uso de hilos (threads),
sincronización de acceso a recursos compartidos y el uso de variables atómicas y mutex para evitar errores 
de concurrencia durante el uso de programacion paralela o concurrente.

Cortador de verduras:
En este ejemplo, dos hilos (Olivia y Barron) trabajan simultáneamente para cortar verduras. Se utilizan 
variables atómicas para controlar el turno de cada hilo y asegurar que ambos no trabajen al mismo tiempo. 
Esto se logra mediante el uso de la variable turn_olivia, que indica si es el turno de Olivia para cortar 
las verduras. Si no es su turno, Barron corta las verduras. La sincronización adecuada garantiza que cada
hilo respete su turno logrando que ambos realicen el mismo numero de vegetales, es decir, logrando que se
distribuya de forma deseada el trabajo.

Calculadora poco eficas:
En este código, se piden dos números a través de dos hilos diferentes. Uno recoge el primer número y el otro
recoge el segundo número. Para evitar que los hilos accedan a los datos simultáneamente, se usan variables 
atómicas, lo que asegura que el valor de las variables no se vea alterado mientras un hilo las está usando. 
Al final, los números se suman y se muestra el resultado. Si trataramos de realizarlo sin variables atomicas 
u otro metodo de control se podrian solapar valores de entrada o de salida creando errores.

Hello and Goodbye:
Este ejemplo muestra cómo dos hilos pueden imprimir mensajes alternos en la consola usando un mutex. Un hilo 
imprime "Hello!" y el otro imprime "Goodbye!". Usando un mutex (pencil), se asegura que solo uno de los hilos
pueda acceder a la consola al mismo tiempo, lo que permite que los mensajes se alternen correctamente sin que 
se solapen. De otra forma se podrian presentar errores de escritura como hello, hello o goodbye, goodbye.
