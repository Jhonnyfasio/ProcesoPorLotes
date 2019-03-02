#ifndef PROCESS_H_INCLUDED
#define PPROCESS_H_INCLUDED

#include <iostream>
#include <cstring>

class Process {
private:
	int id;
	std::string operation;
	int tme;
	int timeTrans;
	int timeLlegada;
	int timeFinalizacion;
	int timeServicio;
	int timeRespuesta;
	int timeBlocked;
	//int lote;
	float result;

public:
	int getId();
	std::string getOperation();
	int getTme();
	int getTimeTrans();
	int getTimeLlegada();
	int	getTimeFinalizacion();
	int getTimeServicio();
	int getTimeRespuesta();
	int getTimeBlocked();
	//int getLote();
	float getResult();

	void setId(const int& idX);
	void setOperation(std::string& operationX);
	void setTme(const int& tmeX);
	void setTimeTrans(const int  timeX);
	void setTimeLlegada(const int timeX);
	void setTimeFinalizacion(const int timeX);
	void setTimeServicio(const int timeX);
	void setTimeRespuesta(const int timeX);
	void setTimeBlocked(const int timeX);
	//void setLote(const int& loteX);
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

int Process::getTimeTrans() {
	return timeTrans;
}

int Process::getTimeLlegada() {
	return timeLlegada;
}

int Process::getTimeFinalizacion() {
	return timeFinalizacion;
}

int Process::getTimeServicio() {
	return timeServicio;
}

int Process::getTimeRespuesta(){
	return timeRespuesta;
}

int Process::getTimeBlocked() {
	return timeBlocked;
}
/*int Process::getLote() {
	return lote;
}*/

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

void Process::setTimeTrans(const int timeX) {
	timeTrans = timeX;
}

void Process::setTimeLlegada(const int timeX) {
	timeLlegada = timeX;
}

void Process::setTimeFinalizacion(const int timeX) {
	timeFinalizacion = timeX;
}

void Process::setTimeServicio(const int timeX) {
	timeServicio = timeX;
}

void Process::setTimeRespuesta(const int timeX) {
	timeRespuesta = timeX;
}

void Process::setTimeBlocked(const int timeX) {
	timeBlocked = timeX;
}
/*void Process::setLote(const int& loteX) {
	lote = loteX;
}*/

void Process::setResult(const float& resultX) {
	result = resultX; 
}

std::string Process::toString() {
	std::string acumulator;
	return acumulator;
}

#endif // PROGRAMER_H_INCLUDED
