#include "main.h"

int counts = 0;
int tests = 0;

struct values
{
	vector<double> x;
	vector<double> h;
	int type;
};

//Квадратичная функция
double func1(vector<double> x)
{
	return pow((x[0] - x[1]), 2) + pow((x[0] + x[1] - 10), 2) / 9;
}

//Функция розенброка
double func2(vector<double> x)
{
	return 100 * (pow((pow(x[0], 2) - x[1]), 2)) + pow((1 - x[0]),2);
}

//Ассиметричная долина
double func3(vector<double> x)
{
	return pow((x[0]-3)/100, 2)-(x[1]-x[0])+exp(20*(x[1]-x[0]));
}

//Функция пауэлла
double func4(vector<double> x)
{
	return pow((x[0] + 10 * pow(x[1],2)), 2) + 5 * pow((x[2]-x[3]), 2) + pow((x[1] - 2 * x[2]), 4) + 10 * pow((x[0]-x[3]), 4);
}

//Минимальных квадратов
double func5(vector<double> x)
{
	vector<double> a = {0, 0.428, 1, 1.61, 2.09, 3.48, 5.25};
	for (int i = 0; i < 7; i++)
		a[i] *= pow(10, -3);
	vector<double> b = {7.391, 11.18, 16.44, 16.20, 22.2, 24.02, 31.32};


	double sum = 0;
	for (int i = 0; i < 7; i++)
		sum +=pow(((((pow(x[0], 2) + pow(x[1], 2) * a[i] + pow(x[2], 2) * pow(a[i], 2)) / (1 + pow(x[3], 2) * a[i])) - b[i]) / b[i]), 2);

	sum = sum * pow(10, 4);

	return sum;
}

