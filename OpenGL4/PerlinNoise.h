#ifndef DEF_PERLINNOISE
#define DEF_PERLINNOISE
class PerlinNoise
{
public:
	PerlinNoise(void);
	~PerlinNoise(void);
	void init(int size, int set, int octavesNbr);
	double noiseFunction(double x);
	double linearInterpolation(double a, double b, double x);
	double cosInterpolation(double a, double b, double x);
	double noise(int i);
	double coherentNoise(double x, double persistance);

private:
	double* values;
	int set;
	int octavesNbr;

};

#endif