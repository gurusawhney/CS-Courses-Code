//Homework2

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Weapon { //this structure organizes the weapons
public:

	Weapon() {}
	Weapon(string n, int m) : name(n), strength(m) {}

	int getWeaponStrength() const {
		return strength;
	}
	string getWeaponName() const {
		return name;
	}
	void setWeaponStrength(const int& newstrength) {
		strength = newstrength;
	}
	void setWeaponName(const string& newname) {
		name = newname;
	}

private:
	string name;
	int strength;
};

class Warrior { //this structure organizes the weapons
public:

	Warrior() {}
	Warrior(string n, Weapon w) : name(n), weap(w) {}

	string getName() const {
		return name;
	}
	string getWeaponName() const {
		return weap.getWeaponName();
	}
	int getWeaponStrength() const {
		return weap.getWeaponStrength();
	}
	void setName(const string& newname) {
		name = newname;
	}
	void setWeaponStrength(const int& newstrength) {
		weap.setWeaponStrength(newstrength);
	}
	void setWeaponName(const string& newname) {
		weap.setWeaponName(newname);
	}

private:
	string name;
	Weapon weap;
};



void displaywarriors(vector<Warrior>& vecofwarriors) { //this function displays the warriors stats
	cout << "There are: " << vecofwarriors.size() << " warriors"  << endl; //prints out the number of warriors
	for (size_t i = 0; i < vecofwarriors.size(); i++) {
		cout << "Warrior: "<<vecofwarriors[i].getName() << ", weapon: "<< vecofwarriors[i].getWeaponName() << ", " << vecofwarriors[i].getWeaponStrength() << endl; //prints out name and strength
	}
}

void battle(vector<Warrior>& vecofwarriors, const string& name1, const string& name2) { //this function executes the battle
	int strength1;
	int strength2;
	for (Warrior& warr : vecofwarriors) { //this function assigns the variables
		if (warr.getName() == name1 ) {
			strength1 = warr.getWeaponStrength();
		}
		else if (warr.getName() == name2) {
			strength2 = warr.getWeaponStrength();
		}
	}
	if (strength1 == strength2) { //this is when both warriors have the same strength
		strength1 = 0;
		strength2 = 0;
		cout << "Mutual Annihalation: " << name1 << " and " << name2 << " died at eachother's hands" <<endl;
	}
	else if ( strength1 > strength2) { //this is when name1 wins
		strength1 = strength1 - strength2;
		strength2 = 0;
		cout << name1 << " defeats " << name2 << endl;
	}
	else if (strength2 > strength1) { //this is when name2 wins
		strength2 = strength2 - strength1;
		strength1 = 0;
		cout << name2 << " defeats " << name1 << endl;
	}
	
	for (Warrior& warr : vecofwarriors) { //this reassigns the new strength values to the vector
		if (warr.getName() == name1) {
			warr.setWeaponStrength(strength1); //setter
		}
		else if (warr.getName() == name2) {
			warr.setWeaponStrength(strength2);
		}
	}
}

bool isdead(vector<Warrior>& vecofwarriors, const string& name) { //this function checks if the warriors are dead
	for (size_t i = 0; i < vecofwarriors.size(); i++) {
		if (vecofwarriors[i].getName() == name) {
			if (vecofwarriors[i].getWeaponStrength() == 0) {
				return true;
			}
			return false;
		}
	} 
}


int main() {

	ifstream ifs("warriors.txt");
	if (!ifs) {
		cout << "couldn't open file...\n";
	}  //this checks to see if the file is open

	vector<Warrior> vecofwarriors;
	string current;
	while (ifs >> current) {
		if (current == "Warrior") { //this reads all lines that say "Warrior" first
			string name;
			int strength;
			string weaponname;
			ifs >> name >> weaponname >> strength;
			Warrior warr;
			warr.setName(name);
			warr.setWeaponName(weaponname);
			warr.setWeaponStrength(strength);
			vecofwarriors.push_back(warr); //this stores all the warriors in a vector
		}
		else if(current == "Status") {
			displaywarriors(vecofwarriors); //the first display using the display function
		}
		else if (current == "Battle") { //this reads all lines that say "Battle" first
			string name1;
			string name2;
			ifs >> name1 >> name2;
			cout << name1 << " battles " << name2 << endl;
			//the following conditions check if anyone is dead yet by using my isdead bool function
			if ((isdead(vecofwarriors, name1) == true) && (isdead(vecofwarriors, name2) == true)) {
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
			}
			else if (isdead(vecofwarriors, name1) == true) {
				cout << "He's dead, " << name2 << endl;
			}
			else if (isdead(vecofwarriors, name2) == true) {
				cout << "He's dead, " << name1 << endl;
			}
			else { //this executes the battle function if no one is dead
				battle(vecofwarriors, name1, name2);
			}
		}
	}
}
