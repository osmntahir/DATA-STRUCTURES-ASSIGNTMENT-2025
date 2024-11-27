#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "DNA.h"
#include <string>

void performCrossover(DNA* dna);
void performMutation(DNA* dna);
void performAutomaticOperations(DNA* dna, const std::string& filename);
Chromosome* crossoverChromosomes(Chromosome* c1, Chromosome* c2, bool useFirstCombination);

#endif
