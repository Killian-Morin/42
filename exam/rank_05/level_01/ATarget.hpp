#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget {

	protected:
		std::string	_type;

	public:
		ATarget(void);
		ATarget(const ATarget& src);
		ATarget&	operator=(const ATarget& rhs);
		virtual ~ATarget(void);

		ATarget(const std::string& type);

		const std::string&	getType(void) const;

		virtual ATarget*	clone(void) const = 0;

		void	getHitBySpell(const ASpell& spell) const;
};

#endif
