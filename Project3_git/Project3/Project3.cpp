//#include "Project3.h"
#include <iostream>
#include <fstream>
#include <func.hpp>

using namespace std;

int main()
{
	ifstream in("input.txt");
	if (!in.is_open())
	{
		cout << "file error =(" <<endl;
	}
	cout << sum(2, 3);
	return 0;
}
