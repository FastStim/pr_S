#include "main.h"

int main()
{
	int size = 5;
	string* name = new string[size];
	float* krit = new float[size];
	float** mat = new float*[size];
	float** step = new float*[size];
	float** step2 = new float*[size];
	string curName = "";
	
	//Default task

	// mat[0] = new float[size] {0.008, 0.100,  0.500, 44000, 500, 2800000, 0.3, 30};
	// mat[1] = new float[size] {0.010, 0.0625, 0.125, 70000, 700, 3000000, 0.8, 45};
	// mat[2] = new float[size] {0.010, 0.1111, 0.200, 47000, 500, 2550000, 0.2, 19};
	// mat[3] = new float[size] {0.010, 0.1250, 0.050, 49000, 600, 2600000, 0.6, 20};
	// mat[4] = new float[size] {0.008, 0.2000, 0.143, 45000, 400, 2500000, 0.3, 13};
	// mat[5] = new float[size] {0.003, 0.2500, 0.167, 80000, 600, 3300000, 0.1, 92};
	// mat[6] = new float[size] {0.001, 0.7500, 0.038, 85000, 600, 2500000, 0.9, 11};

	// krit[0] = 0.01;
	// krit[1] = 0.1;
	// krit[2] = 0.038;
	// krit[3] = 44000;
	// krit[4] = 400;
	// krit[5] = 2500000;
	// krit[6] = 0.3;
	// krit[7] = 10;

	// name[0] = "Смена";
	// name[1] = "Час Пик";
	// name[2] = "Невское время";
	// name[3] = "Вечерний ПБ";
	// name[4] = "СПБ ведомости";
	// name[5] = "Деловой ПБ";
	// name[6] = "Реклама - Шанс";

	// Egor task

	mat[0] = new float[size] {3.1, 128, 200, 150, -4690};
	mat[1] = new float[size] {2.0, 32,  15,  5,   -750 };
	mat[2] = new float[size] {3.0, 32,  90,  20,  -1070};
	mat[3] = new float[size] {2.0, 8,   27,  12,  -570 };
	mat[4] = new float[size] {3.0, 128, 150, 150, -3220};

	krit[0] = 3.0;
	krit[1] = 32;
	krit[2] = 90;
	krit[3] = 20;
	krit[4] = -4690;

	name[0] = "SanDisk Extreme Go";
	name[1] = "Smart Buy Glossy";
	name[2] = "Qumo Speedster";
	name[3] = "Qumo Tropic Green";
	name[4] = "SanDisk Cruzer Ultra Fit";

	// Julia task

	// mat[0] = new float[size] {234, 59, 144,   1,   9}; 
	// mat[1] = new float[size] {340, 88, 208, 4.5,  10}; 
	// mat[2] = new float[size] {300, 43, 160,   3, 8.5}; 
	// mat[3] = new float[size] {210, 55, 108, 2.9,   3}; 
	// mat[4] = new float[size] {301, 70, 150, 3.3,  11}; 

	// krit[0] = 200; 
	// krit[1] = 50; 
	// krit[2] =150; 
	// krit[3] = 3; 
	// krit[4] = 5;

	// name[0] = "Далматин"; 
	// name[1] = "Ретривер"; 
	// name[2] = "Доберман"; 
	// name[3] = "Корги"; 
	// name[4] = "Спаниель";

	int j = 0;
	for (int i = 0; i < size; i++)
		if (mat[i][0] >= krit[0])
			step[j++] = mat[i];


	int y = 0;
	for(int x = 1; x < size; x++ )
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

					curName = name[i+1];
				}
			}
		}

		j = g;
	}


	cout << endl;
	cout << "\033[33mОтвет:\033[0m " << curName << endl;
	cout << "\033[33mПри значениях:\033[0m ";
	for (int x = 0; x < j; x++)
		for (int i = 0; i < size; i++)
			if (j-1 == x)
				cout<< step[x][i]<<" ";
	cout<<endl;
	return 0;
}


