#include "Wizard.h"
#include <iostream>

vector<Wizard> wizards;

Wizard::Wizard() {}

Wizard::Wizard(const string& name_, const string& house_, int hp_) : NAME_(name_), HOUSE_(house_), HP_(hp_) { add_wizard(); }

void Wizard::print_members() {
	cout << "NAME: " << NAME_ << " HOUSE: " << HOUSE_ << " HP: " << HP_;
}
void Wizard::add_wizard() {
	for (int i = 0; i < wizards.size(); i++) {
		if (wizards[i].get_name() == this->get_name()) return;
	}
	wizards.push_back(*this);
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
