#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));

    ofstream writeToFile("words.txt");
	for (int i = 0; i < 1000; i++)
	{
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;
		int z = rand() % 10 + 10;
		string temp = to_string(x) + " + "  + to_string(y) + " = ans" + to_string(x+y) + " dmg" + to_string(z);
		temp += "\n";
		writeToFile.write(temp.c_str(), temp.size());
	}
	writeToFile.close();
}
