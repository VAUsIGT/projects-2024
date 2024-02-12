#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;
string work(double** A, int N, int M, int K) {
	for (int i = 1; i <= N; i++) {//�������� �������
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
					A[i][j] = ((rand() % 199 - 99) * 0.001);//�������� �� -0,1 �� 0,1 (�� -0.099 �� 0.099 �������)
				}
			}
		}
	}
	string a = "�����Ũ��������������������������"; //�������
	string letters = { 0 };//string
	letters[0] = a[K + 4];

	if (letters[0] >= '�' && letters[0] <= '�')
		letters += letters[0] + 32;
	else if (letters[0] == '�')
		letters += '�';

	return letters;
}

void output(double** A, int N, int M) { //����� �������
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

	int K = 4;//�������
	int N = rand() % (K + 1) + 3; //������� ���������� ����� � ��������� [3,3+k]
	int M = rand() % (K + 1) + 3;

	double** A = new double* [N + 1]; //������������ �������
	for (int i = 1; i <= N; i++) {
		A[i] = new double[M + 1];
	}

	ofstream fout("out.txt");
	if (!(fout.is_open())){
		cout << "������ ��������"; //������, ��� �����
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