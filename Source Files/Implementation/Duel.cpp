#include "Duel.h"
#include <iostream>

int PlayRound = 1;
multimap<int, function<void()>> to_cast;


Duel::Duel() { Duel::start_duel(); }


void Duel::start_duel() {
	cout << "\n===================================== HARRY POTTER THE GAME ====================================\n";

	cout << "Player1 select a wizard\n";
	cout << "-------------------------\n";
	Duel::select_wizard(this->p1);

	cout << "Player2 select a wizard\n";
	cout << "-------------------------\n";
	Duel::select_wizard(this->p2);
	while (check_winner() != 1) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << "ROUND " << PlayRound << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		Duel::start_of_round_spells();
		Duel::cast_spell(&(*turn));
		Duel::show_Wizards_info();

		if (check_winner() == 1) break;

		Duel::cast_spell(&(*turn));
		Duel::show_Wizards_info();
		PlayRound++;
	}
}

void Duel::select_wizard(Wizard &wiz) {
	string wizard;
	show_wizards();

	getline(cin, wizard);
	if (wizards.count(wizard)) {
		wiz = wizards.at(wizard);
	}
	else {
		cout << "This wizard does not exist. Please select again\n";
		cout << "-------------------------\n";
		select_wizard(wiz);
	}
}

void Duel::show_wizards() {
	map<string, Wizard>::iterator itr;
	for (itr = wizards.begin(); itr != wizards.end(); ++itr) {
		cout << itr->second.get_name() << "\n";
	}
	cout << "-------------------------\n";
}

void Duel::show_Wizards_info() {
	cout << "\n######################\n";
	cout << p1;
	cout << "######################\n";

	cout << "\n\n######################\n";
	cout << p2;
	cout << "######################\n\n";

}

void Duel::show_spells(Wizard wiz) {
	map<string, void *>::iterator itr;
	Spell *tmp;
	for (itr = wiz.get_spells().begin(); itr != wiz.get_spells().end(); ++itr) {
		tmp = (Spell *)itr->second;
		cout << tmp->get_name() << "\n";
	}
	cout << "-------------------------\n";
}
void Duel::cast_spell(Wizard *wiz) {
	string spell;

	if (!wiz->get_wand()) {
		cout << wiz->get_name() << "(Player " << Duel::get_playerNO(wiz) << ") has not a wand so he cant't cast a spell.\n";
		Duel::change_turn();
		return;
	}

	cout << wiz->get_name() << "(Player " << Duel::get_playerNO(wiz) << ") select spell:\n";
	Duel::show_spells(*wiz);

	getline(cin, spell);
	if (wiz->get_spells().count(spell)) {
		Spell *spl = (Spell *) wiz->get_spells().at(spell);
		Duel::change_turn();
		spl->get_action(wiz, turn);
	}
	else {
		cout << "This spell does not exist. Please select again\n";
		cout << "-------------------------\n";
		cast_spell(wiz);
	}
}
void Duel::change_turn() {
	if (this->turn == &p1) this->turn = &p2;
	else this->turn = &p1;
}
Wizard* Duel::get_turn() {
	return this->turn;
}
int Duel::check_winner() {
	if (this->p1.get_hp() <= 0) {
		cout << "\n\nGAME FINISHED ! PLAYER 2 WINS \n\n";
		return 1;
	}
	else if (this->p2.get_hp() <= 0) {
		cout << "\n\nGAME FINISHED ! PLAYER 1 WINS \n\n";
		return 1;
	}
	return 0;
}
int Duel::get_playerNO(Wizard *wiz) {
	if (wiz == &this->p1) return 1;
	else return 2;
}

void Duel::start_of_round_spells() {
	multimap<int, function<void()>>::iterator itr;
	multimap<int, function<void()>> tmp_map;
	function<void()> tmp;
	int key_times;

	for (itr = to_cast.begin(); itr != to_cast.end(); ++itr) {
		tmp = itr->second;
		key_times = itr->first;
		if (key_times >= 0) {
			tmp();
			if (key_times > 1) {
				tmp_map.insert(pair<int, function<void()>>(key_times - 1, tmp));
			}
		}
		else {
			tmp_map.insert(pair<int, function<void()>>(key_times + 1, tmp));
		}
	}
	to_cast = tmp_map;
}