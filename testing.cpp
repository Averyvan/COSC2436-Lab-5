#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	string test = "test";
	cout<<(typeid(string).name() == typeid(test).name())<<endl;
}
