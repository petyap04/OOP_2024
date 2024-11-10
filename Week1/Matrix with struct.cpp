#include <iostream>

class Matrix {
private:
	size_t rows = 0;
	size_t colls = 0;
	int** mtx = nullptr;

	void copyFrom(const Matrix& other);
	void moveFrom(Matrix&& other);
	void free();
public:
	Matrix(size_t row, size_t colls);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other)noexcept;

	Matrix& operator=(const Matrix& other);
	Matrix& operator=(Matrix&& other)noexcept;

	void readMatrix();
	Matrix* transp();
	void print(const Matrix& mtx);

	~Matrix();
};

void Matrix::copyFrom(const Matrix& other) {
	rows = other.rows;
	colls = other.colls;
	int** mtx = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = new int[colls];
		mtx[i] = other.mtx[i];
	}
}

void Matrix::moveFrom(Matrix&& other) {
	rows = other.rows;
	colls = other.colls;
	mtx = other.mtx;
	other.mtx = nullptr;
	other.rows = other.colls = 0;
}

void Matrix::free() {
	for (size_t i = 0; i < colls; i++) {
		delete[] mtx[i];
	}
	delete[]mtx;
}

Matrix::Matrix(size_t row, size_t colls) {
	int** mtx = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = new int[colls] {0};
	}
}

Matrix::Matrix(const Matrix& other) {
	copyFrom(other);
}

Matrix::Matrix(Matrix&& other) noexcept
{
	moveFrom(std::move(other));
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Matrix::readMatrix() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < colls; j++) {
			std::cin >> mtx[i][j];
		}
	}
}

Matrix* Matrix::transp() {
	Matrix* trans = new Matrix{colls,rows };
	for (size_t i = 0; i < trans->rows; i++) {
		for (size_t j = 0; j < trans->colls; j++) {
			trans->mtx[i][j] = mtx[j][i];
		}
	}
	return trans;
}

void Matrix::print(const Matrix& mtx)
{
	for (size_t i = 0; i < mtx.rows; i++)
	{
		for (size_t j = 0; j < mtx.colls; j++)
		{
			std::cout << mtx.mtx[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrix::~Matrix()
{
	free();
}

int main() {
	size_t rows, colls;
	std::cin >> rows >> colls;
	Matrix mtx = { rows,colls };
	mtx.readMatrix();
	mtx.print(*(mtx.transp()));
}
