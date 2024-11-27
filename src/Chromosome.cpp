#include "Chromosome.h"

Chromosome::Chromosome() {
    head = nullptr;
    tail = nullptr;
    next = nullptr;
}

Chromosome::~Chromosome() {
    Gene* current = head;
    while (current) {
        Gene* nextGene = current->next;
        delete current;
        current = nextGene;
    }
}

void Chromosome::addGene(char data) {
    Gene* gene = new Gene(data);
    if (!head) {
        head = gene;
        tail = gene; 
    } else {
        tail->next = gene;
        tail = gene; 
    }
}

Gene* Chromosome::getGeneAt(int index) {
    Gene* temp = head;
    int count = 0;
    while (temp) {
        if (count == index) {
            return temp;
        }
        temp = temp->next;
        count++;
    }
    return nullptr;
}

int Chromosome::getGeneCount() const {
    Gene* temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Chromosome::copyGenes(Gene* start, Gene* end) {
    Gene* temp = start;
    while (temp != end && temp != nullptr) {
        addGene(temp->data);
        temp = temp->next;
    }
}
