#include "stdafx.h"

#include "Matrix.h"

Matrix::Row::Row(Matrix*& father) : father(father), columns() {}

Matrix::Row::~Row() {
	delete &this->columns;
}

int& Matrix::Row::operator[](const int& column) {
	this->father->lastOperation.column = column;

	return this->father->lastOperation.value;
}