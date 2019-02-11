#ifndef PROGRAMER_H_INCLUDED
#define PROGRAMER_H_INCLUDED

#include <iostream>
#include <cstring>

class Programer {
	private:
		int id;
		std::string name;

	public:
		int getId();
		std::string getName();

		void setId(const int& idX);
		void setName(std::string& nameX);
	
		std::string toString();
};

int Programer::getId() {
	return id;
	}

std::string Programer::getName() {
	return name;
}

void Programer::setId(const int& idX) {
	id = idX;
}

void Programer::setName(std::string& nameX) {
	name = nameX;
}

std::string Programer::toString() {
	std::string acumulator;
	return acumulator;
}

#endif // PROGRAMER_H_INCLUDED
