#ifndef NOBLE_H
#define NOBLE_H
#include <string>
#include <iostream>
#include <vector>

namespace WarriorCraft { 

	class Warrior;
	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& nob); //this is the overloaded output operator
	public:
		Noble(const std::string& n); //constructor
		std::string getName() const; //gets the name
		std::vector<Warrior*> getArmy(); //gets the army
		int getStrength() const; //gets the strength
		void hire(Warrior& warr); //hires the warrior
		void fire(Warrior& warr); //fires the warrior
		void battle(Noble& opponent); //battles with another Noble
		void adjustStrength(const double& str_ratio); //adjusts the strength after the battle
		void display() const; // displays the Noble
	private:
		std::string name; //Noble's name
		std::vector<Warrior*> army; //Noble's army
	};
}
#endif NOBLE_H
