#ifndef UTILITIES_H
#define UTILITIES_H
#include "Spell.h"

class AND_ {
public:
	AND_();
	bool operator() (bool first, bool second);
};
class OR_ {
public:
	OR_();
	bool operator() (bool first, bool second);
};
class NOT_ {
public:
	NOT_();
	bool operator() (bool first);
};
class LEARN_ {
public:
	LEARN_();
	bool operator[] (bool placeHolder);
};

class AFTER_FOR {
public:
	AFTER_FOR();
	void operator , (function<void()>);
};
class a {
public:
	a();
	int operator -- ();
	a operator - ();
};
int GET_HP(Wizard wiz);

string GET_NAME(Wizard wiz);

string GET_HOUSE(Wizard wiz);

bool HAS_WAND(Wizard wiz);

int SPELL_NAME(string name);

extern Wizard *wiz;
extern Spell *spell;
extern int times;
#endif // !UTILITIES_H
#pragma once
