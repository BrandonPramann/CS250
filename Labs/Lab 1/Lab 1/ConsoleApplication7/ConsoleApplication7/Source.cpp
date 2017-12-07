#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	cout << "Enter some text: ";
	string text;
	cin >> text;

	stack<char> letters;

	for (int i = 0; i < text.size(); i++) {
		cout << "Letter " << i << " = " << text[i] << endl;
		letters.push(text[i]);
	}
	cout << endl << "Pop off stack" << endl;

	while (!letters.empty()) {
		cout << letters.top();
		letters.pop();
	}

	return 0;
}