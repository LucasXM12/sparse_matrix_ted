#pragma once

#include "Tree.h"

class Matrix {
private:
	typedef struct operation {
		int value;

		int row;
		int column;
	} operation;

	class Row {
	private:
		Matrix* father;
		Tree<int> columns;
	public:
		Row(Matrix*&);
		virtual ~Row();

		int& operator[](const int&);
	};

	Tree<Row> matrix;

	int width;
	int height;

	int defaultValue;

	operation lastOperation;
public:
	Matrix(const int&, const int&, const int&);
	virtual ~Matrix();

	Row& operator[](const int&);
};