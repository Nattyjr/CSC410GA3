#include "GeneticAlgorithm.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm() : individuals(nullptr), populationSize(0), crossoverPoints(1), mutationRate(0.0) {
    srand(static_cast<unsigned int>(time(nullptr))); 
}

GeneticAlgorithm::~GeneticAlgorithm() {
    if (individuals) {
        delete[] individuals;
        individuals = nullptr;
    }
}

void GeneticAlgorithm::initializePopulation(int popSize, int geneCount) {
    deallocatePopulation();
    populationSize = popSize;
    individuals = new Genome[populationSize];
    for (int i = 0; i < populationSize; ++i) {
        individuals[i].allocate(geneCount);
        individuals[i].randomize();
    }
}

void GeneticAlgorithm::deallocatePopulation() {
    if (individuals) {
        delete[] individuals;
        individuals = nullptr;
        populationSize = 0;
    }
}

void GeneticAlgorithm::randomizeGenome(Genome &genome) {
    for (int i = 0; i < genome.getGeneCount(); ++i) {
        genome.setGeneRed(i, rand() % 256);
        genome.setGeneGreen(i, rand() % 256);
        genome.setGeneBlue(i, rand() % 256);
    }
}

void GeneticAlgorithm::setMutationRate(double rate) {
    if (rate >= 0.0 && rate <= 1.0)
        mutationRate = rate;
    else
        cout << "Mutation rate must be between 0 and 1." << endl;
}

double GeneticAlgorithm::getMutationRate() const {
    return mutationRate;
}

void GeneticAlgorithm::mutateGene(Genome &genome, int index) {
    if (index >= 0 && index < genome.getGeneCount()) {
        double chance = static_cast<double>(rand()) / RAND_MAX;
        if (chance < mutationRate)
            genome.setGeneRed(index, rand() % 256);
        chance = static_cast<double>(rand()) / RAND_MAX;
        if (chance < mutationRate)
            genome.setGeneGreen(index, rand() % 256);
        chance = static_cast<double>(rand()) / RAND_MAX;
        if (chance < mutationRate)
            genome.setGeneBlue(index, rand() % 256);
    }
}

void GeneticAlgorithm::mutateGenome(Genome &genome) {
    for (int i = 0; i < genome.getGeneCount(); ++i) {
        mutateGene(genome, i);
    }
}

double GeneticAlgorithm::calculateGeneFitness(const Genome &genome, int index, const Pixel &targetPixel) const {
    if (index < 0 || index >= genome.getGeneCount()) return -1.0;
    double diff = abs(genome.getGeneRed(index) - targetPixel.red) + abs(genome.getGeneGreen(index) - targetPixel.green) + abs(genome.getGeneBlue(index) - targetPixel.blue);
    return diff / (3.0 * 256.0);
}

double GeneticAlgorithm::calculateOverallFitness(const Genome &genome, const Pixel *target, int nPixels) const {
    if (nPixels != genome.getGeneCount()) return -1.0;
    double totalFitness = 0.0;
    for (int i = 0; i < genome.getGeneCount(); ++i) {
        totalFitness += calculateGeneFitness(genome, i, target[i]);
    }
    return totalFitness / genome.getGeneCount();
}

void GeneticAlgorithm::setPixel(Genome &genome, int index, const Pixel &newPixel) {
    if (index >= 0 && index < genome.getGeneCount())
        genome.setGene(index, newPixel);
}

Pixel GeneticAlgorithm::getPixel(const Genome &genome, int index) const {
    if (index >= 0 && index < genome.getGeneCount())
        return genome.getGene(index);
    return { -1, -1, -1 }; // Invalid index
}

void GeneticAlgorithm::printGenome(const Genome &genome) const {
    cout << "GENOME: " << genome.getGeneCount() << " genes";
    for (int i = 0; i < genome.getGeneCount(); ++i) {
        cout << " (" << genome.getGeneRed(i) << "," << genome.getGeneGreen(i) << "," << genome.getGeneBlue(i) << ")";
    }
    cout << endl;
}
