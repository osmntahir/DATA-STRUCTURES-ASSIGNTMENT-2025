all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/DNA.cpp -o ./lib/DNA.o	
	g++ -c -I "./include" ./src/Chromosome.cpp -o ./lib/Chromosome.o	
	g++ -c -I "./include" ./src/Gene.cpp -o ./lib/Gene.o	
	g++ -c -I "./include" ./src/Operations.cpp -o ./lib/Operations.o	

bagla:
	g++ ./lib/main.o ./lib/DNA.o ./lib/Chromosome.o ./lib/Gene.o ./lib/Operations.o -o ./bin/program
calistir:
	./bin/program