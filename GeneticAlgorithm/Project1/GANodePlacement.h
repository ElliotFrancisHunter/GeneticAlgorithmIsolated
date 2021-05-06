#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <random>

typedef std::pair<int, int> MAP_POS;

struct Chromosome
{
	int mFitnessScore = 0;
	bool bCompeting = false;
	MAP_POS mPositions;
};

class GANodePlacement
{

private:
	
	typedef std::vector<Chromosome> POPULATION;
	POPULATION mMapPopulation;
	POPULATION mParents;

	int mUnfitModifier = -150;
	int mLessFitModifier = -40;
	int mGoodFitnessModifier = 20;
	int mGreatFitnessModifier = 35;
	int mBestFitnessModifier = 50;
	int mGenerationCount = 1;
	int mTotalFitness = 0;

	void GeneratePopulation();
	void TournamentSelection();
	void FitnessFunction();
	void CrossoverParents();
	void Mutate(Chromosome& child);
	int RandomRange(int minVal, int maxVal);

public:

	void RunGeneticAlgorithm();	
};


