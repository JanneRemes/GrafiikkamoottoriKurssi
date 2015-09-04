#ifndef MATRIXVECTORCALC_H
#define MATRIXVECTORCALC_H




#include <vector>
#include <iostream>
class matrixvectorcalc
{
public:
	matrixvectorcalc();
	~matrixvectorcalc();

	std::vector<std::vector<float> > additionMatrix(std::vector<std::vector<float> > m1, std::vector<std::vector<float> > m2);
	//void MatrixMultiplication();
	//void multiplyByVector();
	//void scalarMultiplication();

	//std::ostream& operator<<(std::vector<std::vector<float>> mat);

	std::vector<std::vector<float> > matrix;
};

#endif