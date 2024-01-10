#include "ASpell.hpp"

ASpell::ASpell(void) {}

ASpell::ASpell(const ASpell& src) {

	this->_name = src._name;
	this->_effects = src._effects;
}

ASpell&	ASpell::operator=(const ASpell& rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}

	return (*this);
}

ASpell::~ASpell(void) {}

ASpell::ASpell(const std::string& name, const std::string& effects) : _name(name), _effects(effects) {}

const std::string&	ASpell::getName(void) const {

	return (this->_name);
}

const std::string&	ASpell::getEffects(void) const {

	return (this->_effects);
}

void	ASpell::launch(const ATarget& target) const {

	target.getHitBySpell(*this);
}
