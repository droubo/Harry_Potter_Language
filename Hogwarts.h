#ifndef HOGWARTS_H
#define HOGWARTS_H

#include <iostream>
#include "Wizard.h"
#include "Spell.h"

using namespace std;

#define BEGIN_GAME int main() { if(true
#define END_GAME );}
#define NAME false ? ""
#define HOUSE false ? ""
#define HP false ? 0
#define CREATE &&
#define WIZARD nullptr != new Wizard
#define WIZARDS Wizard()
#define SPELL nullptr != new Spell
#define ACTION false ? [] (Wizard *t, Wizard *d) { }
#define START [] (Wizard *attacker, Wizard *defender) {
#define END }

#endif

