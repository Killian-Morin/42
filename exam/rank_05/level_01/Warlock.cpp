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

void	Warlock::learnSpell(const ASpell* spell) {

	if (spell) {
		if (this->_inventory.find(spell->getName()) == this->_inventory.end())
			this->_inventory.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
	}
}

void	Warlock::forgetSpell(const std::string& spell) {

	std::map<std::string, ASpell*>::iterator	tmp;
	tmp = this->_inventory.find(spell);

	if (tmp != this->_inventory.end())
		this->_inventory.erase(tmp);
}

void	Warlock::launchSpell(const std::string& spell, const ATarget& target) {

	std::map<std::string, ASpell*>::iterator	tmp;
	tmp = this->_inventory.find(spell);

	if (tmp != this->_inventory.end())
		tmp->second->launch(target);
}

/*
#include "Warlock.hpp"

int main()
{
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);
}
*/
