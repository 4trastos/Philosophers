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

1. **memset**:
   - `memset` se utiliza para establecer un bloque de memoria con un valor específico.
   - PROTOTIPO: `void *memset(void *ptr, int value, size_t num);`
   - `ptr` es un puntero al bloque de memoria que se va a llenar.
   - `value` es el valor que se va a establecer.
   - `num` es el número de bytes que se establecerán en el bloque de memoria.

2. **printf**:
   - `printf` se utiliza para imprimir texto formateado en la consola o en otro flujo de salida.
   - PROTOTIPO: `int printf(const char *format, ...);`
   - `format` es una cadena de formato que especifica cómo se formatearán los datos que se imprimen.
   - Los puntos suspensivos (`...`) indican que `printf` puede tomar un número variable de argumentos, que corresponden a los valores que se formatearán según la cadena de formato.

3. **malloc**:
   - `malloc` se utiliza para asignar memoria dinámicamente en el montón.
   - PROTOTIPO: `void *malloc(size_t size);`
   - `size` es el tamaño en bytes de la memoria que se desea asignar.
   - Devuelve un puntero al bloque de memoria asignado, o `NULL` si la asignación falla.

4. **free**:
   - `free` se utiliza para liberar la memoria previamente asignada dinámicamente con `malloc`.
   - PROTOTIPO: `void free(void *ptr);`
   - `ptr` es un puntero al bloque de memoria que se va a liberar.

5. **write**:
   - `write` se utiliza para escribir datos en un descriptor de archivo.
   - PROTOTIPO: `ssize_t write(int fd, const void *buf, size_t count);`
   - `fd` es el descriptor de archivo en el que se va a escribir.
   - `buf` es el búfer que contiene los datos que se van a escribir.
   - `count` es el número de bytes que se van a escribir.
   - Devuelve el número de bytes escritos o -1 en caso de error.

6. **usleep**:
   - `usleep` se utiliza para suspender la ejecución del programa durante un período de tiempo especificado.
   - PROTOTIPO: `int usleep(useconds_t microseconds);`
   - `microseconds` es el número de microsegundos que se desea suspender la ejecución del programa.

7. **gettimeofday**:
   - `gettimeofday` se utiliza para obtener la fecha y hora actuales.
   - PROTOTIPO: `int gettimeofday(struct timeval *tv, struct timezone *tz);`
   - `tv` es un puntero a una estructura timeval donde se almacenará la fecha y hora.
   - `tz` es un puntero a una estructura timezone (generalmente no se usa y se pasa como `NULL`).

8. **pthread_create**:
   - `pthread_create` se utiliza para crear un nuevo hilo.
   - PROTOTIPO: `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);`
   - `thread` es un puntero a una variable pthread_t donde se almacenará el identificador del nuevo hilo.
   - `attr` es un puntero a una estructura de atributos del hilo (generalmente se pasa como `NULL` para utilizar los atributos predeterminados).
   - `start_routine` es la función que se ejecutará en el nuevo hilo.
   - `arg` es un puntero al argumento que se pasará a `start_routine`.

9. **pthread_detach**:
   - `pthread_detach` se utiliza para marcar un hilo como desprendido.
   - PROTOTIPO: `int pthread_detach(pthread_t thread);`
   - `thread` es el identificador del hilo que se va a desvincular.

10. **pthread_join**:
    - `pthread_join` se utiliza para esperar a que un hilo se complete.
    - PROTOTIPO: `int pthread_join(pthread_t thread, void **retval);`
    - `thread` es el identificador del hilo que se espera.
    - `retval` es un puntero a un puntero donde se almacenará el valor devuelto por el hilo.

11. **pthread_mutex_init**:
    - `pthread_mutex_init` se utiliza para inicializar un objeto de mutex.
    - PROTOTIPO: `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
    - `mutex` es un puntero a un objeto de mutex que se inicializará.
    - `attr` es un puntero a una estructura de atributos de mutex (generalmente se pasa como `NULL` para utilizar los atributos predeterminados).

12. **pthread_mutex_destroy**:
    - `pthread_mutex_destroy` se utiliza para destruir un objeto de mutex previamente inicializado.
    - PROTOTIPO: `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
    - `mutex` es un puntero al objeto de mutex que se va a destruir.

13. **pthread_mutex_lock**:
    - `pthread_mutex_lock` se utiliza para adquirir un cerrojo de mutex.
    - PROTOTIPO: `int pthread_mutex_lock(pthread_mutex_t *mutex);`
    - `mutex` es un puntero al objeto de mutex que se va a bloquear.

14. **pthread_mutex_unlock**:
    - `pthread_mutex_unlock` se utiliza para liberar un cerrojo de mutex.
    - PROTOTIPO: `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
    - `mutex` es un puntero al objeto de mutex que se va a desbloquear.

Estas son funciones fundamentales en C para realizar operaciones comunes como manipulación de memoria, entrada y salida, operaciones de tiempo, concurrencia, etc.
