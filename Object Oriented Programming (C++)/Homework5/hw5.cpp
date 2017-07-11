//Homework 5

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Warrior { //this structure organizes the weapons
public:
	Warrior() {}
	Warrior(string n, int w) : name(n), strength(w) {}

	string getName() const { //returns the name
		return name;
	}
	int getStrength() const { //returns the strength
		return strength;
	}
	void setName(const string& newname) { //changes the name
		name = newname;
	}
	void setStrength(const int& newstrength) { //changes the strength
		strength = newstrength;
	}
private:
	string name;
	int strength;
};

class Noble { //this organizes the noble class
public:
	Noble() {}
	Noble(const string& n) : name(n) {} 
	string getName() const { //returns the name
		return name;
	}
	vector<Warrior*> getArmy() const { //returns the army
		return army;
	}
	int getStrength() { //the strength of the noble consolidates the strength from all its warriors
		int total = 0;
		for (Warrior* warr : army) {
			total += warr->getStrength();
		}
		return total;
	}
	void hire(Warrior*& warr) { //adds a warrior
		army.push_back(warr);
	}
	void fire(Warrior*& warr) {
		for (size_t i = 0; i < army.size(); i++) { //adjusts the position of all warriors and shortens the length of the vector
			if (army[i]->getName() == warr->getName()) {
				for (size_t j = i; i < army.size() - 1; j++) {
					army[j] = army[j + 1];
				}
			}
		}
		army.pop_back();
		cout << "You don't work for me anymore " << warr->getName() << "! -- " << name << endl;
	}
	void display() const { //this function displays the warriors stats
		cout << name << " has an army of " << army.size() << endl; //prints out the number of warriors
		for (size_t i = 0; i < army.size(); i++) {
			cout << "\t" << army[i]->getName() << ": " << army[i]->getStrength() << endl; //prints out name and strength
		}
	}
	void battle(Noble*& opponent) { //this function executes the battle
		cout << name << " battles " << opponent->getName() << endl;
		if (getStrength() == opponent->getStrength() && getStrength() != 0 && opponent->getStrength() != 0) {//checks to see if neither are dead and have same strength
			cout << "Mutual Annihalation: " << name << " and " << opponent->getName() << " die at each other's hands" << endl;
			adjustStrength(0);
			opponent->adjustStrength(0);
		}
		else if (getStrength() == 0 && opponent->getStrength() == 0) {//executes if both are dead
			cout << "Oh,NO! They're both dead! Yuck!" << endl;
		}
		else if (getStrength() > opponent->getStrength() && opponent->getStrength() != 0) {//checks if noble is stronger than opponent
			cout << name << " defeats " << opponent->getName() << endl;
			adjustStrength(opponent->getStrength() / getStrength());
			opponent->adjustStrength(0);
		}
		else if (getStrength() > opponent->getStrength() && opponent->getStrength() == 0) {//checks if opponent is dead
			cout << "He's dead, " << name << endl;
		}
		else if (getStrength() < opponent->getStrength() && getStrength() != 0) {//checks if opponent is stronger than noble
			cout << opponent->getName() << " defeats " << name << endl;
			adjustStrength(0);
			opponent->adjustStrength(getStrength() / opponent->getStrength());
		}
		else if (getStrength() < opponent->getStrength() && getStrength() == 0) {//checks if noble is dead
			cout << "He's dead, " << opponent->getName() << endl;
		}
	}
	void adjustStrength(const double& str_ratio) {//once the battle takes place this fixes the strengths of the armies
		for (size_t i = 0; i < army.size(); i++) {
			if (str_ratio == 0) { //changes the strengths for the dead warriors
				army[i]->setStrength(0);
			}
			else {
				army[i]->setStrength(army[i]->getStrength() * str_ratio);//adjusts strength of living warriors
			}
		}
	}
private:
	string name;
	vector<Warrior*> army;
};

void display(const vector<Noble*>& Nobles, const vector<Warrior*>& Warriors) {
	
	cout << "Status\n" << "=====\n" << "Nobles:" << endl;
	if (Nobles.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (Noble* nob : Nobles) {
			nob->display();
		}
	}
	cout << "Unemployed Warriors: " << endl;
	if (Warriors.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (Warrior* warr : Warriors) {
			cout << warr->getName() << ": " << warr->getStrength() << endl;
		}
	}
}

