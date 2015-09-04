#include "matrixvectorcalc.h"


matrixvectorcalc::matrixvectorcalc()
{
	std::vector<float>a1;
	a1.push_back(0);
	a1.push_back(0);
	a1.push_back(0);

	std::vector<float>a2;
	a2.push_back(0);
	a2.push_back(0);
	a2.push_back(0);

	std::vector<float>a3;
	a3.push_back(0);
	a3.push_back(0);
	a3.push_back(0);


	matrix.push_back(a1);
	matrix.push_back(a2);
	matrix.push_back(a3);
}


matrixvectorcalc::~matrixvectorcalc()
{
}


std::vector<std::vector<float>> matrixvectorcalc::additionMatrix(std::vector<std::vector<float>> m1, std::vector<std::vector<float>> m2)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return matrix;
}

//std::ostream& operator<<(std::ostream& os, std::vector<std::vector<float>> mat)
//{
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			std::cout << mat[i][j];
//		}
//		std::cout << std::endl;
//	}
//}


