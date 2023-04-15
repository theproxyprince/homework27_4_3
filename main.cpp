#include <iostream>
#include "Manager.h"

int main() {
    bool theEnd = false;
    int command;
    int commandQuantity, worksQuantity, commandBusy = 0;
    std::cout << "Enter the command quantity: " ;
    std::cin >> commandQuantity;
    Manager* manager = new Manager[commandQuantity];

    for (int i = 0; i < commandQuantity; ++i) {
        std::cout << "Enter the workers quantity in command #" << i+1 << ": ";
        std::cin >> worksQuantity;
        manager[i].SetCountWorkers(worksQuantity);
    }

    do {
        std::cout << "Enter command: ";
        std::cin >> command;
        for (int i = 0; i < commandQuantity; ++i) {
            if (!manager[i].SetTaskToWorkers(command)) {
                commandBusy++;
            }
            std::cout << "Manager #" << manager[i].GetManagerNumber() << " has " <<
                manager[i].GetFreeWorkers() << " free workers" << std::endl;
        }

        if (commandBusy == (commandQuantity - 1)) {
            theEnd = true;
        }

    } while (!theEnd);

    return 0;
}
