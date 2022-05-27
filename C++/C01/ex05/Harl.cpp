#include "Harl.hpp"

Harl::Harl(){
	std::cout << "Harl turned on" << std::endl;
	return;
}

Harl::~Harl(){
	std::cout << "Harl finished its complaints" << std::endl;
	return;
}

void Harl::complain(std::string level){
	void (Harl::*complains[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string complainsLevels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	for (int i = 0; i < 4; i++){
		void (Harl::*selectedComplain)(void) = complains[i];
		if (level == complainsLevels[i])
			(this->*selectedComplain)();
	}
}

void Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}