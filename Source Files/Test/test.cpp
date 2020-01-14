#include "Hogwarts.h"

BEGIN_GAME

CREATE SPELL{
NAME: "Sectumsempra",
ACTION : START
		 // Για 5 γύρους κάνει 8 damage στον αντίπαλο (DEFENDER)
		  FOR 5 ROUNDS DO
		  DAMAGE DEFENDER 8
		  END
		EQUIP DEFENDER ---α
		AFTER 2 ROUNDS DO
			EQUIP DEFENDER _
		END
		END
}
CREATE SPELL{
NAME: "Expulso",
ACTION : START
		 // Κάνει 22 damage στον αντίπαλο (DEFENDER)
		 DAMAGE DEFENDER 22
		 END
}
CREATE SPELL{
NAME: "Anapneo",
ACTION : START
		 // Κάνει heal στον εαυτό του (ATTACKER)
		 HEAL ATTACKER 30
		END
}
CREATE SPELL{
NAME: "Expelliarmus",
	  ACTION : START
		AFTER 2 ROUNDS DO
			HEAL ATTACKER 100
		END
		END
}
CREATE WIZARD{
NAME: "Harry Potter",
HOUSE : "Gryffindor",
HP : 100
}
CREATE WIZARD{
NAME: "Draco Malfoy",
HOUSE : "Ravenclaw",
HP : 90
}
MR "Harry Potter" LEARN[
	SPELL_NAME(Expelliarmus)
		SPELL_NAME(Sectumsempra)
		SPELL_NAME(Expulso)
		SPELL_NAME(Anapneo)
]
MR "Draco Malfoy" LEARN[
	SPELL_NAME(Expelliarmus)
		SPELL_NAME(Expulso)
]
DUEL
END_GAME
