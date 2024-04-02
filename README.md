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
