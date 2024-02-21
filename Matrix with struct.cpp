#include <iostream>
int** createMatrix(size_t rows, size_t colls)
{
	int** mtx = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = new int[colls] {0};
	}
	return mtx;
}
struct Matrix
{
	size_t rows;
	size_t colls;
	int** mtx = createMatrix(rows, colls);
};
void readMatrix(Matrix& mtx)
{
	for (size_t i = 0; i < mtx.rows; i++)
	{
		for (size_t j = 0; j < mtx.colls; j++)
		{
			std::cin >> mtx.mtx[i][j];
		}
	}
}
Matrix& transp(Matrix& trans, const Matrix& mtx)
{
	for (size_t i = 0; i < trans.rows; i++)
	{
		for (size_t j = 0; j < trans.colls; j++)
		{
			trans.mtx[i][j] = mtx.mtx[j][i];
		}
	}
	return trans;
}
void printMatrix(const Matrix& mtx)
{
	for (size_t i = 0; i < mtx.rows; i++)
	{
		for (size_t j = 0; j < mtx.colls; j++)
		{
			std::cout << mtx.mtx[i][j]<<" ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	size_t rows, colls;
	std::cin >> rows >> colls;
	Matrix mtx = { rows,colls,createMatrix(rows,colls) };
	readMatrix(mtx);
	Matrix trans = { colls,rows,createMatrix(colls,rows) };
	transp(trans, mtx);
	printMatrix(trans);
}