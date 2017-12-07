#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {

	list<string> states;
	
	states.push_back("maine");
	states.push_back("h");
	states.push_back("k");

	// states.sort();
	//states.reverse();
	/*for (list<string>::iterator it = states.begin(); it != states.end(); it++) {
		cout << *it << endl;
	}*/

	for (auto const & state : states) {
		cout << state << endl;
	}
	return 0;
}