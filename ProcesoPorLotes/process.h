#ifndef PROCESS_H_INCLUDED
#define PPROCESS_H_INCLUDED

#include <iostream>
#include <cstring>

class Process {
private:
	int id;
	std::string operation;
	int tme;
	int lote;
	float result;

public:
	int getId();
	std::string getOperation();
	int getTme();
	int getLote();
	float getResult();

	void setId(const int& idX);
	void setOperation(std::string& operationX);
	void setTme(const int& tmeX);
	void setLote(const int& loteX);
	void setResult(const float& resultX);

	std::string toString();
};

int Process::getId() {
	return id;
}

std::string Process::getOperation() {
	return operation;
}

int Process::getTme() {
	return tme;
}

int Process::getLote() {
	return lote;
}

float Process::getResult() {
	return result;
}

void Process::setId(const int& idX) {
	id = idX;
}

void Process::setOperation(std::string& operationX) {
	operation = operationX;
}

void Process::setTme(const int& tmeX) {
	tme = tmeX;
}

void Process::setLote(const int& loteX) {
	lote = loteX;
}

void Process::setResult(const float& resultX) {
	result = resultX; 
}

std::string Process::toString() {
	std::string acumulator;
	return acumulator;
}

#endif // PROGRAMER_H_INCLUDED
