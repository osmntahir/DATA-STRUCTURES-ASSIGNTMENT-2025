#include "DNA.h"
#include <iostream>
#include <fstream>
#include <sstream>

DNA::DNA() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DNA::~DNA() {
    Chromosome* current = head;
    while (current) {
        Chromosome* nextChromosome = current->next;
        delete current;
        current = nextChromosome;
    }
}

void DNA::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        std::cerr << "Dna.txt file must be inside doc folder" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        Chromosome* chromosome = new Chromosome();
        std::istringstream iss(line);
        std::string geneStr;
        while (iss >> geneStr) {
            if (!geneStr.empty()) {
                char geneData = geneStr[0];
                chromosome->addGene(geneData);
            }
        }
        addChromosome(chromosome);
    }

    file.close();
}

void DNA::addChromosome(Chromosome* chromosome) {
    if (!head) {
        head = chromosome;
        tail = chromosome; 
    } else {
        tail->next = chromosome;
        tail = chromosome; 
    }
    size++;
}

Chromosome* DNA::getChromosomeAt(int index) {
    Chromosome* temp = head;
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

int DNA::getSize() const {
    return size;
}

void DNA::printChromosomes() {
    Chromosome* temp = head;
    int index = 0;
    while (temp) {
        std::cout << index << ": ";
        Gene* gene = temp->head;
        while (gene) {
            std::cout << gene->data << " ";
            gene = gene->next;
        }
        std::cout << std::endl;
        temp = temp->next;
        index++;
    }
}


void DNA::printGenes() {
    Chromosome* cTemp = head;
    while (cTemp) {
        char geneToPrint = cTemp->head->data; // Varsayılan olarak ilk gen
        findPrintGene(cTemp->head, cTemp->head->data, geneToPrint);
        std::cout << geneToPrint << " ";
        cTemp = cTemp->next;
    }
    std::cout << std::endl;
}

bool DNA::findPrintGene(Gene* gene, char firstGene, char& result) {
    if (!gene) {
        return false;
    }
    bool found = findPrintGene(gene->next, firstGene, result);
    if (found) {
        return true;
    }
    if (gene->data < firstGene) {
        result = gene->data;
        return true;
    }
    return false;
}