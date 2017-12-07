#include"lab2_RecordManager.hpp"
#include <stdexcept>
RecordManager ::~RecordManager()
{
	for (int i = 0; i < MAX_FILES; i++)
		{
		if (m_outputs[i].is_open())
			{
			m_outputs[i].close();
			}
		}
}
void RecordManager::OpenOutputFile(string filename)
{
	int index = FindAvailableFile();
	if (index == -1) {
		throw runtime_error("No availible files");
	}
	m_outputs[index].open(filename);
	m_filenames[index] = filename;
}
void RecordManager::CloseOutputFile(string filename) {
	int index = FindFilenameIndex(filename);
	if (index == -1) {
		throw runtime_error("File3.txt is not open");
	}
	m_outputs[index].close();
	m_filenames[index] = "";
}
void RecordManager::WriteToFile(string filename, string
	text) {
	int index = FindFilenameIndex(filename);
	if (index == -1) {
		throw runtime_error("Test2.txt is not open");
	}
	m_outputs[index] << text << endl;

}
void RecordManager::DisplayAllOpenFiles() noexcept {
	cout << "Open files: " << endl;
	for (int i = 0; i < MAX_FILES; i++) {


		if (m_outputs[i].is_open()) {
			cout << i << ". " << m_filenames[i] << endl;
		}

	}

}
int RecordManager::FindAvailableFile() noexcept{
	for (int i = 0; i < MAX_FILES; i++) {
		if (m_outputs[i].is_open() == false) {
			return i;
		}
	}
	return -1;

}
int RecordManager::FindFilenameIndex(string filename) noexcept{
	for (int i = 0; i < MAX_FILES; i++) {
		if (m_filenames[i] == filename) {
			return i;
		}
	}
	return -1;
}
