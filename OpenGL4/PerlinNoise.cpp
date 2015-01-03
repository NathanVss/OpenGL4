#include "PerlinNoise.h"
#include <math.h>
#include <time.h>
#include <random>
#include <iostream>

#include <Windows.h>
#include <Psapi.h>
#include "Boot.h"

PerlinNoise::PerlinNoise(void){
	this->set = false;
}


PerlinNoise::~PerlinNoise(void)
{
}

double PerlinNoise::coherentNoise(double x, double persistance) {

	double sum = 0;
	double p = 1;
	int f = 1;

	for(int i = 0; i < this->octavesNbr; i++) {

		sum += p*this->noiseFunction(x * f);
		p *= persistance;
		f *= 2;

	}

	return sum * (1 - persistance) / ( 1 - p);

}

void PerlinNoise::init(int size, int set, int octavesNbr) {

	
	srand(time(NULL)+rand());
	for(int i=0; i<100;i++) {
		rand();
	}


	double power = pow((double)2, (octavesNbr-1));
	int valuesSize = (int)ceil(size*power / set);
	double* values = new double[valuesSize];
	//this->values = values;

	// Si set existe alors PerlinNoise à déjà été init au moins une fois auparavant
	// On libère donc la mémoire des values
	if(this->set) {

		delete this->values;
	}

	//OutputDebugString("\nPERLIN : ");
	for(int i =0; i<valuesSize;i++) {
		values[i] = (double)rand()/ RAND_MAX;
		if( i <= 3) {
			//OutputDebugString("\n");
			//OutputDebugString((std::string("") + values[i]).c_str());
		}
		//std::cout << values[i] << std::endl;
	}
	this->values = values;
	this->set = set;
	this->octavesNbr = octavesNbr;

}

double PerlinNoise::noise(int i) {
	return this->values[i];
}

double PerlinNoise::noiseFunction(double x) {

	int i = (int) ( x / this->set );
	return this->cosInterpolation(this->noise(i), this->noise(i+1), fmod(( x / this->set ), 1));

}

double PerlinNoise::linearInterpolation(double a, double b, double x) {
	return a * ( 1 - x ) + b * x;
}

double PerlinNoise::cosInterpolation(double a, double b, double x) {
	double k = (1- cos(x*3.14159265)) / 2;
	return this->linearInterpolation(a, b, k);
}