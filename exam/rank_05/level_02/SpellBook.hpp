#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>

#include "ASpell.hpp"

class ASpell;

class SpellBook {

	private:
		std::map<std::string, ASpell*>	_book;

		SpellBook(const SpellBook& src);
		SpellBook&	operator=(const SpellBook& rhs);

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const & s);
		ASpell*	createSpell(std::string const & s);
};

#endif
