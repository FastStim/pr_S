#include "main.h"


vector<float> minMax(vector<vector<float>> mat, int type = 0)
{
	vector<float> result (mat[0].size(), INT_MIN);

	if (type == 1)
		for (int i = 0; i < result.size(); i++)
			result[i] = INT_MAX;

	for (int i = 0; i < mat.size(); i++)
		for (int j = 0; j < mat[i].size(); j++)
			if (type == 0 && result[j] < mat[i][j])
				result[j] = mat[i][j];
			else if (type == 1 && result[j] > mat[i][j])
				result[j] = mat[i][j];

	return result;
}

vector<vector<float>> stepD(vector<vector<float>> mat, vector<float> max, vector<float> min)
{
	vector<vector<float>> result;
	for (int i = 0; i < mat.size(); i++)
	{
		vector<float> temp;
		for (int j = 0; j < mat[i].size(); j++)
		{
			temp.push_back((max[j]-mat[i][j])/(max[j]-min[j]));
		}
		result.push_back(temp);
	}

	return result;
}

vector<vector<float>> stepL(vector<vector<float>> d, vector<float> krit, vector<float> p)
{
	vector<vector<float>> result;
	for (int i = 0; i < d.size(); i++)
	{
		vector<float> temp;
		for (int j = 0; j < d[i].size(); j++)
		{
			
		}
		result.push_back(temp);
	}

	return result;
}

int main()
{

	vector<vector<float>> mat;
	vector<float> krit;
	vector<string> name;

	vector<float> p = {1, 2, 3, 5, 15};
	
	//Default task
	mat.push_back({ 5.0, 1.0,  50.0});
	mat.push_back({10.0, 1.5,  40.0});
	mat.push_back({ 2.0, 1.5,  90.0});
	mat.push_back({ 1.0, 1.0, 100.0});
	mat.push_back({ 6.0, 3.0, 100.0});
	mat.push_back({16.0, 3.5,  50.0});

	name.push_back("МКО1");
	name.push_back("МКО2");
	name.push_back("МКО3");
	name.push_back("МКО4");
	name.push_back("МКО5");
	name.push_back("МКО6");

	krit.push_back(6);
	krit.push_back(6);
	krit.push_back(2);

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
	vector<float> max = minMax(mat, 0);
	vector<float> min = minMax(mat, 1);

	// for(int i = 0; i < max.size(); i++)
	// 	cout<< max[i] << " ";
	// cout << endl;
	// for(int i = 0; i < max.size(); i++)
	// 	cout<< min[i] << " ";
	// cout << endl;

	vector<vector<float>> d = stepD(mat, max, min);

	// for(int i = 0; i < d.size(); i++){
	// 	for(int j = 0; j < d[i].size(); j++)
	// 		cout<< d[i][j] << " ";
	// 	cout << endl;
	// }

	vector<vector<float>> l = stepL(d, krit, p);

	// print(name, result);

	return 0;
}


