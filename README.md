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

```
//**** PHILO CODE ****

- Asegúrese de que el código de filo cumpla con los siguientes requisitos y solicite explicaciones.
- Comprueba que haya un hilo por filósofo.
- Comprueba que sólo hay un tenedor por filósofo.
- Compruebe si hay un mutex por bifurcación y si se utiliza para comprobar el valor de la fork y/o cambiarlo.
- Compruebe que las salidas nunca estén mezcladas.
- Comprueba cómo se verifica la muerte de un filósofo y si existe un mutex para evitar que un filósofo muera y empiece a comer al mismo tiempo.

//**** PHILO TESTING ****

- No pruebes con más de 200 filósofos.
- No realice la prueba con time_to_die o time_to_eat o time_to_sleep configurados en valores inferiores a 60 ms.
- Prueba que no supera el INT_MAX.
- Prueba 1 800 200 200. El filósofo no debe comer y debe morir.
- Prueba 5 800 200 200. Ningún filósofo debería morir.
- Prueba 5 800 200 200 7. Ningún filósofo debería morir y la simulación debería detenerse cuando cada filósofo haya comido al menos 7 veces.
- Prueba 4 410 200 200. Ningún filósofo debería morir.
- Prueba 4 310 200 100. Un filósofo debería morir.
- Prueba con 2 filósofos y comprueba los diferentes tiempos: una muerte retrasada más de 10 ms es inaceptable.
- Pruebe con cualquier valor de su elección para verificar todos los requisitos. Asegurarse de que los filósofos mueran en el momento adecuado, que no roben tenedores, etc.

//**** BONUS ****

- Asegúrese de que el código de philo_bonus cumpla con los siguientes requisitos y solicite explicaciones.
- Comprueba que hay un proceso por filósofo y que el proceso principal no es un filósofo.
- Comprobar que no quedan procesos huérfanos al final de la ejecución de este programa.
- Compruebe si hay un único semáforo que represente el número de bifurcaciones.
- Compruebe que la salida esté protegida contra acceso múltiple. Para evitar una visualización codificada.
- Comprueba cómo se verifica la muerte de un filósofo y si existe un semáforo para evitar que un filósofo muera y empiece a comer al mismo tiempo.

//**** BONUS TESTING ****

- No pruebes con más de 200 filósofos.
- No realice la prueba con time_to_die o time_to_eat o time_to_sleep configurados en valores inferiores a 60 ms.
- Prueba 5 800 200 200. Ningún filósofo debería morir.
- Prueba 5 800 200 200 7. Ningún filósofo debería morir y la simulación debería detenerse cuando cada filósofo haya comido al menos 7 veces.
- Prueba 4 410 200 200. Ningún filósofo debería morir.
- Prueba 4 310 200 100. Un filósofo debería morir.
- Prueba con 2 filósofos y comprueba los diferentes tiempos: una muerte retrasada más de 10 ms es inaceptable.
- Pruebe con cualquier valor de su elección para verificar todos los requisitos. Asegurarse de que los filósofos mueran en el momento adecuado, que no roben tenedores, etc.

DEFINICIONES DEL PROYECTO:

1. **usleep**:
   - `usleep` se utiliza para suspender la ejecución del programa durante un período de tiempo especificado.
   - PROTOTIPO: `int usleep(useconds_t microseconds);`
   - `microseconds` es el número de microsegundos que se desea suspender la ejecución del programa.

2. **gettimeofday**:
   - `gettimeofday` se utiliza para obtener la fecha y hora actuales.
   - PROTOTIPO: `int gettimeofday(struct timeval *tv, struct timezone *tz);`
   - `tv` es un puntero a una estructura timeval donde se almacenará la fecha y hora.
   - `tz` es un puntero a una estructura timezone (generalmente no se usa y se pasa como `NULL`).

3. **pthread_create**:
   - `pthread_create` se utiliza para crear un nuevo hilo.
   - PROTOTIPO: `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);`
   - `thread` es un puntero a una variable pthread_t donde se almacenará el identificador del nuevo hilo.
   - `attr` es un puntero a una estructura de atributos del hilo (generalmente se pasa como `NULL` para utilizar los atributos predeterminados).
   - `start_routine` es la función que se ejecutará en el nuevo hilo.
   - `arg` es un puntero al argumento que se pasará a `start_routine`.

4. **pthread_detach**:
   - `pthread_detach` se utiliza para marcar un hilo como desprendido.
   - PROTOTIPO: `int pthread_detach(pthread_t thread);`
   - `thread` es el identificador del hilo que se va a desvincular.

5. **pthread_join**:
    - `pthread_join` se utiliza para esperar a que un hilo se complete.
    - PROTOTIPO: `int pthread_join(pthread_t thread, void **retval);`
    - `thread` es el identificador del hilo que se espera.
    - `retval` es un puntero a un puntero donde se almacenará el valor devuelto por el hilo.

6. **pthread_mutex_init**:
    - `pthread_mutex_init` se utiliza para inicializar un objeto de mutex.
    - PROTOTIPO: `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
    - `mutex` es un puntero a un objeto de mutex que se inicializará.
    - `attr` es un puntero a una estructura de atributos de mutex (generalmente se pasa como `NULL` para utilizar los atributos predeterminados).

7. **pthread_mutex_destroy**:
    - `pthread_mutex_destroy` se utiliza para destruir un objeto de mutex previamente inicializado.
    - PROTOTIPO: `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
    - `mutex` es un puntero al objeto de mutex que se va a destruir.

8. **pthread_mutex_lock**:
    - `pthread_mutex_lock` se utiliza para adquirir un cerrojo de mutex.
    - PROTOTIPO: `int pthread_mutex_lock(pthread_mutex_t *mutex);`
    - `mutex` es un puntero al objeto de mutex que se va a bloquear.

9. **pthread_mutex_unlock**:
    - `pthread_mutex_unlock` se utiliza para liberar un cerrojo de mutex.
    - PROTOTIPO: `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
    - `mutex` es un puntero al objeto de mutex que se va a desbloquear.

Estas son funciones fundamentales en C para realizar operaciones comunes como manipulación de memoria, entrada y salida, operaciones de tiempo, concurrencia, etc.
