#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell {

	public:
		Fireball(void);
		~Fireball(void);

		virtual Fireball*	clone(void) const;
};

#endif
