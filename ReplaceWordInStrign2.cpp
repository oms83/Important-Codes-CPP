#include<iostream>
#include<string>
using namespace std;

int main()
{
    string S = "Mohammed Abu-Hadhoud I'm From Jordan , welcome to Jordan";
	string WordToReplace = "Jordan";
	string  ReplaceTo = "USE";
	short pos = 0;
	while ((pos = S.find(WordToReplace)) != std::string::npos)
	{
	   
		S.erase(pos,WordToReplace.length());
		S.insert(pos, ReplaceTo);
    }
	
	cout << S;
}