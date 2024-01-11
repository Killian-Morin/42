#include "Warlock.hpp"

Warlock::Warlock(void) {}

Warlock::Warlock(const Warlock& src) {

	this->_name = src._name;
	this->_title = src._title;
}

Warlock&	Warlock::operator=(const Warlock& rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_title = rhs._title;
	}

	return (*this);
}

Warlock::~Warlock(void) {

	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title) {

	std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

const std::string&	Warlock::getName(void) const {

	return (this->_name);
}

const std::string&	Warlock::getTitle(void) const {

	return (this->_title);
}

void	Warlock::setTitle(const std::string& s) {

	this->_title = s;
}

void	Warlock::introduce(void) const {

	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell) {

	this->_inventory.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spellName) {

	this->_inventory.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget const & target) {

	ASpell*	tmp = this->_inventory.createSpell(spellName);

	if (tmp)
		tmp->launch(target);
}

/*
int main() {

	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall model1;

	Polymorph* polymorph = new Polymorph();
	TargetGenerator tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball* fireball = new Fireball();

	richard.learnSpell(fireball);

	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
}
*/
