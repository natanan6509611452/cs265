#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int ** readMatrix(int size) {
	if (size > 10) {
		cout << "Invalid matrix size; cannot create it. " << endl;
		cout << "Bye!";
		abort();
	}

	int** tmpMatrix = new int*[size];

	for (int i = 0; i < size; i++) {
		tmpMatrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			tmpMatrix[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		cout << "Row " << i << " (" << size << " elements) : ";
		string str;
		getline(cin, str);
		stringstream s(str);

		for(int j = 0; s >> str; j++) {
			tmpMatrix[i][j] = stoi(str);
		}
	}

	return tmpMatrix;

}
int ** makeSymmetricMatrix(int **matrix, int size, bool fromLower) {
	int** tmp = new int*[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tmp[i][j] = matrix[i][j];
		}
	}

	switch (fromLower) {
		case false: {
			for (int i = 0; i < size; i++) {
				for (int j = i+1; j < size; j++) {
					tmp[j][i] = tmp[i][j];
				}
			}
			break;
		}
		case true: {
			for (int i = 0; i < size; i++) {
				for (int j = i+1; j < size; j++) {
					tmp[i][j] = tmp[j][i];
				}
			}
			break;
		}
	}
	return tmp;
}

void printMatrix(int **matrix, int size) {
	cout << "Print matrix" << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
bool isSymmetric(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (matrix[j][i] != matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}


void deallocate2DArr(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}


int main() {
	int size;
	cout << "Enter the size of a square matrix (>=1 and <=10): ";
	cin >> size;
	fflush(stdin);
	int **oriMatrix = readMatrix(size);
	printMatrix(oriMatrix, size);
	cout << "This matrix is" << (isSymmetric(oriMatrix, size) ? " " : " NOT ")
	     << "symmetric.\n\n";
	int **uSymMatrix = makeSymmetricMatrix(oriMatrix, size, false);
	printMatrix(uSymMatrix, size);
	cout << "This (fromUpper) matrix is"
	     << (isSymmetric(uSymMatrix, size) ? " " : " NOT ")
	     << "symmetric.\n\n";
	int **lSymMatrix = makeSymmetricMatrix(oriMatrix, size, true);
	printMatrix(lSymMatrix, size);
	cout << "This (fromLower) matrix is"
	     << (isSymmetric(lSymMatrix, size) ? " " : " NOT ")
	     << "symmetric.\n";
// deallocate memory for all created arrays
	deallocate2DArr(oriMatrix, size);
	deallocate2DArr(uSymMatrix, size);
	deallocate2DArr(lSymMatrix, size);
	return 0;
}