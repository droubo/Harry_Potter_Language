#include "Hogwarts.h"

BEGIN_GAME

CREATE WIZARD{
	NAME: "Harry Potter",
	HOUSE : "Gryffindor",
	HP : 101
}

CREATE WIZARD{
	NAME: "Harry Iotter",
	HOUSE : "Gryffindor",
	HP : 102
}

CREATE WIZARDS[
	WIZARD{
		NAME: "HarryPotter",
		HOUSE : "Gryffindor",
		HP : 103
	},

		WIZARD{
			NAME: "Harry Dotter",
			HOUSE : "Gryffindor",
			HP : 100
	},
		WIZARD{
			NAME: "Harry Aotter",
			HOUSE : "Gryffindor",
			HP : 100
	}
]

CREATE SPELLS [
	SPELL{
		NAME: "Yes",
		ACTION : START
			IF AND(GET_HP(ATTACKER), 101) DO
				DAMAGE ATTACKER 10
		//EQUIP ATTACKER  ---α
			END
		END
	},
	SPELL{
		NAME: "HEAL",
		ACTION : START
			IF AND(GET_HP(ATTACKER), 101) DO
				HEAL ATTACKER 10
				//EQUIP ATTACKER  ---α
			END
		END
	}
]


CREATE nullptr != spells.at("Yes").get_action(&wizards.at("Harry Potter"), &wizards.at("Harry Iotter"))

MR "Harry Potter" LEARN[
	SPELL_NAME(Yes)
	SPELL_NAME(HEAL)
		0
]
&& nullptr != ((Spell *)wizards.at("Harry Potter").get_spells().at("HEAL"))->get_action(&wizards.at("Harry Potter"), &wizards.at("Harry Iotter"))
&& cout << wizards.at("Harry Potter").get_hp()

END_GAME