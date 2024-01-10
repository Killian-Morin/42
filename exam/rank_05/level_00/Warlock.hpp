#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock {

	private:
		std::string	name;
		std::string	title;

		Warlock(void);
		Warlock(const Warlock& src);
		Warlock&	operator=(const Warlock& rhs);

	public:
		~Warlock(void);

		Warlock(const std::string& Name, const std::string& Title);

		const std::string&	getName() const;
		const std::string&	getTitle() const;

		void				setTitle(const std::string& s);

		void				introduce() const;

};

#endif
