#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Validation.h"

using namespace std;

bool convert(string inPath,string outPath);

ifstream inStream;
ofstream outStream;
string line;
string s1 = "<";
string s2 = ">";
int pos;
int pos2;

//main method / driver
int main(){
	
	string path = "C:\\";
	string inPath;
	string outPath;
	string inFileName;
	string outFileName;



	Validate validate;

	while (true){
		std::cout << "Please give name of the .cpp without the file extenision" << endl;
		cin >> inFileName;
		if (validate.validFileName(inFileName) == true){
			break;
		}
		else{
			std::cout << "Please enter a valid file name" << endl;
		}
	}
	inPath = path + inFileName + ".cpp";

	while (true){
		std::cout << "Please enter what you would like the output file to be named" << endl;
		cin >> outFileName;
		if (validate.validFileName(outFileName) == true){
			break;
		}
		else{
			std::cout << "Please enter a valid file name" << endl;
		}

	}
	outPath = path + outFileName + ".html";

	convert(inPath, outPath);

}


struct myE{
	const char* message;
	myE() : message("Struct myE"){}
};
// reads the cpp and converts it to html
bool convert(string inPath, string outPath){



	try{
		inStream.open(inPath);

		std::cout << "fuck" << endl;
		_getch();

		outStream.open(outPath);

	
		if (inStream.fail()){
			cout << "inStream has failed" << endl;
			_getch();
			return false;
		}
		if (outStream.fail()){
			return false;
		}

		outStream << "<PRE>" << endl;

		while (!inStream.eof()){
			getline(inStream, line);
			
			while(true){
				if (line.find(s1) != -1){
					pos = line.find(s1);
	
					line.at(pos) = '&';
					line.insert(pos + 1, "lt");
				
				}
				else{
					break;
				}
			}

			while (true){
				if (line.find(s2) != -1){
					pos2 = line.find(s2);
					
					line.at(pos2) = '&';
					line.insert(pos2 + 1, "gt");

				}
				else{
					break;
				}
			}
			
			std::cout << line << endl;
			outStream << line << endl;
		}
		outStream << "</PRE>" << endl;

		_getch();

		inStream.close();
		outStream.close();
		myE mye;
		throw mye;

	}
	catch (myE e){
		std::cout << "Caught myE" << e.message << endl;
	}
	catch (exception e){
		std::cout << "Libary exception thrown" << endl;
	}
	catch (...){
		std::cout << "Default exception thrown" << endl;
	}
	return true;

}