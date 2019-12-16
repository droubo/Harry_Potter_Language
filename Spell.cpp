#include "Spell.h"

vector<Spell> spells;

template <class T>
Spell::Spell(const string& name_, void action(T *attacker, T*defender)) : NAME_(name_), action(action_) { add_spell(); }

void *Spell::get_action() {
	return &action;
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