#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
namespace WarriorCraft {
	//the code correlates with my header
	ostream& operator<<(ostream& os, const Noble& nob) {
		nob.display();
		return os;
	}
	Noble::Noble(const std::string& n) : name(n) {}
	std::string Noble::getName() const {
		return name;
	}
	std::vector<Warrior*> Noble::getArmy() {
		return army;
	}
	int Noble::getStrength() const {
		int total = 0;
		for (Warrior* warr : army) {
			total += warr->getStrength();
		}
		return total;
	}
	void Noble::hire(Warrior& warr) {
		army.push_back(&warr);
		warr.setNoble(*this);
	}
	void Noble::fire(Warrior& warr) {
		for (size_t i = 0; i < army.size(); i++) { //method of removing the warrior
			if (army[i] == &warr) {
				for (size_t j = i; i < army.size() - 1; j++) { //adjusts the position of all warriors and shortens the length of the vector
					army[j] = army[j + 1];
				}
			}
		}
		army.pop_back();
		cout << warr.getName() << " you're fired! - " << name << endl;
	}
	void Noble::battle(Noble& opponent) {
		cout << name << " battles " << opponent.getName() << endl;
		if (getStrength() == 0 && opponent.getStrength() == 0) {//executes if both are dead
			cout << "Oh,NO! They're both dead! Yuck!" << endl;
		}
		if (getStrength() == opponent.getStrength() && getStrength() != 0 && opponent.getStrength() != 0) {//checks to see if neither are dead and have same strength
			cout << "Mutual Annihalation: " << name << " and " << opponent.getName() << " die at each other's hands" << endl;
			adjustStrength(0);
			opponent.adjustStrength(0);
		}
		else if (getStrength() > opponent.getStrength() && opponent.getStrength() != 0) {//checks if noble is stronger than opponent
			cout << name << " defeats " << opponent.getName() << endl;
			adjustStrength(opponent.getStrength() / getStrength());
			opponent.adjustStrength(0);
		}
		else if (getStrength() > opponent.getStrength() && opponent.getStrength() == 0) {//checks if opponent is dead
			cout << "He's dead, " << name << endl;
		}
		else if (getStrength() < opponent.getStrength() && getStrength() != 0) {//checks if opponent is stronger than noble
			cout << opponent.getName() << " defeats " << name << endl;
			adjustStrength(0);
			opponent.adjustStrength(getStrength() / opponent.getStrength());
		}
		else if (getStrength() < opponent.getStrength() && getStrength() == 0) {//checks if noble is dead
			cout << "He's dead, " << opponent.getName() << endl;
		}
	}
	void Noble::adjustStrength(const double& str_ratio) {
		for (size_t i = 0; i < army.size(); i++) {
			if (str_ratio == 0) { //changes the strengths for the dead warriors
				army[i]->setStrength(0);
			}
			else {
				army[i]->setStrength(army[i]->getStrength() * str_ratio);//adjusts strength of living warriors
			}
		}
	}
	void Noble::display() const {
		cout << name << " has an army of " << army.size() << endl; //prints out the number of warriors
		for (size_t i = 0; i < army.size(); i++) {
			cout << "\t" << army[i]->getName() << ": " << army[i]->getStrength() << endl; //prints out name and strength
		}
	}
}