#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vectornumbers;
	vectornumbers.push_back(2);
	vectornumbers.push_back(3);
	vectornumbers.push_back(10);

	vectornumbers[0] = 3;

	for (int i = 0; i < vectornumbers.size(); i++) {
		cout << i << "\t" << vectornumbers[i] << endl;
	}


	return 0;
}