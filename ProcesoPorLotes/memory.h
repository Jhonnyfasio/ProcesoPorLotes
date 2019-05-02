#ifndef PROCESS_H_INCLUDED
#define PPROCESS_H_INCLUDED

#include <iostream>
#include <cstring>

class Memory {
private:
	int id;
	int size;
	int max;
	int idProcess;

public:
	int getId();
	int getSize();
	int getMax();
	int getIdProcess();

	void setId(const int& idX);
	void setSize(const int& sizeX);
	void setMax(const int& maxX);
	void setIdProcess(const int& idProcessX);

	std::string toString();
};

//          Getters

int Memory::getId() {
	return id;
}

int Memory::getSize() {
	return size;
}

int Memory::getMax() {
	return max;
}

int Memory::getIdProcess() {
	return idProcess;
}
//           Setters
void Memory::setId(const int& idX) {
	id = idX;
}

void Memory::setSize(const int& sizeX) {
	size = sizeX;
}

void Memory::setMax(const int& maxX) {
	max = maxX;
}

void Memory::setIdProcess(const int& idProcessX){
	idProcess = idProcessX;
}
#endif // PROGRAMER_H_INCLUDED
