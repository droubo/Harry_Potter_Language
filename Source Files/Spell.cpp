#include "Spell.h"
#include <iostream>
#include <iterator>

map<string, Spell> spells;

Spell::Spell(const string& name_, function<void(Wizard*, Wizard*)> action_) : NAME_(name_), action(action_) { add_spell(); }
Spell::Spell() { }


function<void(Wizard*, Wizard*)> Spell::get_action(Wizard* attacker, Wizard* defender) {
	action(attacker, defender);
	return action;
}
string Spell::get_name() {
	return NAME_;
}
void Spell::set_name(string name_) {
	this->NAME_ = name_;
}
void Spell::set_action(function<void(Wizard*, Wizard*)> action_) {
	this->action = action_;
}
void Spell::add_spell() {
	map<string, Spell>::iterator itr;
	for (itr = spells.begin(); itr != spells.end(); ++itr) {
		if (itr->second.get_name() == this->get_name()) return;
	}
	spells.insert(pair<string, Spell>(this->get_name(), *this));
}

bool Spell::operator[] (int index) {
	return true;
}