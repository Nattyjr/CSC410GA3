#include "Population.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor
Population::Population() : individuals(nullptr), populationSize(0), crossoverPoints(1), mutationRate(0.0), targetGenome(nullptr), imageSize(0), parent1Index(-1), parent2Index(-1) {}

// Destructor
Population::~Population() {
    if (individuals) {
        delete[] individuals;
        individuals = nullptr;
    }
}

// Generate a population with random genomes
void Population::generatePopulation(int populationSize, int geneCount) {
    individuals = new Genome[populationSize];
    this->populationSize = populationSize;
    for (int i = 0; i < populationSize; ++i) {
        individuals[i].allocate(geneCount);
        individuals[i].randomize();
    }
}

// Set the target genome for fitness calculation
void Population::setTargetGenome(const Pixel* target, int imageSize) {
    targetGenome = target;
    this->imageSize = imageSize;
}

// Select parents based on fitness
void Population::selectParents() {
    // To be implemented based on fitness calculation
}

// Set the number of crossover points
void Population::setCrossoverPoints(int crossoverPoints) {
    if (crossoverPoints > 0) 
        this->crossoverPoints = crossoverPoints;
}

// Get the number of crossover points
int Population::getCrossoverPoints() const {
    return crossoverPoints;
}

// Set the mutation rate
void Population::setMutationRate(double mutationRate) {
    this->mutationRate = mutationRate;
}

// Generate a new population using selection and crossover
void Population::generateNewPopulation(int useRoulette) {
    // To be implemented for selection and crossover
}

// Calculate the overall fitness of the population
double Population::calculateOverallFitness() {
    double totalFitness = 0.0;
    for (int i = 0; i < populationSize; ++i) {
        totalFitness += individuals[i].calculateOverallFitness(targetGenome, imageSize);
    }
    return totalFitness / populationSize;
}

// Print the selected parents
void Population::printSelectedParents() {
    if (parent1Index == -1 || parent2Index == -1) {
        cout << "No parents selected yet." << endl;
    } else {
        cout << "Parent 1: ";
        individuals[parent1Index].print();
        cout << "Parent 2: ";
        individuals[parent2Index].print();
    }
}

// Print the entire population
void Population::printPopulation() {
    cout << "Population size: " << populationSize << " | Crossover points: " << crossoverPoints << " | Mutation Rate: " << mutationRate << endl;
    for (int i = 0; i < populationSize; ++i) {
        individuals[i].print();
    }
}
