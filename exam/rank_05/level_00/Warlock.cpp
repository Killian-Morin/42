#include "Warlock.hpp"

Warlock::Warlock(void) {}

Warlock::Warlock(const Warlock& src) {

	this->name = src.name;
	this->title = src.title;

}

Warlock&	Warlock::operator=(const Warlock& rhs) {

	if (this != &rhs) {
		this->name = rhs.name;
		this->title = rhs.title;
	}

	return (*this);
}

Warlock::~Warlock(void) {

	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName() const {

	return (this->name);
}

const std::string&	Warlock::getTitle() const {

	return (this->title);
}

void	Warlock::setTitle(const std::string& s) {

	this->title = s;
}

Warlock::Warlock(const std::string& Name, const std::string& Title) : name(Name), title(Title) {

	std::cout << this->getName() << ": This looks like another boring day." \
		<< std::endl;
}

void	Warlock::introduce() const {

	std::cout << this->getName() << ": I am " << this->getName() << \
		", " << this->getTitle() << "!" << std::endl;
}

/*
int main() {

	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	return (0);
}
*/
