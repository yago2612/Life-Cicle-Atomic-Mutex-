#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex pencil; // pencil indicara quien escribe en consola
bool turn = true; 

void say_hello() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        pencil.lock(); // Bloquear el mutex
        if (turn) {
            std::cout << "Hello!" << std::endl;
            turn = false; // Cambiar el turno al otro hilo
        }
        pencil.unlock(); 
    }
}

void say_goodbye() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        pencil.lock();
        if (!turn) { 
            std::cout << "Goodbye!" << std::endl;
            turn = true; 
        }
        pencil.unlock(); 
    }
}

int main() {
    std::thread t1(say_hello);
    std::thread t2(say_goodbye);

    t1.join();
    t2.join();

    return 0;
}
