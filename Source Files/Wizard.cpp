#include "Wizard.h"
#include <iostream>
#include <iterator>

map<string, Wizard> wizards;

int mode = -1;

Wizard::Wizard() {}

Wizard::Wizard(const string& name_, const string& house_, int hp_) : NAME_(name_), HOUSE_(house_), HP_(hp_) { add_wizard(); }

void Wizard::print_members() {
	cout << "NAME: " << NAME_ << " HOUSE: " << HOUSE_ << " HP: " << HP_;
}
void Wizard::add_wizard() {
	map<string, Wizard>::iterator itr;
	for (itr = wizards.begin(); itr != wizards.end(); ++itr) {
		if (itr->second.get_name() == this->get_name()) return;
	}
	wizards.insert(pair<string, Wizard>(this->get_name(), *this));
}

string Wizard::get_name() {
	return NAME_;
}
string Wizard::get_house() {
	return HOUSE_;
}
int Wizard::get_hp() {
	return HP_;
}
bool Wizard::operator[] (int index) {
	return true;
}
bool Wizard::operator , (const int &effect) {
	if (mode == 0) this->set_hp(this->get_hp() - effect);
	if (mode == 1) this->set_hp(this->get_hp() + effect);
	if (mode == 2) this->set_wand(effect);

	return true;
}
bool Wizard::get_wand() {
	if (WAND_ == 1) return true;
	return false;
}
void Wizard::set_hp(int hp_) {
	HP_ = hp_;
}
void Wizard::set_wand(int wnd) {
	WAND_ = wnd;
}
map<string, void*> Wizard::get_spells() {
	return this->spells;
}
void Wizard::add_spell(string name, void *spell) {
	this->spells.insert(pair<string, void*>(name, spell));
}