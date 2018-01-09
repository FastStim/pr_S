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

vector<vector<float>> stepL(vector<vector<float>> d, vector<float> w, vector<float> p)
{
	vector<vector<float>> result;
	for (int x = 0; x < p.size(); x++)
	{
		vector<float> lTemp;
		for (int i = 0; i < d.size(); i++)
		{
			float temp = 0;
			for (int j = 0; j < d[i].size(); j++)
			{
				temp += pow(w[j]*(1-d[i][j]), p[x]);
			}
			temp = pow(temp,1/p[x]);
			lTemp.push_back(temp);
		}

		result.push_back(lTemp);
	}

	return result;
}

vector<vector<int>> sort(vector<vector<float>> l)
{
	vector<vector<int>> result;

	for(int i = 0; i < l.size(); i++)
	{
		vector<int> pTemp;
		int temp;
		while((pTemp.size()+1) < l[i].size())
		{
			temp = 0;
			bool test = false;
			while (true)
			{
				test = false;
				for(int x = 0; x < pTemp.size(); x++)
					if (pTemp[x] == temp)
						test = true;

				if(test)
					temp++;
				else
					break;
			}
			
			for (int j = 0; j < l[i].size(); j++)
			{
				if (l[i][temp] < l[i][j])
				{
					if (pTemp.size() > 0)
					{
						bool test = false;
						for(int x = 0; x < pTemp.size(); x++)
							if (pTemp[x] == j)
								test = true;

						if (!test)
							temp = j; 
					}
					else 
					{
						temp = j; 
					}
				}
			}
			pTemp.push_back(temp);
		}
		
		bool test = false;
		temp = 0;
		while (!test)
		{
			test = true;
			for(int x = 0; x < pTemp.size(); x++)
			{
				if (pTemp[x] == temp)
					test = false;
			}
			if (!test)
				temp++;

		}
		pTemp.push_back(temp);
			
		result.push_back(pTemp);
	}

	return result;
}

vector<vector<int>> delLast(vector<vector<int>> k)
{
	vector<vector<int>> result;
	
	while (true)
	{
		bool test = false;
		int iTemp = k[0][k[0].size()-1];

		for (int i = 0; i <  k.size(); i++)
			if (k[i][k[0].size()-1] != iTemp)
				test = true;

		if (!test && k[0].size()-1 > 0)
			for (int i = 0; i <  k.size(); i++)
				k[i].erase(k[i].end()-1, k[i].end());
		else
		{
			result = k;
			break;
		}
	}

	return result;
}

template <class T> 
void printArray(string title, vector<vector<T>> array)
{
	cout << "\033[32m" << title << "\033[0m" << endl << endl;

	for(int i = 0; i < array.size(); i++)
	{
		for(int j = 0; j < array[i].size(); j++)
			cout << array[i][j] << " ";
		cout << endl;
	}

	cout << endl;
}

void print (string title, vector<string> name, vector<float> p, vector<vector<int>> pos)
{
	cout << "\033[32m" << title << "\033[0m" << endl << endl;

	for(int i = 0; i < pos.size(); i++)
	{
		cout << "\033[33m" << p[i] << "\033[0m" << " : ";
		for(int j = 0; j < pos[i].size(); j++)
			if(j+1 < pos[i].size())
				cout << name[pos[i][j]] << "\033[36m" << " > " << "\033[0m";
			else	
				cout << name[pos[i][j]];
		cout << endl;
	}

	cout << endl;
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

	// krit.push_back(2);
	// krit.push_back(4);
	// krit.push_back(8);
	// krit.push_back(6);
	// krit.push_back(10);

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

	// krit.push_back(7);
	// krit.push_back(9);
	// krit.push_back(1);
	// krit.push_back(9);
	// krit.push_back(4);

	// solution
	cout << endl;

	vector<float> max = minMax(mat, 0);
	vector<float> min = minMax(mat, 1);

	vector<vector<float>> d = stepD(mat, max, min);

	printArray("Относительные единицы измерения", d);

	vector<vector<float>> l = stepL(d, krit, p);

	printArray("Расстояние до идеального объекта", l);

	vector<vector<int>> k = sort(l);

	printArray("Массив приоритетов", k);

	vector<vector<int>> ans = delLast(k);

	print("Итоговый результат", name, p, ans);

	return 0;
}