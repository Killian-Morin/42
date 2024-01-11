#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <map>

#include "ATarget.hpp"

class TargetGenerator {

	private:
		std::map<std::string, ATarget*>	_inventory;

	public:
		TargetGenerator(void);
		TargetGenerator(const TargetGenerator& src);
		TargetGenerator&	operator=(const TargetGenerator& rhs);
		~TargetGenerator(void);

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(std::string const & targetName);
		ATarget*	createTarget(std::string const & targetName);
};

#endif
