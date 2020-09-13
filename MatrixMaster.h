#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include <list>
#include <iostream>

typedef std::list < std::list<int>> Matrix;
typedef std::list<int> Line;

class MatrixMaster {
public:
	static std::list <std::list<int>>& deleteColumn(Matrix&, int);
	static void showArray(Matrix&);
	static int findMaxElem(Matrix&);
	static Matrix createMatrix();
	static std::pair<int, int> findElem(Matrix&, int);
};



#endif
