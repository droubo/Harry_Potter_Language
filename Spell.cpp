#include "Spell.h"
#include <iostream>

vector<Spell> spells;

Spell::Spell(const string& name_, function<void(Wizard*, Wizard*)> action_) : NAME_(name_), action(action_) { add_spell(); }
//Spell::Spell() { }


void* Spell::get_action(Wizard* attacker, Wizard* defender) {
	action(attacker, defender);
}
string Spell::get_name() {
	return NAME_;
}

void Spell::add_spell() {
	for (int i = 0; i < spells.size(); i++) {
		if (spells[i].get_name() == this->get_name()) return;
	}
	spells.push_back(*this);
}
