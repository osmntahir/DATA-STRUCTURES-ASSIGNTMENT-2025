#include <iostream>
#include "DNA.h"
#include "Operations.h"

int main() {
    DNA* dna = new DNA();
    dna->loadFromFile("./doc/dna.txt");

    int choice;
    do {
        std::cout << "\n--- Menu ---\n";
        std::cout << "1- Crossover\n";
        std::cout << "2- Mutation\n";
        std::cout << "3- Automatic Operations\n";
        std::cout << "4- Print Genes\n";
        std::cout << "5- Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                performCrossover(dna);
                break;
            case 2:
                performMutation(dna);
                break;
            case 3:
                performAutomaticOperations(dna, "./doc/Islemler.txt");
                break;
            case 4:
                dna->printGenes();
                break;
            case 5:
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    delete dna;
    return 0;
}
