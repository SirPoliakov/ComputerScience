#pragma once
#include "City.h"
#include <vector>
using namespace std;

class Graph {
private:
	vector<City*> region;
	int nbCities;

public:
	Graph(int nbC, vector<City*> rg) : region(rg), nbCities(nbC) {}
	
	void addCity(City* city);
	vector<City*> getRegion() { return region; }

	vector<string> randomJourney(City* departure);

};