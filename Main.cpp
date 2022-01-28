#include "Matrix.h"

#include <fstream>

using namespace std;

int main() {
	//Open file and check if it opened successfully
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cout << "Error - Nonexisting Input File" << endl;
		system("pause");
		return -1;	}

	//Open output file
	ofstream outputFile("output.txt");

	//Get dimesntions of Matrix
	unsigned int row, column;
	inputFile >> row;
	inputFile >> column;

	//initialize vectors and variables
	int total = row * column;
	vector<int> matrix1;
	vector<int> matrix2;
	int value;

	//Get matrix values from input file and store in vectors
	for (int i = 0; i < total; i++) {
		inputFile >> value;
		matrix1.push_back(value);	}		
	for (int i = 0; i < total; i++) {
		inputFile >> value;
		matrix2.push_back(value);	}

	//Create matrix objects
	Matrix matrixOne(row, column);
	Matrix matrixTwo(row, column);

	//Set matrix objects values using the vectors created
	int k = 0;
	for (unsigned int i = 0; i < row; i++) {
		for (unsigned int j = 0; j < column; j++) {
			value = matrix1[k];
			k++;
			matrixOne.set(i, j, value);		}
	}
	k = 0;
	for (unsigned int i = 0; i < row; i++) {
		for (unsigned int j = 0; j < column; j++) {
			value = matrix2[k];
			k++;
			matrixTwo.set(i, j, value);	}
	}

	//Add the 2 matrix objects and store results in new Matrix object
	Matrix result = matrixOne + matrixTwo;
	
	//Output the result Matrix object
	outputFile << result;
	
	//Close input and output files
	outputFile.close();
	inputFile.close();
	return 0;
}