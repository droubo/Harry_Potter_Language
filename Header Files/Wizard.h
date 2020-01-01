#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Wizard {

private:
	string NAME_;
	string HOUSE_;
	int HP_;
	bool WAND_ = 1;
	map<string, void*> spells;

public:
	Wizard();

	Wizard(const string& name_, const string& house_, int hp_);

	void print_members();
	void add_wizard();
	string get_name();
	string get_house();
	int get_hp();
	void set_hp(int hp_);
	bool get_wand();
	void set_wand(int wnd);
	bool operator[] (int index);
	bool operator , (const int &dmg);
	map<string, void*> get_spells();

	void add_spell(string name, void *spell);
};

extern map<string, Wizard> wizards;
extern int mode;

#endif
#pragma once
