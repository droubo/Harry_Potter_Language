#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <vector>

using namespace std;

class Spell {

private:
	string NAME_;
	template <class T>
	void action(T *attacker, T *defender);
public:
	template <class T>
	Spell(const string& name_, void action_(T *attacker, T*defender));
	void *get_action();
	string get_name();
	void add_spell();
};

extern vector<Spell> spells;

#endif
