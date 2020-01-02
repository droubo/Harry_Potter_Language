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
	const string get_name();
	const string get_house();
	const int get_hp();
	void set_hp(int hp_);
	void set_name(string name_);
	void set_house(string house_);
	void set_spells(map<string, void*> spells_);
	map<string, void*>& get_spells();
	bool get_wand();
	void set_wand(int wnd);
	bool operator[] (int index);
	bool operator , (const int &dmg);
	void operator = (Wizard &wiz);
	friend ostream& operator<<(ostream& os, const Wizard& wiz);

	void add_spell(string name, void *spell);
};

extern map<string, Wizard> wizards;
extern int mode;

#endif
#pragma once
