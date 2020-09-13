#include "MatrixMaster.h"
#include "CheckData.h"

std::list<std::list<int>>& MatrixMaster::deleteColumn(Matrix& array, int d_col) {
	//d_col - столбец, который следует удалить;

	if (array.empty())
		return array;

	// выход за границы массива
	if (array.begin()->size() <= d_col)
		return array;


	for (Matrix::iterator it_row = array.begin(); it_row != array.end(); it_row++) {
		int n = 0;
		for (Line::iterator it_col = it_row->begin(); it_col != it_row->end(); it_col++, n++) {
			if (n == d_col) {
				it_col = it_row->erase(it_col);
				break;
			}
		}
	}
}

void MatrixMaster::showArray(Matrix& array) {
	for (auto row : array) {
		for (auto col : row) {
			std::cout << col << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int MatrixMaster::findMaxElem(Matrix& array) {
	int max = *array.begin()->begin();
	for (auto row : array)
		for (auto col : row) {
			if (max < col)
				max = col;
		}
	return max;
}

Matrix MatrixMaster::createMatrix() {
	int n = 0, m = 0;
	std::cout << "Get count of rows in the matrix > ";
	n = CheckData<int>::getPosDigit();
	std::cout << "Get count of columns in the matrix > ";
	m = CheckData<int>::getPosDigit();
	std::list<std::list<int>> array;

	for (int i = 0; i < n; i++) {
		array.push_back(Line());
		std::cout << "Get elem of " << i << " row > ";
		for (int j = 0; j < m; j++) {
			int x = CheckData<int>::getDigit();
			array.back().push_back(x);
		}
	}
	return array;
}

std::pair<int, int> MatrixMaster::findElem(Matrix& array, int find) {
	int i = 0, j = 0;
	for (auto& line : array) {
		j = 0;
		for (auto& elem : line) {
			if (elem == find)
				return std::make_pair(i, j);
			j++;
		}
		i++;
	}
	return std::make_pair(-1, -1);
}