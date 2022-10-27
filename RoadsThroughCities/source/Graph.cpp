#include "Graph.h"
#include <random>
#include <iostream>
void Graph::addCity(City* city)
{
	getRegion().emplace_back(city);
}

vector<string> Graph::randomJourney(City* departure)
{

	City* temp{ departure }; City* temp2{ departure }; int nbRoads = 0; vector<string> path;
	while (temp->getName() != "Nantes")
	{
		path.emplace_back(temp->getName());
		nbRoads = static_cast<int>(temp->getRoads().size());
		temp->checkVisited();

		//--------------------- Random function stuff: ---------------------------\\

		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, nbRoads);

		//-------------------------------------------------------------------------\\

		unsigned int index{ dist(rng) };
		temp2 = temp2->getRoads()[index].first;
		
		if (!temp2->getVisited()) temp = temp2;
		else if(index < temp->getSize()-1) temp = temp->getRoads()[index+1].first;
		else temp = temp->getRoads()[index-1].first;
	}

	path.emplace_back(temp->getName()); return path;
	
}