int main() {

	vector<Noble*> vecOfNobles;
	vector<Warrior*> unhiredWarriors;
	ifstream ifs("nobleWarriors.txt");
	if (!ifs) {
		cout << "couldn't open file...\n";
	}  //this checks to see if the file is open

	string current;
	while (ifs >> current) {
		if (current == "Noble") {
			string name;
			ifs >> name;
			Noble* nbptr = new Noble(name);//makes a pointer
			if (vecOfNobles.size() > 0) {
				for (size_t i = 0; i < vecOfNobles.size(); i++) {
					if (nbptr->getName() == vecOfNobles[i]->getName()) {
						cout << "The noble already exists" << endl;
						break;
					}
					else {
						vecOfNobles.push_back(nbptr);
						break;
					}
				}
			}
			else {
				vecOfNobles.push_back(nbptr);
			}
		}
		else if (current == "Warrior") { //this reads all lines that say "Warrior" first
			string name;
			int strength;
			ifs >> name >> strength;
			Warrior* wrptr = new Warrior(name, strength); //makes a pointer
			if (unhiredWarriors.size() > 0) {
				for (size_t j = 0; j < unhiredWarriors.size(); j++) {
					if (wrptr->getName() == unhiredWarriors[j]->getName()) {
						cout << "The warrior already exists" << endl;
						break;
					}
					else {
						unhiredWarriors.push_back(wrptr);
						break;
					}
				}
			}
			else {
				unhiredWarriors.push_back(wrptr);
			}
		}
		else if (current == "Hire") {
			string noblename;
			string warriorname;
			Noble* nob = nullptr;
			Warrior* warr = nullptr;
			ifs >> noblename >> warriorname;
			for (size_t i = 0; i < vecOfNobles.size(); i++) {
				if (noblename == vecOfNobles[i]->getName()) {
					nob = vecOfNobles[i]; //identifies the noble
					break;
				}
			}
			for (size_t j = 0; j < unhiredWarriors.size(); j++) {
				if (warriorname == unhiredWarriors[j]->getName()) {
					warr = unhiredWarriors[j]; //identifies the warrior
					break;
				}
			}
			nob->hire(warr); //hire function
			if (unhiredWarriors.size() > 1) { //removes warrior from unemployed vector
				for (size_t i = 0; i < unhiredWarriors.size(); i++) { //adjusts the position of all warriors and shortens the length of the vector
					if (warr->getName() == unhiredWarriors[i]->getName()) {
							unhiredWarriors[i] = unhiredWarriors[unhiredWarriors.size()-1];
							unhiredWarriors.pop_back();
							break;
					}
				}
			}
			else if (unhiredWarriors.size() == 1) {
				unhiredWarriors.pop_back();
			}
		}
		else if (current == "Fire") {
			string noblename;
			string warriorname;
			Noble* nob = nullptr;
			Warrior* warr = nullptr;
			ifs >> noblename >> warriorname;
			for (size_t i = 0; i < vecOfNobles.size(); i++) {
				if (noblename == vecOfNobles[i]->getName()) {
					nob = vecOfNobles[i]; //identifies the noble
					break;
				}
			}
			for (size_t j = 0; j < nob->getArmy().size(); j++) {
				if (warriorname == nob->getArmy()[j]->getName()) {
					warr = nob->getArmy()[j]; //identifies the warrior
					break;
				}
			}
			if (nob == nullptr) {
				cout << "The noble doesn't exist" << endl;
			}
			if (warr == nullptr) {
				cout << "The warrior doesn't exist" << endl;
			}
			if (nob != nullptr && warr != nullptr) {
				nob->fire(warr); //fire function
				unhiredWarriors.push_back(warr); //adds warrior back to unemployed warrior vecotr
			}
		}
		else if (current == "Status") {
			display(vecOfNobles, unhiredWarriors); //the first display using the display function
		}
		else if (current == "Battle") { //this reads all lines that say "Battle" first
			string name1;
			string name2;
			Noble* nob1 = nullptr;
			Noble* nob2 = nullptr;
			ifs >> name1 >> name2;
			for (size_t i = 0; i < vecOfNobles.size(); i++) {
				if (name1 == vecOfNobles[i]->getName()) {
					nob1 = vecOfNobles[i]; //identifies nob1
					break;
				}
			}
			for (size_t i = 0; i < vecOfNobles.size(); i++) {
				if (name2 == vecOfNobles[i]->getName()) {
					nob2 = vecOfNobles[i]; //identifies nob2
					break;
				}
			}
			if (nob1 == nullptr) {
				cout << "The noble doesn't exist" << endl;
			}
			if (nob2 == nullptr) {
				cout << "The opponent noble doesn't exist" << endl;
			}
			if (nob1 != nullptr && nob2 != nullptr) {
				nob1->battle(nob2); //battle function
			}
			

		}
		else if (current == "Clear") { //clears all vectors and deletes all pointers
			for (Noble* nob : vecOfNobles) {
				delete nob;
			}
			for (Noble*& nob : vecOfNobles) {
				nob = nullptr;
			}
			vecOfNobles.clear();
			for (Warrior* warr : unhiredWarriors) {
				delete warr;
			}
			for (Warrior*& warr : unhiredWarriors) {
				warr = nullptr;
			}
			unhiredWarriors.clear();
		}
	}
	ifs.close();
	system("pause");
}