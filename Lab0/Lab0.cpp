#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;
string work(double** A, int N, int M, int K) {
	for (int i = 1; i <= N; i++) {//создание матрицы
		for (int j = 1; j <= M; j++) {
			A[i][j] = 0;
			bool f = false;
			if ((N / 2 + 1 == i) || ((N + 1) / 2 == i)) {
				A[i][j] = K;
				f = true;
			}
			if ((M / 2 + 1 == j) || ((M + 1) / 2 == j)) {
				A[i][j] -= K;
				f = true;
			}
			if (!f) {
				while (A[i][j] == 0) {
					A[i][j] = ((rand() % 199 - 99) * 0.001);//значение от -0,1 до 0,1 (от -0.099 до 0.099 включа€)
				}
			}
		}
	}
	string a = "јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя"; //алфавит
	string letters = { 0 };//string
	letters[0] = a[K + 4];

	if (letters[0] >= 'ј' && letters[0] <= 'я')
		letters += letters[0] + 32;
	else if (letters[0] == '®')
		letters += 'Є';

	return letters;
}

void output(double** A, int N, int M) { //вывод матрицы
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << fixed << setprecision(3) << A[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");

	int K = 4;//вариант
	int N = rand() % (K + 1) + 3; //задание рандомного числа в диапозоне [3,3+k]
	int M = rand() % (K + 1) + 3;

	double** A = new double* [N + 1]; //динамическа€ матрица
	for (int i = 1; i <= N; i++) {
		A[i] = new double[M + 1];
	}

	ofstream fout("out.txt");
	if (!(fout.is_open())){
		cout << "ошибка открыти€"; //доступ, нет места
	}
	else{
		fout << work(A, N, M, K); 
	}
	

	output(A, N, M);
	fout.close();

	for (int i = 1; i <= N; i++) {
		delete A[i];
	}
	delete[] A;
	return 0;
}