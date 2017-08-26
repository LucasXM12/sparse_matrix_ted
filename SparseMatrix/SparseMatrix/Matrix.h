#pragma once

#include "Tree.h"

class Matrix {
private:
	typedef struct lastOperation {
		int value;

		int row;
		int column;
	} lastOperation;

	class Row {
	private:
		Tree<int> columns;
	public:
		int& operator[](const int&);
	};

	Tree<Row> matrix;

	int width;
	int height;

	int defaultValue;

	lastOperation op;
public:
	Matrix(const int&, const int&, const int&);
	virtual ~Matrix();

	Row& operator[](const int&);
};