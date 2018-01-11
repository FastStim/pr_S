#include "main.h"

int compare(vector<float> left, vector<float> right)
{
	int size = left.size();
	int count = 0;
	
	for (int i = 0; i < size; i++)
		if (left[i] > right[i])
			count++;
	// Если количество 0 то сразу игнорим такую строку (передаем 1)
	// Иначе если число равно 0 то отрезаем ту строку с которой сравнивали
	// Если любое другое число то просто записываем в вектор Парето
	if (count == 0) 
		return 1;
	else
		return count - size;
}

vector<vector<float>> logic(vector<vector<float>> mat)
{
	vector<vector<float>> result;

	for (int i = 0; i < mat.size(); ++i)
	{
		if (result.size() < 1)
		{
			result.push_back(mat[i]);
			continue; 
		}

		bool mid = false;
		int cur;
		for (int j = 0; j < result.size(); j++)
		{
			cur = compare(mat[i], result[j]);
			if (cur == 1) {
				mid = false;
				break;
			}

			if (cur == 0)
			{
				result.erase(result.begin() + j);
				mid = true;
			}

			if (cur < 0)
				mid = true;
		}		

		if (mid && cur != 1 )
			result.push_back(mat[i]);
	}

	return result;
}

void addSpace(int size, int fSize)
{
	while (size < fSize)
	{
		cout << " ";
		size++;
	}
}

void print (vector<string> name, vector<vector<float>> result)
{
	int sizeN = 0;

	for (int i = 0; i < name.size(); i++)
		if (sizeN < name[i].length())
			sizeN = name[i].length();

	for (int i = 0; i < result.size(); i++)
	{
		cout << "\033[33m" << name[i];
		addSpace(name[i].size(), sizeN);
		cout << " " << "\033[0m";
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	vector<vector<float>> mat;
	vector<string> name;
	
	//Default task
	mat.push_back({10, 2,   3, 2, 2, 4});
	mat.push_back({ 4, 7,   3, 4, 3, 1});
	mat.push_back({ 6, 8,   3, 5, 4, 2});
	mat.push_back({ 9, 2,   3, 2, 1, 3});
	mat.push_back({ 5, 1, 0.1, 5, 2, 2});
	mat.push_back({ 3, 8, 0.1, 2, 4, 1});
	mat.push_back({ 3, 5,   4, 2, 7, 7});
	mat.push_back({ 3, 6,   3, 4, 4, 1});
	mat.push_back({ 2, 5,   3, 1, 5, 7});

	name.push_back("U1");
	name.push_back("U2");
	name.push_back("U3");
	name.push_back("U4");
	name.push_back("U5");
	name.push_back("U6");
	name.push_back("U7");
	name.push_back("U8");
	name.push_back("U9");

	// Egor task

	// mat.push_back({3.1, 128, 200, 150, -4690});
	// mat.push_back({2.0, 32,  15,  5,   -750 });
	// mat.push_back({3.0, 32,  90,  20,  -1070});
	// mat.push_back({2.0, 8,   27,  12,  -570 });
	// mat.push_back({3.0, 128, 150, 150, -3220});

	// name.push_back("SanDisk Extreme Go");
	// name.push_back("Smart Buy Glossy");
	// name.push_back("Qumo Speedster");
	// name.push_back("Qumo Tropic Green");
	// name.push_back("SanDisk Cruzer Ultra Fit");

	// Julia task

	// mat.push_back({234, 59, 144,   1,   9});
	// mat.push_back({340, 88, 208, 4.5,  10});
	// mat.push_back({300, 43, 160,   3, 8.5});
	// mat.push_back({210, 55, 108, 2.9,   3});
	// mat.push_back({301, 70, 150, 3.3,  11});

	// name.push_back("Далматин"); 
	// name.push_back("Ретривер"); 
	// name.push_back("Доберман"); 
	// name.push_back("Корги"); 
	// name.push_back("Спаниель");

	// solution

	vector<vector<float>> result = logic(mat);

	print(name, result);

	return 0;
}


