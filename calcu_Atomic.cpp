#include <iostream>
#include <thread>
#include <atomic>
// Usamos variables atomicas para los numeros y el hilo porque los hilos pueden estar trabajando
//al mismo tiempo y si no usamos atomicas pueden surgir errores por acceso simultaneo 
//a esos valores. Osea que uno de los hilos puede cambiar el valor mientras el otro lo esta 
//leyendo y eso genera resultados incorrectos. Las atomicas aseguran que un hilo pueda guardar
//y leer sin que se interfieran.


std::atomic<double> num1(0), num2(0);
std::atomic<bool> first_thread_done(false);

void input_first_number() {
    double value;
    std::cout << "Enter first number: ";
    std::cin >> value;
    num1.store(value);
    first_thread_done.store(true);
}

void input_second_number() {
    while (!first_thread_done.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    double value;
    std::cout << "Enter second number: ";
    std::cin >> value;
    num2.store(value);
}

int main() {
    std::thread thread1(input_first_number);
    std::thread thread2(input_second_number);

    thread1.join();
    thread2.join();

    double result = num1.load() + num2.load();
    std::cout << "The sum is: " << result << std::endl;

    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.ignore();
    std::cin.get();

    return 0;
}
