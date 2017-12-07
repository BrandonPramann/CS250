#include <iostream> // required for cout
#include <string> // required for strings
#include <queue> // required for queues
using namespace std;

int main()
{
	float balance = 0.0;
	queue<float> transactions;
	transactions.push(100.42);
	transactions.push(-5.58);
	transactions.push(50.78);
	transactions.push(-20.50);
	while (!transactions.empty()) {
		cout << transactions.front() << " pushed to account" << endl;
		balance += transactions.front();
		transactions.pop();
	}
	cout << endl << "Final balance : $" << balance << endl;
	return 0;
}