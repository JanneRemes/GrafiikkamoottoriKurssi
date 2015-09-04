#include "matrixvectorcalc.h"
#include <iostream>

int main()
{
	matrixvectorcalc *mm1 = new matrixvectorcalc();

	std::vector<std::vector<float> > ma1;
	std::vector<std::vector<float> > ma2;

	std::vector<float>a1;
	a1.push_back(1);
	a1.push_back(1);
	a1.push_back(1);

	std::vector<float>a2;
	a2.push_back(1);
	a2.push_back(1);
	a2.push_back(1);

	std::vector<float>a3;
	a3.push_back(1);
	a3.push_back(1);
	a3.push_back(1);


	ma1.push_back(a1);
	ma1.push_back(a2);
	ma1.push_back(a3);

	std::vector<float>b1;
	b1.push_back(1);
	b1.push_back(1);
	b1.push_back(1);

	std::vector<float>b2;
	b2.push_back(1);
	b2.push_back(1);
	b2.push_back(1);

	std::vector<float>b3;
	b3.push_back(1);
	b3.push_back(1);
	b3.push_back(1);


	ma2.push_back(b1);
	ma2.push_back(b2);
	ma2.push_back(b3);

	std::vector<std::vector<float> > matri1;
	matri1 = mm1->additionMatrix(ma1, ma2);


	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			std::cout << matri1[i][j];
		}
		std::cout << std::endl;
	}
}