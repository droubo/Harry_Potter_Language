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
	Spell();
	Spell(const string& name_, function<void(Wizard*, Wizard*)> action_);
	function<void(Wizard*, Wizard*)> get_action(Wizard* attacker, Wizard* defender);
	string get_name();
	void set_name(string name_);
	void set_action(function<void(Wizard*, Wizard*)> action_);
	void add_spell();
	bool operator[] (int index);
};

extern map<string, Spell> spells;

#endif
#pragma once
