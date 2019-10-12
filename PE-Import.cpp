#include<string>
#include<iostream>
#include<fstream>
using namespace std;
#define FILENAME "PE-1.txt"
#define CONTENT "I want to learn PE file format!"
int main()
{
	//char buffer[256];
	fstream _file;
	_file.open(FILENAME, ios::in| ios::out);
	
	if (!_file)
	{
		cout << FILENAME << "no PE-1.txt";
		ofstream fout(FILENAME);
		if (fout)
		{ 
			cout << "create PE-1.txt" << endl;
			fout << "I want to learn PE file format!" << endl;
			fout.close();
		}
	}
	else
	{
		cout << FILENAME << "PE-1.txt exists"<<endl;
		int flag = 0;
		string str((std::istreambuf_iterator<char>(_file)),
			std::istreambuf_iterator<char>());
		//cout << "str="<<str << endl;
		string::size_type found = str.find("I want to learn PE file format!");
		//cout << found << endl;
		//cout << str.npos << endl;
		if (found ==str.npos)
		{
			cout << "can not find, writing content to the file" << endl;
			_file << "I want to learn PE file format!" << endl;
		}
		else {
			cout << "find the string. the content of PE-1.txt is:"<<str<<endl;
		}
	}
	system("pause");
	return 0;
}
