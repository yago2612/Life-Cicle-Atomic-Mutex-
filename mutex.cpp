#include <iostream>
#include <thread>
#include <mutex>
#include <cstdio>

std::mutex pencil;  // Mutex para evitar condiciones de carrera
unsigned int garlic_count = 0;

void shopper() {
    for (int i = 0; i < 1000000; i++) {
        pencil.lock();
        garlic_count++;
        pencil.unlock();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);

    barron.join();
    olivia.join();

    printf("We should buy %u garlic.\n", garlic_count);

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
