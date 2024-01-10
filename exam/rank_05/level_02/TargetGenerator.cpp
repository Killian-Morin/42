#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::TargetGenerator(const TargetGenerator& src) {

	this->_inventory = src._inventory;
}

TargetGenerator&	TargetGenerator::operator=(const TargetGenerator& rhs) {

	this->_inventory = rhs._inventory;

	return (*this);
}

TargetGenerator::~TargetGenerator(void) {}

void	TargetGenerator::learnTargetType(ATarget* target) {

	if (target)
		this->_inventory.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const & target) {

	std::map<std::string, ATarget*>::iterator	it = this->_inventory.find(target);

	if (it != this->_inventory.end()) {
		delete it->second;
		this->_inventory.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(std::string const & target) {

	ATarget*	tmp = NULL;
	std::map<std::string, ATarget*>::iterator	it = this->_inventory.find(target);

	if (it != this->_inventory.end())
		tmp = this->_inventory[target];

	return (tmp);
}
