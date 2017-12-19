#include "main.h"

/*
Матрица

0.008 0.100 0.500 44000 500 2800000 0.3 30
0.010, 0.0625, 0.125, 70000, 700, 3000000, 0.8, 45
0.010, 0.1111, 0.200, 47000, 500, 2550000, 0.2, 19
0.010, 0.1250, 0.050, 49000, 600, 2600000, 0.6, 20
0.008, 0.2000, 0.143, 45000, 400, 2500000, 0.3, 13
0.003, 0.2500, 0.167, 80000, 600, 3300000, 0.1, 92
0.001, 0.7500, 0.038, 85000, 600, 2500000, 0.9, 11

*/

int main()
{
	float* krit = new float[8];
	float** mat = new float*[8];
	float** step = new float*[8];
	float** step2 = new float*[8];
	
	mat[0] = new float[8] {0.008, 0.100,  0.500, 44000, 500, 2800000, 0.3, 30};
	mat[1] = new float[8] {0.010, 0.0625, 0.125, 70000, 700, 3000000, 0.8, 45};
	mat[2] = new float[8] {0.010, 0.1111, 0.200, 47000, 500, 2550000, 0.2, 19};
	mat[3] = new float[8] {0.010, 0.1250, 0.050, 49000, 600, 2600000, 0.6, 20};
	mat[4] = new float[8] {0.008, 0.2000, 0.143, 45000, 400, 2500000, 0.3, 13};
	mat[5] = new float[8] {0.003, 0.2500, 0.167, 80000, 600, 3300000, 0.1, 92};
	mat[6] = new float[8] {0.001, 0.7500, 0.038, 85000, 600, 2500000, 0.9, 11};

	krit[0] = 0.01;
	krit[1] = 0.1;
	krit[2] = 0.038;
	krit[3] = 44000;
	krit[4] = 400;
	krit[5] = 2500000;
	krit[6] = 0.3;
	krit[7] = 10;

	// 

	int j = 0;
	for (int i = 0; i < 7; i++)
		if (mat[i][0] >= krit[0])
			step[j++] =  mat[i];


	int y = 0;
	for(int x = 1; x < 8; x++ )
	{
		int g = 0;
		for (int i = 0; i < j; i++)
			if (step[i][x] >= krit[x])
				step2[g++] =  step[i];

		step = step2;

		bool cloak = true;
		while(cloak)
		{
			cloak = false;

			for (int i = 0; i < g-1; i++)
			{
				float* temp;
				temp = step[i+1];

				if (temp[x] > step[i][x])
				{
					step[i+1] = step[i];
					step[i] = temp;
					cloak = true;
				}
			}
		}

		j = g;
	}



	cout << "Ответ:" << endl;
	for (int x = 0; x < j; x++){
		for (int i = 0; i < 8; i++){
			cout<< step[x][i]<<" ";
		}
		cout<<endl;
	}
	// cout << "Проект № " << kritFirst->getP() << endl;
	// cout << "e = " << kritFirst->getE() << endl << endl;

	return 0;
}


