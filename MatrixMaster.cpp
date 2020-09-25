#include "MatrixMaster.h"
#include "CheckData.h"

std::list<std::list<int>>& MatrixMaster::deleteColumn(const int d_col) {
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

void MatrixMaster::showArray() {
	if (array.empty())
		std::cout << "Matrix is empty\n";
	for (auto row : array) {
		for (auto col : row) {
			std::cout << col << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int MatrixMaster::findMaxElem() {
	int max = *array.begin()->begin();
	for (auto row : array)
		for (auto col : row) {
			if (max < col)
				max = col;
		}
	return max;
}

MatrixMaster::MatrixMaster(const int n, const int m) {
	for (int i = 0; i < n; i++) {
		array.push_back(Line());
		std::cout << "Get elem of " << i << " row > ";
		for (int j = 0; j < m; j++) {
			int x = CheckData<int>::getDigit();
			array.back().push_back(x);
		}
	}
}


std::pair<int, int> MatrixMaster::findElem(const int find) {
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