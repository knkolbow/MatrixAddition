#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {

public:

	//Constructor
	Matrix(unsigned int = 0, unsigned int = 0);

	//Getters
	unsigned int get_num_of_rows() const;
	unsigned int get_num_of_columns() const;

	//Class member functions
	int get(unsigned int, unsigned int) const;

	void set(unsigned int, unsigned int, int);

	//Operators
	Matrix operator +(const Matrix&) const; //Overloads "Matrix + Matrix"

	friend std::ostream& operator << (std::ostream&, const Matrix&);	//Overloads << operator

private:
	//Data fields
	std::vector<std::vector<int> > data;
	unsigned int num_of_rows;
	unsigned int num_of_columns;
};

#endif