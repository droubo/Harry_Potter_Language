#ifndef DUEL_H
#define DUEL_H
#include "Wizard.h"
#include "Spell.h"

class Duel {
private:
	Wizard p1, p2;
	Wizard *turn = &p1;
public:
	Duel();
	void start_duel();
	void select_wizard(Wizard &wiz);
	void show_wizards();
	void show_spells(Wizard wiz);
	void cast_spell(Wizard *wiz);
	void show_Wizards_info();
	void change_turn();
	Wizard* get_turn();
	void start_of_round_spells();
	int check_winner();
	int get_playerNO(Wizard *wiz);
	void give_hp_to_RavenClaw();
};

extern int PlayRound;
extern multimap<int, function<void()>> to_cast;
#endif
#pragma once
