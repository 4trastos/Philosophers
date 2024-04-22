# Uso de Hilos y Mutex en C

Este repositorio contiene un ejemplo básico de cómo utilizar hilos y mutex en un programa escrito en C. El código demuestra cómo implementar hilos para realizar operaciones concurrentes y cómo utilizar mutex para sincronizar el acceso a recursos compartidos entre los hilos.

## Código

El código consiste en dos funciones de rutina para los hilos, `thread1_routine` y `thread2_routine`, que incrementan y decrementan respectivamente una variable compartida llamada `count`. Ambas funciones utilizan un mutex para proteger el acceso a `count` y garantizar que solo un hilo pueda modificarla a la vez, evitando así condiciones de carrera.
