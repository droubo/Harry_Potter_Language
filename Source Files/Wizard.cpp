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

const string Wizard::get_name() {
	return this->NAME_;
}
const string Wizard::get_house() {
	return this->HOUSE_;
}
const int Wizard::get_hp() {
	return this->HP_;
}
void Wizard::set_name(string name_) {
	this->NAME_ = name_;
}
void Wizard::set_house(string house_) {
	this->HOUSE_ = house_;
}
void Wizard::set_spells(map<string, void*> spells_) {
	this->spells = spells_;
}
map<string, void*>& Wizard::get_spells() {
	return this->spells;
}
bool Wizard::operator[] (int index) {
	return true;
}
bool Wizard::operator , (const int &effect) {
	if (mode == 0) this->set_hp(this->get_hp() - effect);
	if (mode == 1) {
		int maxHp = wizards.at(this->get_name()).get_hp();
		if (this->get_hp() + effect > maxHp) this->set_hp(maxHp);
		else this->set_hp(this->get_hp() + effect);
	}
	if (mode == 2) this->set_wand(effect);

	return true;
}
void Wizard::operator = (Wizard &wiz) {
	this->set_hp(wiz.get_hp());
	this->set_name(wiz.get_name());
	this->set_house(wiz.get_house());
	this->set_spells(wiz.get_spells());
}

ostream& operator<<(ostream& os, const Wizard& wiz)
{
	string chk_wand;
	if (wiz.WAND_ == 1) chk_wand = "Wand equipped";
	else chk_wand = "Wand not equipped";

	os << "NAME: " << wiz.NAME_ << "\n" << "HP: " << wiz.HP_ << "\n" << chk_wand << "\n";
	return os;
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
void Wizard::add_spell(string name, void *spell) {
	this->spells.insert(pair<string, void*>(name, spell));
}