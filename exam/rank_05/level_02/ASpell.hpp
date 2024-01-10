#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell {

	protected:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell(void);
		ASpell(const ASpell& src);
		ASpell&	operator=(const ASpell& rhs);
		virtual ~ASpell(void);

		ASpell(const std::string& name, const std::string& effects);

		const std::string&	getName(void) const;
		const std::string&	getEffects(void) const;

		virtual ASpell*	clone(void) const = 0;

		void	launch(const ATarget& target) const;
};

#endif
