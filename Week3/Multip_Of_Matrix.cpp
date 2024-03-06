#include <iostream>
#include <fstream>
constexpr int ROWS = 3;
constexpr int COLLS = 3;

void fillArr(int arr[][COLLS], std::ifstream& file) {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++)
		{
			file >> arr[i][j];
			char ch = file.get();
			if (ch == '|') {
				break;
			}
			if (file.eof()) {
				return;
			}
		}
	}
}
int multOfRowsAndColls(const int arr1[][COLLS], const int arr2[][COLLS], int indexRow, int indexColl ) {
	int result = 0;
	for (int i = 0; i < COLLS; i++) {
		result += arr2[i][indexColl] * arr1[indexRow][i];
	}
	return result;
}
void multiplOfTwoArr(const int arr1[][COLLS], const int arr2[][COLLS], int result[][COLLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			result[i][j] = multOfRowsAndColls(arr1, arr2, i, j);
		}
	}
}
void print(int mtx[][COLLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS ; j++)
			std::cout << mtx[i][j] << ' ';
		std::cout << std::endl;
	}
}

void multiplucationOfMatrixInTwoFiles(const char* source1, const char* source2, const char* result) {
	std::ifstream firstFile(source1);
	std::ifstream secondFile(source2);

	if (!firstFile.is_open() && !secondFile.is_open()) {
		return;
	}

	int arr1[ROWS][COLLS]{ 0 };
	int arr2[ROWS][COLLS]{ 0 };
	fillArr(arr1, firstFile);
	fillArr(arr2, secondFile);

	firstFile.close();
	secondFile.close();

	int resultarr[ROWS][COLLS]{ 0 };
	multiplOfTwoArr(arr1, arr2, resultarr);
	std::ofstream resultFile(result);
	if(!resultFile.is_open()) {
		return;
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			resultFile << resultarr[i][j];
			if (j != COLLS - 1) {
				resultFile << ",";
			}
		}
		if (i != ROWS - 1) {
			resultFile << "|";
		}
	}
	resultFile.close();
}
int main()
{
	multiplucationOfMatrixInTwoFiles("fst.txt", "snd.txt", "result.txt");
}
