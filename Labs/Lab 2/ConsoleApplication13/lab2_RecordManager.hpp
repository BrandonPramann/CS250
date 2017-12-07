#pragma once
# ifndef _RECORD_MANAGER_HPP
# define _RECORD_MANAGER_HPP
# include <string >
# include <iostream >
# include <fstream >
# include <stdexcept >
using namespace std;

class RecordManager
{
	public:
	~RecordManager();
		
	void OpenOutputFile(string filename);
	void CloseOutputFile(string filename);
	void WriteToFile(string filename, string text);
	void DisplayAllOpenFiles() noexcept;
		
	private:
	int FindAvailableFile() noexcept;
	int FindFilenameIndex(string filename) noexcept;
			
	ofstream m_outputs[5];
	string m_filenames[5];
	const int MAX_FILES = 5;
	};

# endif