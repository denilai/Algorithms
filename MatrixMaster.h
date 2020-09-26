#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include <list>
#include <iostream>

typedef std::list < std::list<int>> Matrix;
typedef std::list<int> Line;

class MatrixMaster {
private:
	Matrix array;
public:
	MatrixMaster(const int n, const int m);
	void deleteColumn(const int);
	void showArray();
	int findMaxElem();
	std::pair<int, int> findElem(const int);
};



#endif
