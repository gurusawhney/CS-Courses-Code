//Homework 6

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Person { //everyone derives from person. Has a default strength and isdead setting if not inputs are taken
public:
	Person(const string& n, double s = 0) : name(n), strength(s) {}
	string getName() const { //returns the name
		return name;
	}
	bool getDead() const { //returns bool value
		return isdead;
	}
	virtual double getStrength() const { //returns the strength
		return strength;
	}
	void setStrength(const double& newstrength) { //changes the strength
		strength = newstrength;
	}
	void setDead(bool status) { //changes the death bool
		isdead = status;
	}
private:
	string name;
	double strength;
	bool isdead = false;
};

class Noble : public Person {
public:
	Noble(const string& n, double s = 0) : Person(n, s) {} //constructor
	virtual void display() = 0;
	void battle(Noble& opponent) { //this function executes the battle
		cout << getName() << " battles " << opponent.getName() << endl;
		if (getStrength() == opponent.getStrength() && getDead() == false && opponent.getDead() == false) {//checks to see if neither are dead and have same strength
			clash(); opponent.clash();
			cout << "Mutual Annihalation: " << getName() << " and " << opponent.getName() << " die at each other's hands" << endl;
			setStrength(0);
			setDead(true);
			opponent.setStrength(0);
			opponent.setDead(true);
		}
		else if (getDead() == true && opponent.getDead() == true) {//executes if both are dead
			cout << "Oh,NO! They're both dead! Yuck!" << endl;
		}
		else if (getStrength() > opponent.getStrength() && opponent.getDead() == false) {//checks if noble is stronger than opponent
			clash(); opponent.clash();
			cout << getName() << " defeats " << opponent.getName() << endl;
			adjustStrength(opponent.getStrength(), getStrength());
			opponent.setStrength(0);
			opponent.setDead(true);
		}
		else if (getStrength() > 0 && opponent.getDead() == true) {//checks if opponent is dead
			cout << "He's dead, " << getName() << endl;
		}
		else if (getStrength() < opponent.getStrength() && getDead() == false) {//checks if opponent is stronger than noble
			clash(); opponent.clash();
			cout << opponent.getName() << " defeats " << getName() << endl;
			setStrength(0);
			setDead(true);
			opponent.adjustStrength(getStrength(), opponent.getStrength());
		}
		else if (opponent.getStrength() > 0 && getDead() == true) {//checks if noble is dead
			cout << "He's dead, " << opponent.getName() << endl;
		}
	}
	virtual void adjustStrength(double x, double y) = 0; //adjusts the strength differently for each type of noble
	virtual void clash() = 0; //calls for the nobles' army's battle cry
}; 

class Lord;

class Protector : public Person {
public:
	Protector(const string& n, double s) : Person(n, s), boss(nullptr) {} //constructor
	Noble* getBoss() const {
		Noble* theboss = boss;
		return theboss;
	}
	void hire(Noble* lord) { //
		boss = lord;
	}
	virtual void battles() = 0; //battles function is the battle cry for wizards and warriors
private:
	Noble* boss;
};

class PersonWithStrengthToFight : public Noble {
public:
	PersonWithStrengthToFight(const string& n, double s) : Noble(n, s) { }
	virtual void display() { //this function displays the warriors stats
		cout << getName() << " is a person with strength " << getStrength() << endl; //prints out the number of warriors
	}
	virtual void adjustStrength(double x, double y) override {//once the battle takes place it subtracts the strengths
		setStrength(x-y);
	}
	virtual void clash() { //my placeholder so that clash can be inherited from the Noble class
		cout << "";
	}
};

class Lord : public Noble {
public:
	Lord(const string& n, double s = 0) : Noble(n, s) {} //constructor
	vector<Protector*> getArmy() { //returns the army
		return army;
	}
	void hires(Protector& warr) { //adds a warrior and assigns the warrior their noble
		warr.hire(this);
		army.push_back(&warr);
	}
	void fire(Protector& warr) {
		for (size_t i = 0; i < army.size(); i++) { //adjusts the position of all warriors and shortens the length of the vector
			if (army[i] == &warr) {
				for (size_t j = i; i < army.size() - 1; j++) {
					army[j] = army[j + 1];
				}
			}
		}
		army.pop_back();
		cout << warr.getName() << " you're fired! - " << getName() << endl;
	}
	double getStrength() const { //returns the strength
		double total = 0;
		for (Protector* p : army) {
			total += p->getStrength();
		}
		return total;
	}
	virtual void display() { //this function displays the warriors stats
		cout << getName() << " has an army of " << army.size() << endl; //prints out the number of warriors
		for (size_t i = 0; i < army.size(); i++) {
			cout << "\t" << army[i]->getName() << ": " << army[i]->getStrength() << endl; //prints out name and strength
		}
	}
	virtual void adjustStrength(double x, double y) override {//once the battle takes place this fixes the strengths of the armies
		double str_ratio = x / y;
		for (size_t i = 0; i < army.size(); i++) {
			if (str_ratio == 0) { //changes the strengths for the dead warriors
				army[i]->setStrength(0);
			}
			else {
				army[i]->setStrength(army[i]->getStrength() * str_ratio);//adjusts strength of living warriors
			}
		}
	}
	virtual void clash() { //calls their warrior battle cries
		for (Protector* p : army) {
			p->battles();
		}

	}
private:
	vector<Protector*> army;
};

class Warrior : public Protector { //swordsmen and archers derive from warrior
public:
	Warrior(const string& n, double s) : Protector(n, s) {} //constructor
};

class Wizard : public Protector {
public:
	Wizard(const string& n, double s) : Protector(n, s) {} //constructor
	virtual void battles() override { //battle cry
		cout << "POOF!" << endl;
	}
};

class Archer : public Warrior {
public:	
	Archer(const string& n, double s) : Warrior(n, s) {} //constructor
	virtual void battles() override {
		cout << "TWANG! " << getName() << " says: Take that in the name of my lord, " << getBoss()->getName() << endl; //battle cry
	}
};

class Swordsman : public Warrior { 
public:
	Swordsman(const string& n, double s) : Warrior(n, s) {} //constructor
	virtual void battles() override {
		cout << "CLANG! " << getName() << " says: Take that in the name of my lord, " << getBoss()->getName() << endl; //battle cry
	}
};

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}