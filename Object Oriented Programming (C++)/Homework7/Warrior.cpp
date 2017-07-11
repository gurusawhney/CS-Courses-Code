#include "Warrior.h"
#include "Noble.h"
#include <string>
#include <iostream>

using namespace std;
namespace WarriorCraft {
	//the code correlates with my header file
	Warrior::Warrior(const std::string& n, int w) : name(n), strength(w) {} 
	std::string Warrior::getName() const {
		return name; 
	}
	int Warrior::getStrength() const {
		return strength;
	}
	Noble* Warrior::getNoble() const {
		return nob;
	}
	void Warrior::setName(const std::string& newname) {
		name = newname;
	}
	void Warrior::setStrength(const int newstrength) {
		strength = newstrength;
	}
	void Warrior::setNoble(Noble& noble) {
		nob = &noble;
	}
	void Warrior::runaway() {
		if (nob != nullptr) {
			cout << name << " flees in terror, abandoning his lord, " << nob->getName() << endl;
			for (size_t i = 0; i < nob->getArmy().size(); i++) { //method of removing the warrior from the noble
				if (nob->getArmy()[i]->getName() == name) {
					for (size_t j = i; i < nob->getArmy().size() - 1; j++) { //adjusts the position of all warriors and shortens the length of the vector
						nob->getArmy()[j] = nob->getArmy()[j + 1];
					}
				}
			}
			nob->getArmy().pop_back();
			nob = nullptr; //assigns the noble pointer to null
		}
	}	
}