#include <string>
#include <vector>
#include <iostream>

#pragma once

namespace File
{

	std::string createGUID()
	{
		char* guidString;
		GUID guid;
		CoCreateGuid(&guid);
		UuidToStringA(&guid, (RPC_CSTR*)&guidString);
		return std::string(guidString, 36);
	}

	// Do not modify below here, unless you like a 4 hour WIN32 API adventure
	bool findFile(std::string, std::vector<std::string>&);
	void findFile(HANDLE&, std::vector<std::string>&);

	bool findFile(std::string searchString, std::vector<std::string> &results)
	{
		WIN32_FIND_DATAA currentFileData;
		HANDLE searchIterator;

		std::cout << "Search String is: " << searchString.c_str() << std::endl;
		searchIterator = FindFirstFileA(searchString.c_str(), &currentFileData);
		//(LPCTSTR)searchString.c_str()
		if (searchIterator != INVALID_HANDLE_VALUE)
		{
			results.push_back((char*)(currentFileData.cFileName));
			findFile(searchIterator, results);
		}
		else
		{
			//No file found or internal error
			std::cout << "Search String not found once: " << GetLastError;
			return false;
		}

		//At least one file was found
		return true;
	}

	void findFile(HANDLE &searchIterator, std::vector<std::string> &results)
	{
		// This is a pointer so we can delete it straight away without overflowing the recursive function
		WIN32_FIND_DATAA currentFileData;

		

		if (FindNextFileA(searchIterator, &currentFileData) != 0) {
			results.push_back((char*)currentFileData.cFileName);
			findFile(searchIterator, results);
		}
	}
}