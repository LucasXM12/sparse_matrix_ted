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

int Matrix::Row::rootHeight() {
	return this->columns.rootHeight();
}

void Matrix::Row::delWithKey(const int& key) {
	this->columns.delWithKey(key);
}

int& Matrix::Row::getWithKey(const int& key) {
	return this->columns[key];
}

void Matrix::Row::setWithKey(const int& key, const int& value) {
	this->columns.setWithKey(key, value);
}

Matrix::Matrix(const int& width, const int& height, const int& defaultValue) : width(width),
defaultValue(defaultValue) {
	this->height = height;

	this->lastOperation.row = -1;
	this->lastOperation.column = -1;
}

Matrix::~Matrix() {
	delete &this->matrix;
}

Matrix::Row& Matrix::operator[](const int& row) {
	int lastRow = this->lastOperation.row;
	int lastColumn = this->lastOperation.column;

	int lastValue = this->lastOperation.value;

	this->lastOperation.row = -1;
	this->lastOperation.column = -1;

	if (lastRow != -1 && lastColumn != -1) {
		if (lastValue == this->defaultValue) {
			this->matrix[lastRow].delWithKey(lastColumn);

			if (this->matrix[lastRow].rootHeight() == 0)
				this->matrix.delWithKey(lastRow);
		} else
			this->matrix[lastRow].setWithKey(lastColumn, lastValue);
	}

	this->lastOperation.row = row;

	return this->matrix[row];
}
