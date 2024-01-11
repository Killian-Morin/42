#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"

class ASpell;
class ATarget;

class Warlock {

	private:
		std::string	_name;
		std::string	_title;

		SpellBook	_inventory;

		Warlock(void);
		Warlock(const Warlock& src);
		Warlock&	operator=(const Warlock& rhs);

	public:
		~Warlock(void);

		Warlock(const std::string& name, const std::string& title);

		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;

		void				setTitle(const std::string& s);

		void				introduce(void) const;

		void				learnSpell(ASpell* spell);
		void				forgetSpell(std::string spellName);
		void				launchSpell(std::string spellName, ATarget const & target);
};

#endif