//1 алгоритм спуск
vector<vector<double>> descent(values* val, bool changeStep, bool* stop, double eps)
{
	double (*func)(vector<double> x);

	if (val->type == 1)
		func = func1;
	else if (val->type == 2)
		func = func2;
	else if (val->type == 3)
		func = func3;
	else if (val->type == 4)
		func = func4;
	else if (val->type == 5)
		func = func5;
	else
		func = func1;

	vector<vector<double>> result;
	vector<double> xL = val->x;

	result.push_back(val->x);
	
	for (int i = 0; i < val->x.size(); i++)
	{
		double curF = func(val->x);
		while (true)
		{			
			counts++;

			xL[i] = val->x[i] - val->h[i];
			double leftF = func(xL);
			xL[i] = val->x[i] + val->h[i];
			double rightF = func(xL);

			// if (counts > 150000000 && counts % 1000000 == 0)
			// {
			// 	cout << counts/1000000 << ": " << curF << "|" << leftF << "|" << rightF << endl;
			// }

			if (curF <= leftF && curF <= rightF)
			{
				if (val->h[i] > eps && changeStep)
					val->h[i] /= 2;
				else
					break;
			}
			else if (curF > leftF)
			{
				val->x[i] = val->x[i] - val->h[i];
				break;
			}
			else if (curF > rightF)
			{
				val->x[i] = val->x[i] + val->h[i];
				break;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < val->h.size(); i++)
		if (val->h[i] <= eps)
			count++;

	if (count == val->h.size())
		*stop = true;

	result.push_back(val->x);

	return result;
}

//2 алгоритм поиск по шаблону
vector<double> hookT(vector<vector<double>> x, double alpha, values val, double eps)
{
	vector<double> result;
	int c = 0;
	
	while (true)
	{
		for (int i = 0; i < x[0].size(); i++)
			val.x[i] = x[0][i] + alpha*(x[1][i] - x[0][i]);

		bool stop = false;
		vector<vector<double>> newX;
		newX = descent(&val, false, &stop, eps);

		int count = 0;
		for (int i = 0; i < x[0].size(); i++)
			if (x[1][i] - newX[1][i] <= eps)
				count++;

		if (stop || count == x[0].size())
			break;

		x = newX;
	}

	result = val.x;

	return result;
}

int main()
{	
	//Остановка
	bool stop;
	//Точность вычислений
	double eps = 0.000000000000001;
	//Коэффициент шага
	double alpha = 2;

	//Квадратичная функция
	values quadF;
	quadF.x.push_back(0);
	quadF.x.push_back(1);

	quadF.h.push_back(1);
	quadF.h.push_back(1);
	quadF.type = 1;

	//Функция росзенброка
	values rosenF;
	rosenF.x.push_back(-1.2);
	rosenF.x.push_back(1);

	rosenF.h.push_back(0.1);
	rosenF.h.push_back(0.1);
	rosenF.type = 2;

	// Ассиметричная долина
	values assF;
	assF.x.push_back(0);
	assF.x.push_back(-1);

	assF.h.push_back(0.1);
	assF.h.push_back(0.1);
	assF.type = 3;

	// Функция пауэлла
	values paulF;
	paulF.x.push_back(3);
	paulF.x.push_back(-1);
	paulF.x.push_back(0);
	paulF.x.push_back(1);

	paulF.h.push_back(100);
	paulF.h.push_back(100);
	paulF.h.push_back(100);
	paulF.h.push_back(100);
	paulF.type = 4;

	// Минимальных квадратов
	values mquadF;
	mquadF.x.push_back(2.7);
	mquadF.x.push_back(90);
	mquadF.x.push_back(1500);
	mquadF.x.push_back(10);

	mquadF.h.push_back(10);
	mquadF.h.push_back(10);
	mquadF.h.push_back(10);
	mquadF.h.push_back(10);
	mquadF.type = 5;

	// solution
	counts = 0;
	cout << endl;
	stop  = false;
	while (true)
	{
		vector<vector<double>> x = descent(&quadF, true, &stop, eps);
		if (stop)
			break;
		quadF.x = hookT(x, alpha, quadF, eps);
	}
	cout << "\033[33m" << "Квадратичная функция" << "\033[0m" << endl;
	cout << "\033[32m" << "Значение функции: " << "\033[0m" << func1(quadF.x) << endl;
	cout << "\033[35m" << "При х:" << "\033[0m" << endl;
	cout << quadF.x[0] << endl;
	cout << quadF.x[1] << endl;
	cout << "\033[31m" << "Количество итераций: " << "\033[0m" << counts << endl;

	counts = 0;
	stop  = false;
	while (true)
	{
		vector<vector<double>> x = descent(&rosenF, true, &stop, eps);
		if (stop)
			break;
		rosenF.x = hookT(x, alpha, rosenF, eps);
	}
	cout << endl;
	cout << "\033[33m" << "Функция Розенброка" << "\033[0m" << endl;
	cout << "\033[32m" << "Значение функции: " << "\033[0m" << func2(rosenF.x) << endl;
	cout << "\033[35m" << "При х:" << "\033[0m" << endl;
	cout << rosenF.x[0] << endl;
	cout << rosenF.x[1] << endl;
	cout << "\033[31m" << "Количество итераций: " << "\033[0m" << counts << endl;

	counts = 0;
	stop  = false;
	while (true)
	{
		vector<vector<double>> x = descent(&assF, true, &stop, eps);
		if (stop)
			break;
		assF.x = hookT(x, alpha, assF, eps);
	}
	cout << endl;
	cout << "\033[33m" << "Ассиметричная долина" << "\033[0m" << endl;
	cout << "\033[32m" << "Значение функции: " << "\033[0m" << func3(assF.x) << endl;
	cout << "\033[35m" << "При х:" << "\033[0m" << endl;
	cout << assF.x[0] << endl;
	cout << assF.x[1] << endl;
	cout << "\033[31m" << "Количество итераций: " << "\033[0m" << counts << endl;

	counts = 0;
	stop  = false;
	while (true)
	{
		vector<vector<double>> x = descent(&paulF, true, &stop, eps);
		break;
		if (stop)
			break;
		paulF.x = hookT(x, alpha, paulF, eps);
	}
	cout << endl;
	cout << "\033[33m" << "Функция Пауэлла" << "\033[0m" << endl;
	cout << "\033[32m" << "Значение функции: " << "\033[0m" << func4(paulF.x) << endl;
	cout << "\033[35m" << "При х:" << "\033[0m" << endl;
	cout << paulF.x[0] << endl;
	cout << paulF.x[1] << endl;
	cout << paulF.x[2] << endl;
	cout << paulF.x[3] << endl;
	cout << "\033[31m" << "Количество итераций: " << "\033[0m" << counts << endl;
	
	counts = 0;
	stop  = false;
	while (true)
	{
		vector<vector<double>> x = descent(&mquadF, true, &stop, eps);
		break;
		if (stop)
			break;
		mquadF.x = hookT(x, alpha, mquadF, eps);
	}
	cout << endl;
	cout << "\033[33m" << "Минимальных квадратов" << "\033[0m" << endl;
	cout << "\033[32m" << "Значение функции: " << "\033[0m" << func5(mquadF.x) << endl;
	cout << "\033[35m" << "При х:" << "\033[0m" << endl;
	cout << mquadF.x[0] << endl;
	cout << mquadF.x[1] << endl;
	cout << mquadF.x[2] << endl;
	cout << mquadF.x[3] << endl;
	cout << "\033[31m" << "Количество итераций: " << "\033[0m" << counts << endl;

	return 0;
}