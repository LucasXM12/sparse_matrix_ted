// SparseMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

#include <conio.h>
#include <iostream>

using namespace std;

int main() {
	Matrix test(2147483647, 2147483647, 0);

	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 10000; j++)
			test[i][j] = i + j;

	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 10000; j++)
			test[i][j] = 0;

	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 10000; j++)
			cout << test[i][j] << " ";

	cout << endl << test.treeHeight();

	_getch();

	return 0;
}

