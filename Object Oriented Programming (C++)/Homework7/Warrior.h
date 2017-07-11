#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include <iostream>

namespace WarriorCraft {

	class Noble;
	class Warrior {
	public:
		Warrior (const std::string& n, int w); //constructor 
		std::string getName() const; //gets the name
		int getStrength() const; //gets the strength
		Noble* getNoble() const; //gets the noble
		void setName(const std::string& newname); //sets the name
		void setStrength(const int newstrength); //sets the strength
		void setNoble(Noble& nob); //assigns it to a noble
		void runaway(); //when the warrior runs away
	private:
		std::string name;
		int strength;
		Noble* nob;
	};
}
#endif WARRIOR_H
