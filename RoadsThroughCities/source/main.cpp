
#include "City.h"
#include "Graph.h"
#include <iostream>

int main()
{
    City nantes = City("NANTES");
    City paris = City("Paris");
    City lyon = City("Lyon");
    City montpellier = City("Montpellier");
    City toulouse = City("Toulouse");

    nantes.addRoad(std::make_pair(&paris, 1.0f));
    nantes.addRoad(std::make_pair(&toulouse, 1.0f));
    nantes.addRoad(std::make_pair(&lyon, 3.0f));
    std::cout << "Nantes roads size : " << static_cast<int>(nantes.getRoads().size()) << std::endl;
    paris.addRoad(std::make_pair(&nantes, 1.0f));
    paris.addRoad(std::make_pair(&lyon, 1.0f));
    paris.addRoad(std::make_pair(&toulouse, 3.0f));

    toulouse.addRoad(std::make_pair(&nantes, 1.0f));
    toulouse.addRoad(std::make_pair(&lyon, 1.0f));
    toulouse.addRoad(std::make_pair(&paris, 3.0f));
    toulouse.addRoad(std::make_pair(&montpellier, 2.0f));

    lyon.addRoad(std::make_pair(&paris, 1.0f));
    lyon.addRoad(std::make_pair(&toulouse, 1.0f));
    lyon.addRoad(std::make_pair(&nantes, 3.0f));
    lyon.addRoad(std::make_pair(&montpellier, 2.0f));

    vector<City*> rg = { &nantes,&paris,&lyon,&toulouse,&montpellier };

    Graph france = Graph(static_cast<int>(rg.size()), rg);

    vector<string> path = france.randomJourney(&nantes);

    for (auto ite = path.begin(); ite < path.end(); ite++)
    {
        std::cout << "le che est : "<< std::endl;
        std::cout << *ite << std::endl;
    }

    return 0;
}

