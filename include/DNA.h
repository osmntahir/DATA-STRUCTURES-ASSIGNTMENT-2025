#ifndef DNA_H
#define DNA_H

#include "Chromosome.h"
#include <string>

class DNA {
private:
    Chromosome* head;
    Chromosome* tail;
    int size;
public:
    DNA();
    ~DNA();
    void loadFromFile(const std::string& filename);
    void addChromosome(Chromosome* chromosome);
    Chromosome* getChromosomeAt(int index);
    int getSize() const;
    void printChromosomes();
    void printGenes();
    bool findPrintGene(Gene* gene, char firstGene, char& result);
};

#endif
