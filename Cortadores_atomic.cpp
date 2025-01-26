#include <thread>
#include <chrono>
#include <cstdio>
#include <atomic>

// Variables globales
//Creamos las variables atomicas de cortar y truno de olivia(como solo son 2)
//se entiende que si no es turno de olivia sera de barron, si fueran mas los requerimientos
//caambiarian
//El tiempo entre turnos es relevante, si el tiempo es muy pequeno 
//ambos hilos pueden terminar sus turnos tan rapido que uno de los hilos
//empieza su trabajo inmediatamente despues de que otro termine,
//como el cambio de turno es extremdamente rapido
//el hilo que esta empezando  puede completar una iteracion 
//mas antes de que el hilo principal cambie la variable chopping a false.

std::atomic<bool> chopping{true}; 
std::atomic<bool> turn_olivia{true}; 
unsigned int vegetable_count_olivia = 0; // Conteo de Olivia
unsigned int vegetable_count_barron = 0; // Conteo de Barron


void vegetable_chopper_olivia() {
    while (chopping.load()) { 
        if (turn_olivia.load()) { // Solo trabaja si es su turno
            vegetable_count_olivia++;
            turn_olivia.store(false);
			std::this_thread::sleep_for(std::chrono::nanoseconds(50));
        }
    }
}

void vegetable_chopper_barron() {
    while (chopping.load()) { 
        if (!turn_olivia.load()) { 
            vegetable_count_barron++;
            turn_olivia.store(true); // Pasa el turno a Olivia
			std::this_thread::sleep_for(std::chrono::nanoseconds(50));
        }
    }
}

int main() {

    std::thread olivia(vegetable_chopper_olivia);
    std::thread barron(vegetable_chopper_barron);

    printf("Barron and Olivia are chopping vegetables...\n");


    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping.store(false); 

   
    if (olivia.joinable()) olivia.join();
    if (barron.joinable()) barron.join();


    printf("Final count:\n");
    printf("Olivia chopped %u vegetables.\n", vegetable_count_olivia);
    printf("Barron chopped %u vegetables.\n", vegetable_count_barron);

    // Mantener la consola abierta
    printf("Presiona Enter para salir...");
    getchar();

    return 0;
}
