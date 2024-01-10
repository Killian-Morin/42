#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::SpellBook(const SpellBook& src) {

	this->_book = src._book;
}

SpellBook&	SpellBook::operator=(const SpellBook& rhs) {

	if (this != &rhs)
		this->_book = rhs._book;

	return (*this);
}

SpellBook::~SpellBook(void) {}

void	SpellBook::learnSpell(ASpell* spell) {

	if (spell) {
		if (this->_book.find(spell->getName()) == this->_book.end())
			this->_book.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
	}
}

void	SpellBook::forgetSpell(std::string const & s) {

	std::map<std::string, ASpell*>::iterator	it = this->_book.find(s);

	if (it != this->_book.end()) {
		delete it->second;
		this->_book.erase(it);
	}
}

ASpell*	SpellBook::createSpell(std::string const & s) {

	ASpell*	tmp = NULL;
	std::map<std::string, ASpell*>::iterator	it = this->_book.find(s);

	if (it != this->_book.end())
		tmp = this->_book[s];

	return (tmp);
}
