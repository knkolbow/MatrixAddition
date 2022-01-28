#include "Matrix.h"

//Constructor
Matrix::Matrix(unsigned int row, unsigned int column) :
	num_of_rows(row), num_of_columns(column)
	{ data.resize(row, std::vector<int>(column, 0)); } //Initialize 2d vector

//Getters
unsigned int Matrix::get_num_of_rows() const { return num_of_rows; }
unsigned int Matrix::get_num_of_columns() const { return num_of_columns; }

//Class member functions
/** Gets value from data based on user inputed indexes
	@param new_i: row index
	@param new_j: column index
	@returns: the value at new_i and new_j index
*/
int Matrix::get(unsigned int new_i, unsigned int new_j) const {
	return data[new_i][new_j];	}

/** Set the value at user inputed indexes
	@param new_i: row index
	@param new_j: column index
	@param new_val: integer value to go in data 2d vector
*/
void Matrix::set(unsigned int new_i, unsigned int new_j, int new_val) { data[new_i][new_j] = new_val; }

//Operators
/** Overloads "Matrix + Matrix"
	@param other: the second operand
	@returns: the addition result
*/
Matrix Matrix::operator + (const Matrix& other) const {
	Matrix result(other.num_of_rows, other.num_of_columns);
	for (unsigned int i = 0; i < result.num_of_rows; i++) {
		for (unsigned int j = 0; j < result.num_of_columns; j++) {
			int this_matrix = get(i, j);
			int other_matrix = other.get(i, j);
			int value = this_matrix + other_matrix;
			result.set(i, j, value);	}
	}
	return result;	}

/** Overloads << operator
	@param out: output stream
	@param m: a matrix to be added
	@returns: the output stream
*/
std::ostream& operator << (std::ostream& out, const Matrix& m) {
	unsigned int rows = m.num_of_rows;
	unsigned int columns = m.num_of_columns;
	int value;
	out << rows << "\t" << columns << "\n\n";
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			value = m.get(i, j);
			out << value;
			if (j == columns - 1) {
				out << std::endl;			}
			else {
				out << "	";	}
		}
	}
	return out;	}
