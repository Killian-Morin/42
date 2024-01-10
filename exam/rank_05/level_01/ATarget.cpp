#include "ATarget.hpp"

ATarget::ATarget(void) {}

ATarget::ATarget(const ATarget& src) {

	this->_type = src._type;
}

ATarget&	ATarget::operator=(const ATarget& rhs) {

	if (this != &rhs) {
		this->_type = rhs._type;
	}

	return (*this);
}

ATarget::~ATarget(void) {}

ATarget::ATarget(const std::string& type) : _type(type) {}

const std::string&	ATarget::getType(void) const {

	return (this->_type);
}

void	ATarget::getHitBySpell(const ASpell& spell) const {

	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
