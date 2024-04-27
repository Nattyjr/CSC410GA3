#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "Genome.h"
#include <cstdlib> 


struct Pixel {
    int red;    // Value for the red component of the pixel
    int green;  // Value for the green component of the pixel
    int blue;   // Value for the blue component of the pixel
};

// Represents a genetic algorithm
class GeneticAlgorithm {
public:
    GeneticAlgorithm(); // Constructor initializes the genetic algorithm with default values
    ~GeneticAlgorithm(); // Destructor cleans up dynamically allocated memory

    void initializePopulation(int popSize, int geneCount); // Initializes the population with random genomes
    void deallocatePopulation(); // Frees the allocated memory for individuals

    void randomizeGenome(Genome &genome); // Randomizes the RGB values for each gene in the genome

    void setMutationRate(double rate); // Sets the mutation rate
    double getMutationRate() const; // Returns the current mutation rate

    void mutateGene(Genome &genome, int index); // Mutates a single gene in the genome
    void mutateGenome(Genome &genome); // Mutates the entire genome based on the mutation rate

    double calculateGeneFitness(const Genome &genome, int index, const Pixel &targetPixel) const; // Calculates fitness of a single gene
    double calculateOverallFitness(const Genome &genome, const Pixel *target, int nPixels) const; // Calculates overall fitness of the genome

    void setPixel(Genome &genome, int index, const Pixel &newPixel); // Sets a new pixel at specified index in the genome
    Pixel getPixel(const Genome &genome, int index) const; // Returns the pixel at specified index in the genome

    void printGenome(const Genome &genome) const; // Prints the genome's information to the console

private:
    Genome* individuals; // Pointer to dynamically allocated array of genomes representing the population
    int populationSize;   // Number of individuals in the population
    int crossoverPoints; // Number of crossover points in crossover operation
    double mutationRate; // Mutation rate
};

#endif // GENETICALGORITHM_H
