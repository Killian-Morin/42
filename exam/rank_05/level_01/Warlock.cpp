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

	if (spell) {
		if (this->_inventory.find(spell->getName()) == this->_inventory.end())
			this->_inventory.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
	}
}

void	Warlock::forgetSpell(std::string spellName) {

	std::map<std::string, ASpell*>::iterator	it;
	it = this->_inventory.find(spellName);

	if (it != this->_inventory.end()) {
		delete it->second;
		this->_inventory.erase(it);
	}
}

void	Warlock::launchSpell(std::string spellName, ATarget const & target) {

	std::map<std::string, ASpell*>::iterator	it;
	it = this->_inventory.find(spellName);

	if (it != this->_inventory.end())
		it->second->launch(target);
}

/*
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
