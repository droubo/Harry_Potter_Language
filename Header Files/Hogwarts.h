#ifndef HOGWARTS_H
#define HOGWARTS_H

#include <iostream>
#include "Utilities.h"
#include "Duel.h"

using namespace std;

#define BEGIN_GAME int main() { if(true
#define END_GAME ); return 0;}
#define NAME false ? ""
#define HOUSE false ? ""
#define HP false ? 0
#define CREATE &&
#define WIZARD nullptr != new Wizard
#define WIZARDS Wizard()
#define SPELL nullptr != new Spell
#define SPELLS Spell()
#define ACTION false ? (function<void(Wizard*, Wizard*)>) nullptr
#define START [] (Wizard *atckr, Wizard *dfndr) { caster = (*atckr); round_ = PlayRound
#define ATTACKER (*atckr),
#define DEFENDER (*dfndr),
#define END ;}
#define IF ;if(
#define DO ){
#define ELSE_IF }else if(
#define ELSE }else{
#define AND AND_()
#define OR OR_()
#define NOT NOT_()
#define SHOW ;cout <<
#define SPELL_NAME(NAME) -SPELL_NAME(#NAME)
#define GET_HP(arg1, ...) GET_HP(arg1 __VA_ARGS__)
#define GET_NAME(arg1, ...) GET_NAME(arg1 __VA_ARGS__)
#define GET_HOUSE(arg1, ...) GET_HOUSE(arg1 __VA_ARGS__)
#define HAS_WAND(arg1, ...) HAS_WAND(arg1 __VA_ARGS__)
#define DAMAGE ;mode=0;
#define HEAL ;mode=1;
#define EQUIP ;mode=2;
#define _ 1
#define α a()
#define MR &&nullptr != (wiz = &wizards.at(
#define LEARN ))&&LEARN_()
#define DUEL && nullptr != new Duel()
#define FOR ;times = 
#define ROUNDS ;AFTER_FOR(), [atckr, dfndr](
#define AFTER ;times = -

#endif

