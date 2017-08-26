#include "stdafx.h"

#include "Matrix.h"

//Row: ----------------------------------------------------------------------------------

Matrix::Row::Row() {}

Matrix::Row::Row(Matrix* const& father) : father(father), columns() {}

int& Matrix::Row::operator[](const int& column) {
	if (column < 0 || column >= this->father->width)
		throw exception("Invalid column");

	if (!this->columns.existsKey(column))
		this->columns.addNode(column, this->father->defaultValue);

	this->father->lastOperation.column = column;

	this->father->lastOperation.value = this->columns[column];

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

//Matrix: -------------------------------------------------------------------------------

Matrix::Matrix(const int& width, const int& height, const int& defaultValue) : defaultValue(defaultValue), matrix() {
	if (width <= 0)
		throw exception("Invalid width");

	if (height <= 0)
		throw exception("Invalid height");

	this->width = width;
	this->height = height;

	this->lastOperation.row = -1;
	this->lastOperation.column = -1;
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

	if (row < 0 || row >= this->height)
		throw exception("Invalid row");

	if (!this->matrix.existsKey(row))
		this->matrix.addNode(row, Row(this));

	this->lastOperation.row = row;

	return this->matrix[row];
}

int Matrix::treeHeight() {
	return this->matrix.rootHeight();
}
