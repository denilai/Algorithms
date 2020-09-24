#ifndef COMPARE
#define COMPARE
#include <math.h>
#include "Person.h"

struct CompData {                             // функтор сравнения 
private:
	void setDirection(const std::string &dir);
	PersonField field;
	std::string direction = "increase";
	bool compare(Person&, Person&);

public:
	CompData(const PersonField field, const bool & direction = true);
	bool operator()(Person& f, Person& g) {
		bool ret = compare(f, g);
		return direction == "increase" ? ret : !ret;
	}
};
#endif 