#include "main.h"

int compare(float* left, float* right, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (left[i] >= right[i])
			count++;
	}

	// Если количество 0 то сразу игнорим такую строку (передаем 1)
	// Иначе если число равно 0 то отрезаем ту строку с которой сравнивали
	// Если любое другое число то просто записываем в вектор Парето
	if (count == 0) 
		return 1;
	else
		return count - size;
}

vector<float*> logic(float** mat, int size, int nSize)
{
	vector<float*> result;
	for (int i = 0; i < size; ++i)
	{
		if (result.size() < 1)
		{
			result.push_back(mat[i]);
			continue; 
		}

		int cur = compare(mat[i], result[i], nSize);
	}

	return result;
}

int main()
{
	int size = 9;
	int nSize = 6;

	string* name = new string[size];

	float* krit = new float[nSize];
	float** mat = new float*[size];
	
	//Default task

	mat[0] = new float[nSize] {10, 2,   3, 2, 2, 4};
	mat[1] = new float[nSize] { 4, 7,   3, 4, 3, 1};
	mat[2] = new float[nSize] { 6, 8,   3, 5, 4, 2};
	mat[3] = new float[nSize] { 9, 2,   3, 2, 1, 3};
	mat[4] = new float[nSize] { 5, 1, 0.1, 5, 2, 2};
	mat[5] = new float[nSize] { 3, 8, 0.1, 2, 4, 1};
	mat[6] = new float[nSize] { 3, 5,   4, 2, 7, 7};
	mat[7] = new float[nSize] { 3, 6,   3, 4, 4, 1};
	mat[8] = new float[nSize] { 2, 5,   3, 1, 5, 7};

	krit[0] = 0.10;
	krit[1] = 0.20;
	krit[2] = 0.20;
	krit[3] = 0.20;
	krit[4] = 0.20;
	krit[5] = 0.10;

	name[0] = "U1";
	name[1] = "U2";
	name[2] = "U3";
	name[3] = "U4";
	name[4] = "U5";
	name[5] = "U6";
	name[6] = "U7";
	name[7] = "U8";
	name[8] = "U9";

	// Egor task

	// mat[0] = new float[size] {3.1, 128, 200, 150, -4690};
	// mat[1] = new float[size] {2.0, 32,  15,  5,   -750 };
	// mat[2] = new float[size] {3.0, 32,  90,  20,  -1070};
	// mat[3] = new float[size] {2.0, 8,   27,  12,  -570 };
	// mat[4] = new float[size] {3.0, 128, 150, 150, -3220};

	// krit[0] = 0.1;
	// krit[1] = 0.5;
	// krit[2] = 0.2;
	// krit[3] = 0.15;
	// krit[4] = 0.05;

	// name[0] = "SanDisk Extreme Go";
	// name[1] = "Smart Buy Glossy";
	// name[2] = "Qumo Speedster";
	// name[3] = "Qumo Tropic Green";
	// name[4] = "SanDisk Cruzer Ultra Fit";

	// Julia task

	// mat[0] = new float[size] {234, 59, 144,   1,   9}; 
	// mat[1] = new float[size] {340, 88, 208, 4.5,  10}; 
	// mat[2] = new float[size] {300, 43, 160,   3, 8.5}; 
	// mat[3] = new float[size] {210, 55, 108, 2.9,   3}; 
	// mat[4] = new float[size] {301, 70, 150, 3.3,  11}; 

	// krit[0] = 0.1; 
	// krit[1] = 0.3; 
	// krit[2] = 0.15; 
	// krit[3] = 0.25; 
	// krit[4] = 0.2;

	// name[0] = "Далматин"; 
	// name[1] = "Ретривер"; 
	// name[2] = "Доберман"; 
	// name[3] = "Корги"; 
	// name[4] = "Спаниель";

	// solution

	vector<float*> result = logic(mat, size, nSize);

	for (int i = 0; i < result.size(); i++)
		for (int j = 0; j < nSize; j++)
			cout << result[i][j] << endl;

	return 0;
}


