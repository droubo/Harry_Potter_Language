#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <vector>
#include <functional>
#include "Wizard.h"

using namespace std;

class Spell {

private:
	string NAME_;
	function<void(Wizard*, Wizard*)> action;
public:
	//Spell();
	Spell(const string& name_, function<void(Wizard*, Wizard*)> action_);
	void *get_action(Wizard* attacker, Wizard* defender);
	string get_name();
	void add_spell();
};

extern vector<Spell> spells;

#endif
