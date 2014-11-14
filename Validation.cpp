#include "Validation.h"
#include <regex>

using namespace std;

Validate::Validate(void){}

//validates for only letters, numbers and underscores
bool Validate::validFileName(string fileName){

	regex regexCheck("\\w*");

	return regex_match(fileName, regexCheck);

}