#include "kitty.h"

DomesticCat::DomesticCat(const std::string& name, const std::string& species)
	: name_(name)
	, species_(species)
{

}

DomesticCat::~DomesticCat()
{

}

std::string DomesticCat::get_description()
{
	return "kitty";
}

std::ostream& operator<<(std::ostream& os, const DomesticCat& kitty)
{
	os << kitty.name_ << " specimen of " << kitty.species_;
	return os;
}

void DomesticCat::make_sound()
{
	std::cout << "Miau" << std::endl;
}


//Kitty::operator std::string() const
//{
//	std::string result(this->name_);
//	result.append(" (");
//	result.append(this->species_);
//	result.append(")");
//	return result;
//}

//Kitty::operator int() const
//{
//	return this->name_.length();
//}
