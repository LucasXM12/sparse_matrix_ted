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
		Row();
		Row(Matrix* const&);

		int& operator[](const int&);

		int rootHeight();
		void delWithKey(const int&);
		int& getWithKey(const int&);
		void setWithKey(const int&, const int&);
	};

	Tree<Row> matrix;

	int width;
	int height;

	int defaultValue;

	operation lastOperation;
public:
	Matrix(const int&, const int&, const int&);

	Row& operator[](const int&);

	int treeHeight();
};