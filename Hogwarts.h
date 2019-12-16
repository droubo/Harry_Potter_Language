#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define BEGIN_GAME int main() {
#define END_GAME }
#define NAME false ? ""
#define HOUSE false ? ""
#define HP false ? 0
#define WIZARD Wizard
#define CREATE if(nullptr !=
class Wizard;

vector<Wizard> wizards;

class Wizard {
	string NAME_;
	string HOUSE_;
	int HP_;

public:
	Wizard() { print_members(); }
	Wizard(const string& name_, const string& house_, int hp_) : NAME_(name_), HOUSE_(house_), HP_(hp_) { wizards.push_back(*this); }
	void print_members() {
		cout << "NAME: " << NAME_ << " HOUSE: " << HOUSE_ << " HP: " << HP_;	
	}
};

