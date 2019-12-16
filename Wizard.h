#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include <vector>

using namespace std;

class Wizard {
	string NAME_;
	string HOUSE_;
	int HP_;

public:
	Wizard();

	Wizard(const string& name_, const string& house_, int hp_);

	void print_members();
	void add_wizard();
	string get_name();
	string get_house();
	int get_hp();
	bool operator[] (int index);
};

extern vector<Wizard> wizards;

#endif
