#pragma once
#include <string>

class Vcxproj
{
public:
	Vcxproj(int ver);

private:
	std::string lineArray;
	void write();

};