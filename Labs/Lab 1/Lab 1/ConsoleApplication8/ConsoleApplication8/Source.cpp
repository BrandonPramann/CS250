#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> employeeNameToId;
	
	employeeNameToId["Harry"] = 1024;
	employeeNameToId["Ron"] = 256;
	employeeNameToId["Hermione"] = 512;

	string key;
	cout << "Enter an employee name: ";
	cin >> key;

	cout << "That employee's ID is " << employeeNameToId[key] << endl;


	return 0;
}