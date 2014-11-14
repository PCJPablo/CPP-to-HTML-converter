#ifndef Validation_H
#define Validation_H

#include <string>
using namespace std;

class Validate{
	
private:
	string fileName;
	
public:
	Validate();
	bool validFileName(string fileName);
};
#endif // !Validation_H
