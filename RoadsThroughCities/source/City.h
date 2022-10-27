#pragma once
#include <string>
#include <map>


using namespace std;

class City {

private:
	string name;
	map<int, std::pair<City*,float>> roads;
	int mapSize{ 0 };
	bool visited{ false };

public:
	City(string nm) : name(nm){}
	bool getVisited() { return visited; }
	string getName() { return name; }
	map<int, std::pair<City*, float >> getRoads() { return roads; }
	int getSize() { return mapSize; }
	void sizeUp() { mapSize++; }
	void checkVisited() { visited = true; }

	void addRoad(std::pair<City*,float> myRoad)
	{
		roads.emplace(std::make_pair(mapSize, myRoad));
		sizeUp();
	}

};