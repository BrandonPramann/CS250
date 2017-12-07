#ifndef _TESTER_BASE_HPP
#define _TESTER_BASE_HPP

#include <string>
#include <list>
#include <functional>
using namespace std;

struct TestListItem;

class TesterBase
{
	public:
	TesterBase();

	void Start();
	void AddTest( const TestListItem& test );

	protected:
	void MainMenu();
	int TestAll();
	void ReportFailure( const string& test, const string& message );
	void DisplayTestHeader( const string& test );
	void DisplayScore( int totalPasses, int totalTests );

	list<TestListItem> m_tests;
	int m_totalTestCount;
};

struct TestListItem
{
	string name;
	bool testAggregate;
	function<int()> callFunction;


	TestListItem()
	{
        testAggregate = false;
	}

	TestListItem( const string name, function<int()> callFunction, bool testAggregate = false )
	{
		Setup( name, callFunction, testAggregate );
	}

	void Setup( const string& name, function<int()> callFunction, bool testAggregate = false )
	{
		this->name = name;
		this->callFunction = callFunction;
		this->testAggregate = testAggregate;
	}
};

#endif
