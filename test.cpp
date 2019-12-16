#include "Hogwarts.h"
#include <string>
#include <vector>

BEGIN_GAME

CREATE WIZARD{
	NAME: "Harry Potter",
	HOUSE : "Gryffindor",
	HP : 100
}

CREATE WIZARD{
	NAME: "Harry Iotter",
	HOUSE : "Gryffindor",
	HP : 100
}

CREATE WIZARDS[
	WIZARD{
		NAME: "HarryPotter",
		HOUSE : "Gryffindor",
		HP : 100
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

CREATE cout << wizards.size()

END_GAME