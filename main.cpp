#include "Population.h"
#include <iostream>

using namespace std;

int main() {
    // Create an instance of the GeneticAlgorithm class
    GeneticAlgorithm myGeneticAlgorithm;

    // Generate a population of 10 genomes, each with 5 genes
    myGeneticAlgorithm.initializePopulation(10, 5);

    // Create a dummy genome
    Pixel target[5] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}, {0, 255, 255}};
    //myGeneticAlgorithm.setTarget(target, 5);


    cout << "Initial population state:" << endl;
    //myGeneticAlgorithm.printPopulation();

    // Set and demonstrate mutation behaviors
    myGeneticAlgorithm.setMutationRate(0.1); // Set mutation rate to 10%

    // Perform mutation on the population
    myGeneticAlgorithm.mutatePopulation();

    // Print the population after mutation
    cout << "\nAfter mutation:" << endl;
     myGeneticAlgorithm.printPopulation();

    // Calculate fitness
    double fitness = myGeneticAlgorithm.calculateOverallFitness();
    cout << "\nOverall fitness of the population: " << fitness << endl;

    return 0;
}
