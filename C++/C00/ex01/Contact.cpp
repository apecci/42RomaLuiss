#include "Contact.hpp"

Contact::Contact(){
	return ;
}

Contact::~Contact(){
	return ;
}

void Contact::fillContact(){
	std::cout << "dame el NOMBRE hermano!" << std::endl;
	std::getline(std::cin, this->firstName, '\n');
	std::cout << "dame el COGNOMBRE hermano!" << std::endl;
	std::getline(std::cin, this->lastName, '\n');
	std::cout << "dame el FINTONOMBRE hermano!" << std::endl;
	std::getline(std::cin, this->nickName, '\n');
	std::cout << "dame el NUMERO hermano!" << std::endl;
	std::getline(std::cin, this->phoneNumber, '\n');
	std::cout << "dame el SEGRETON hermano!" << std::endl;
	std::getline(std::cin, this->darkestSecret, '\n');
	this->init = true;
	return ;
}

void Contact::displaySearchMenu(){

}

void Contact::showSearchedContact(int i){
	std::cout << "|        " << i + 1 << "|";
	this->displayField(this->firstName);
	this->displayField(this->lastName);
	this->displayField(this->nickName);
	std::cout << std::endl;
	return ;
}

void Contact::displayField(std::string str){
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9).append(".") << "|";
	else
		std::cout << std::right << std::setfill(' ') << std::setw(10) << str << "|";
	return ;
}

bool Contact::check() const{
	return (this->init);
}