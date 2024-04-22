# Uso de Hilos y Mutex en C

Este repositorio contiene un ejemplo básico de cómo utilizar hilos y mutex en un programa escrito en C dentro del directorio `test`. El código demuestra cómo implementar hilos para realizar operaciones concurrentes y cómo utilizar mutex para sincronizar el acceso a recursos compartidos entre los hilos.

## Código

El código consiste en dos funciones de rutina para los hilos, `thread1_routine` y `thread2_routine`, que incrementan y decrementan respectivamente una variable compartida llamada `count`. Ambas funciones utilizan un mutex para proteger el acceso a `count` y garantizar que solo un hilo pueda modificarla a la vez, evitando así condiciones de carrera.

### Pruebas

Para demostrar que sudece si NO utilizamos la función mutex y varios hilos acceden a la misma variable, tienes que comentar `pthread_mutex_lock(&mutex)` y `pthread_mutex_unlock(&mutex)`.
La explicación porque esto sucede la encontrarás creando un archico en ensamblador ejecuntando con `-S`.


#### Compilación y Ejecución

Para compilar el código, simplemente ejecuta el comando `gcc` seguido del nombre del archivo de código fuente:

```bash
gcc -o threads_mutex threads_mutex.c -lpthread
