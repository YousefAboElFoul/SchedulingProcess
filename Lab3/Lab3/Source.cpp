
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

//#include <pthread.h/LINUX>

using namespace std;
int main() {
	clock_t start;
	start=clock();//setting 
	int my_num;
	string line;
	ifstream myfile;
	 myfile.open ("pbsinput.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		//num
		}
		myfile.close();
	}

	else cout << "Unable to open file";



	system("Pause");

	return 0;
}