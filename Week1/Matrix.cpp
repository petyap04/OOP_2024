#include <iostream>
using std::cin;
using std::cout;
int** createMatrix(unsigned int rows, unsigned int colls) {
	int** mtx = new int* [rows];
	for (int i = 0; i < rows; i++) {
		mtx[i] = new int[colls] {0};
	}
	return mtx;
}
void readMatrix(int** mtx, unsigned int rows, unsigned int colls) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			cin >> mtx[i][j];
		}
	}
}
void freeMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}
void print(int** mtx, unsigned int rows, unsigned int colls)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
			cout << mtx[i][j] << ' ';
		cout << std::endl;
	}
}
void transpMatrix(int** mtx, unsigned int rows, unsigned int colls) {
	int** transmtx = createMatrix(colls, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			transmtx[j][i]=mtx[i][j];
		}
	}
	print(transmtx, colls, rows);
	freeMatrix(transmtx, colls);
}
void swapRows(int** mtx, unsigned int rows, unsigned int firstRow, unsigned int secondRow) {
	std::swap(mtx[firstRow], mtx[secondRow]);
}
int main()
{
	unsigned int n, m;
	cin >> n >> m;
	int** mtx = createMatrix(n, m);
	readMatrix(mtx, n, m);
	swapRows(mtx, n, 0, 2);
	print(mtx, n, m);
	freeMatrix(mtx, n);
}
