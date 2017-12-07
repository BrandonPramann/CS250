#include "TesterBase.hpp"
#include "Menu.hpp"
#include "StringUtil.hpp"

TesterBase::TesterBase()
{
	m_totalTestCount = 0;
	m_output.open( "../test_result.html" );
	m_header.open( "../cuTEST/cutest_header.html" );

	string buffer;
	while ( getline( m_header, buffer ) )
	{
        m_output << buffer << endl;
	}

	m_header.close();
}

TesterBase::~TesterBase()
{
	m_footer.open( "../cuTEST/cutest_base.html" );

	string buffer;
	while ( getline( m_footer, buffer ) )
	{
        m_output << buffer << endl;
	}

	m_footer.close();

    m_output.close();
}

void TesterBase::Start()
{
//	MainMenu();
    TestAll();
}

void TesterBase::TestAll()
{
    for ( list<TestListItem>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        if ( it->testAggregate == false )
        {
            it->callFunction();
        }
    }
}

void TesterBase::AddTest( const TestListItem& test )
{
	m_tests.push_back( test );
	m_totalTestCount++;
}

void TesterBase::StartTestSet( const string& name, const vector<string>& prereqs )
{
    Set_TestSet( name );
    m_subtest_totalTests = 0;
    m_subtest_totalPasses = 0;
    Set_TestPrerequisites( prereqs );
}

void TesterBase::StartTest( const string& description )
{
    Set_TestName( description );
    m_subtest_totalTests++;
    col_actualOutput = "";
    col_expectedOutput = "";
}

void TesterBase::TestFail()
{
    Set_Result( false );
}

void TesterBase::TestPass()
{
    Set_Result( true );
    m_subtest_totalPasses++;
}

int TesterBase::TestResult()
{
    return ( m_subtest_totalPasses == m_subtest_totalTests );
}

void TesterBase::FinishTest()
{
    WriteoutRow();
}

void TesterBase::FinishTestSet()
{
    WriteoutSummary();
}

void TesterBase::Set_TestSet( const string& value )
{
    col_testSet = value;
}

void TesterBase::Set_TestName( const string& value )
{
    col_testName = value;
}

void TesterBase::Set_TestPrerequisites( const vector<string>& prereqs )
{
    col_prerequisites = "";
    for ( unsigned int i = 0; i < prereqs.size(); i++ )
    {
        if ( i != 0 ) { col_prerequisites += ", "; }
        col_prerequisites += prereqs[i];
    }
}

void TesterBase::Set_Result( bool passed )
{
    col_result = ( passed ) ? "passed" : "failed";
}

void TesterBase::Set_ExpectedOutput( const string& variable )
{
    col_expectedOutput += variable + "<br>";
}

void TesterBase::Set_ExpectedOutput( const string& variable, const string& value )
{
    col_expectedOutput += variable + " = " + value + "<br>";
}

void TesterBase::Set_ExpectedOutput( const string& variable, int value )
{
    Set_ExpectedOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_ExpectedOutput( const string& variable, bool value )
{
    Set_ExpectedOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_ActualOutput( const string& variable )
{
    col_actualOutput += variable + "<br>";
}

void TesterBase::Set_ActualOutput( const string& variable, const string& value )
{
    col_actualOutput += variable + " = " + value + "<br>";
}

void TesterBase::Set_ActualOutput( const string& variable, int value )
{
    Set_ActualOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_ActualOutput( const string& variable, bool value )
{
    Set_ActualOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_Comments( const string& value )
{
    col_comments = value;
}

void TesterBase::WriteoutSummary()
{
    m_output << "<tr class='summary'>" << endl;
    m_output << "<td colspan='7' class='summary'>" << endl;
    m_output << "<strong>SUMMARY FOR " << col_testSet << ":</strong>" << endl;
    m_output << m_subtest_totalPasses << " out of " << m_subtest_totalTests << " tests passed" << endl;
    m_output << "</td>" << endl;
    m_output << "</tr>" << endl;
    m_output << "<tr class='spacer'></tr>" << endl;
}


void TesterBase::WriteoutRow()
{
    if ( col_result == "passed" )
        m_output << "<tr class='pass'>" << endl;
    else
        m_output << "<tr class='fail'>" << endl;

    m_output << "<td class='test-set'> " << col_testSet << " </td>" << endl;
    m_output << "<td class='test'> " << col_testName << " </td>" << endl;
    m_output << "<td class='prereq'> " << col_prerequisites << " </td>" << endl;
    m_output << "<td class='result'> " << col_result << " </td>" << endl;
    m_output << "<td class='expected'> " << col_expectedOutput << " </td>" << endl;
    m_output << "<td class='actual'> " << col_actualOutput << " </td>" << endl;
    m_output << "<td class='comments'> " << col_comments << " </td>" << endl;
    m_output << "</tr>" << endl;
}
