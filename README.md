
# Genetic Algorithm Simulation

## **Project Overview**

This project, developed as part of Sakarya University’s 2025 Data Structures 1st assignment, simulates genetic algorithm operations such as crossover and mutation using C++ doubly linked lists. The program reads DNA sequences from a `Dna.txt` file, managing each chromosome as a linked list of genes. Tail pointers are implemented to optimize insertion operations from O(n) to O(1), ensuring efficient handling of large datasets and robust memory management.

## **Project Structure**

```
VY-ODEV/
│
├── src/                # Source files
│   ├── main.cpp
│   ├── DNA.cpp
│   ├── Chromosome.cpp
│   ├── Gene.cpp
│   └── Operations.cpp
│
├── include/            # Header files
│   ├── DNA.h
│   ├── Chromosome.h
│   ├── Gene.h
│   └── Operations.h
│
├── lib/                # Compiled object files (.o)
│
├── bin/                # Executable files
│
├── doc/                # Documentation and reports
│
├── Dna.txt             # Input file containing DNA sequences
├── Islemler.txt        # Command file for automatic operations
├── makefile            # Makefile for building the project
└── README.md           # Project documentation
```

## **Technologies and Methods Used**

- **C++ Programming Language:** Core language for implementation.
- **Doubly Linked Lists:** Utilized for managing genes and chromosomes, allowing bidirectional traversal.
- **Tail Pointer Optimization:** Introduced tail pointers in linked lists to enable O(1) insertion time.
- **Dynamic Memory Management:** Employed `new` and `delete` for dynamic allocation with proper destructors to prevent memory leaks.
- **File Processing:** Implemented reading from `Dna.txt` for DNA sequences and `Islemler.txt` for automatic operations.
- **Command-Line Interface:** Developed a user-friendly menu-driven interface for interacting with the program.

## **Installation and Execution**

### **Requirements**

- **C++ Compiler:** `g++` (GCC) or a similar C++ compiler.
- **Make:** Ensure the `make` tool is installed.
- **Operating System:** Compatible with Windows, Linux, or macOS.

### **Compilation Steps**

1. **Clone or Download the Project:**

   ```bash
   git clone https://github.com/yourusername/VY-ODEV.git
   cd VY-ODEV
   ```

2. **Compile Using Makefile:**

   Navigate to the project directory and run:

   ```bash
   make clean
   make
   ```

   - `make clean`: Removes any previous compilation artifacts.
   - `make`: Compiles the source code and generates the executable in the `bin/program` directory.

3. **Run the Program:**

   ```bash
   ./bin/program
   ```

## **Usage Instructions**

Upon running the program, you will be presented with the following menu:

```
--- Menu ---
1- Crossover
2- Mutation
3- Automatic Operations
4- Print Genes
5- Exit
```

### **1. Crossover**

- **Operation:** Combine two chromosomes to create new ones.
- **Steps:**
  1. Select option `1`.
  2. Enter the row numbers of the two chromosomes (0-based indexing).
  3. The program performs crossover by merging the left half of the first chromosome with the right half of the second chromosome, and vice versa, creating two new chromosomes.
- **Example:**
  ```
  Your choice: 1
  First chromosome row number: 0
  Second chromosome row number: 3
  Crossover operation completed.
  ```

### **2. Mutation**

- **Operation:** Mutate a specific gene within a chromosome.
- **Steps:**
  1. Select option `2`.
  2. Enter the chromosome row number.
  3. Enter the gene column number.
  4. The specified gene is mutated to `X`.
- **Example:**
  ```
  Your choice: 2
  Chromosome row number: 4
  Gene column number: 3
  Mutation operation completed.
  ```

### **3. Automatic Operations**

- **Operation:** Execute a series of predefined operations from `Islemler.txt`.
- **Steps:**
  1. Select option `3`.
  2. The program reads and executes each command in `Islemler.txt`.
- **Example `Islemler.txt`:**
  ```
  C 1 3
  C 0 6
  M 5 1
  ```
- **Execution Output:**
  ```
  New chromosomes added: 6 and 7
  New chromosomes added: 8 and 9
  Automatic operations completed.
  ```

### **4. Print Genes**

- **Operation:** Display specific genes based on defined criteria.
- **Method:** For each chromosome, the program iterates from right to left to find the first gene that is smaller than the first gene of the chromosome. If no such gene exists, the first gene is printed.
- **Example Output:**
  ```
  A D C D A A D A A E
  ```

### **5. Exit**

- **Operation:** Terminate the program.
- **Example:**
  ```
  Your choice: 5
  Exiting the program...
  ```

## **Performance Optimizations**

### **Tail Pointer Implementation**

Initially, adding genes or chromosomes required traversing the entire linked list, resulting in O(n) time complexity per insertion. This was inefficient for large datasets.

**Solution:** Introduced tail pointers in both the `Chromosome` and `DNA` classes. The tail pointer maintains a reference to the last element, allowing new elements to be appended in constant time (O(1)).

**Impact:** Reduced insertion time from O(n) to O(1), significantly improving performance when handling large DNA datasets.

### **Efficient Memory Management**

Implemented destructors in all classes to ensure that dynamically allocated memory is properly freed, preventing memory leaks and ensuring the program remains efficient over extended operations.

---

## **Author**

This project was developed as part of the Sakarya University Data Structures course.

**Author:** Osman Tahir Ozdemir  
**Email:** ozdemirosmantahir@gmail.com

---
