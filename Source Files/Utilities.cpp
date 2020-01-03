#include "Utilities.h"
#include "Duel.h"

Wizard *wiz;
int times;

AND_::AND_() {}
bool AND_::operator() (bool first, bool second) {
	return first && second;
}
OR_::OR_() {}
bool OR_::operator() (bool first, bool second) {
	return first || second;
}
NOT_::NOT_() {}
bool NOT_::operator() (bool first) {
	return !first;
}
LEARN_::LEARN_(){}

bool LEARN_::operator[](bool placeHolder) {
	return true;
}

AFTER_FOR::AFTER_FOR() {}

void AFTER_FOR::operator , (function<void()> fun) {
	to_cast.insert(pair<int, function<void()>>(times, fun));
}

a::a() {}
int a::operator -- () {
	return 0;
}
a a::operator - () {
	return a();
}

int GET_HP(Wizard wiz) {
	return wiz.get_hp();
}
string GET_NAME(Wizard wiz) {
	return wiz.get_name();
}
string GET_HOUSE(Wizard wiz) {
	return wiz.get_house();
}
bool HAS_WAND(Wizard wiz) {
	return wiz.get_wand();
}

int SPELL_NAME(string name) {
	Spell *spell = (&spells.at(name));
	wiz->add_spell(name, spell);
	return 0;
}
