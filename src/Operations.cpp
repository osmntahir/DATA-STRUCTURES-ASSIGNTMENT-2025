#include "Operations.h"
#include <iostream>
#include <fstream>
#include <sstream>

void performCrossover(DNA* dna) {
    int index1, index2;
    std::cout << "First chromosome line number: ";
    std::cin >> index1;
    std::cout << "Second chromosome line number: ";
    std::cin >> index2;

    Chromosome* c1 = dna->getChromosomeAt(index1);
    Chromosome* c2 = dna->getChromosomeAt(index2);

    if (!c1 || !c2) {
        std::cout << "Invalid chromosome indices!\n";
        return;
    }

    // Create new chromosomes
    Chromosome* newChromosome1 = crossoverChromosomes(c1, c2, true);
    Chromosome* newChromosome2 = crossoverChromosomes(c1, c2, false);

    dna->addChromosome(newChromosome1);
    dna->addChromosome(newChromosome2);

   // std::cout << "Crossover operation completed.\n";
   // dna->printChromosomes();
}

void performMutation(DNA* dna) {
    int cIndex, gIndex;
    std::cout << "Chromosome line number: ";
    std::cin >> cIndex;
    std::cout << "Gene column number: ";
    std::cin >> gIndex;

    Chromosome* chromosome = dna->getChromosomeAt(cIndex);
    if (!chromosome) {
        std::cout << "Invalid chromosome index!\n";
        return;
    }

    Gene* gene = chromosome->getGeneAt(gIndex);
    if (!gene) {
        std::cout << "Invalid gene index!\n";
        return;
    }

    gene->data = 'X';
   // std::cout << "Mutation operation completed.\n";
   // dna->printChromosomes();
}

void performAutomaticOperations(DNA* dna, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        char operation;
        int param1, param2;
        std::istringstream iss(line);
        iss >> operation >> param1 >> param2;
        if (operation == 'C') {
            Chromosome* c1 = dna->getChromosomeAt(param1);
            Chromosome* c2 = dna->getChromosomeAt(param2);

            if (c1 && c2) {
                Chromosome* newChromosome1 = crossoverChromosomes(c1, c2, true);
                Chromosome* newChromosome2 = crossoverChromosomes(c1, c2, false);

                dna->addChromosome(newChromosome1);
                dna->addChromosome(newChromosome2);

                int newIndex1 = dna->getSize() - 2;
                int newIndex2 = dna->getSize() - 1;
                // std::cout << "New chromosomes added: " << newIndex1 << " and " << newIndex2 << std::endl;
            } else {
                // std::cout << "Invalid chromosome indices: " << param1 << ", " << param2 << std::endl;
            }
        } else if (operation == 'M') {
            Chromosome* chromosome = dna->getChromosomeAt(param1);
            if (chromosome) {
                Gene* gene = chromosome->getGeneAt(param2);
                if (gene) {
                    gene->data = 'X';
                } else {
                    std::cout << "Invalid gene index: " << param2 << std::endl;
                }
            } else {
                std::cout << "Invalid chromosome index: " << param1 << std::endl;
            }
        }
    }

    file.close();
   // std::cout << "Automatic operations completed.\n";
   // dna->printChromosomes();
}

Chromosome* crossoverChromosomes(Chromosome* c1, Chromosome* c2, bool useFirstCombination) {
    Chromosome* newChromosome = new Chromosome();

    int size1 = c1->getGeneCount();
    int size2 = c2->getGeneCount();

    int mid1 = size1 / 2;
    int mid2 = size2 / 2;

    bool isOdd1 = size1 % 2 != 0;
    bool isOdd2 = size2 % 2 != 0;

    if (useFirstCombination) {
        // Left part is the left side of c1's midpoint
        Gene* end1 = c1->getGeneAt(mid1);
        newChromosome->copyGenes(c1->head, end1);

        // Right part is the right side of c2's midpoint
        Gene* start2 = c2->getGeneAt(mid2);
        if (isOdd2) {
            start2 = start2->next; 
        }
        newChromosome->copyGenes(start2, nullptr);

    } else {
        // Right part is the right side of c1's midpoint
        Gene* start1 = c1->getGeneAt(mid1);
        if (isOdd1) {
            start1 = start1->next;
        }
        newChromosome->copyGenes(start1, nullptr);

        // Left part is the left side of c2's midpoint
        Gene* end2 = c2->getGeneAt(mid2);
        // No action needed for odd indices here
        newChromosome->copyGenes(c2->head, end2);
    }

    return newChromosome;
}
