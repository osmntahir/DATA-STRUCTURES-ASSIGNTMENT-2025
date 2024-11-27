#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "Gene.h"

class Chromosome {
public:
    Gene* head;
    Gene* tail;
    Chromosome* next;

    Chromosome();
    ~Chromosome();
    void addGene(char data);
    Gene* getGeneAt(int index);
    int getGeneCount() const;
    void copyGenes(Gene* start, Gene* end);
};

#endif
