#include <iostream>
#include <fstream>
#include <Rpc.h>
#include <string>
#include <vector>
#include <Objbase.h>
#include <Windows.h>

#include "File.h"



bool createVCfilters()
{
	std::string guid[3];
	for (int i = 0; i < 3; i++)
	{
		guid[i] = File::createGUID();
	}

	const int lineAmount = 17;
	std::string lines[lineAmount];
	lines[0] = "<?xml version=\"1.0\" encoding=\"utf - 8\"?>";
	lines[1] = "<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">";

	lines[2] = "<ItemGroup>";

	lines[3] = "<Filter Include=\"Source Files\">";
	lines[4] = "<UniqueIdentifier>{" + guid[0] +"}</UniqueIdentifier>";
	lines[5] = "<Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>";
	lines[6] = "</Filter>";

	lines[7] = "<Filter Include=\"Header Files\">";
	lines[8] = "<UniqueIdentifier>{" + guid[1] + "}</UniqueIdentifier>";
	lines[9] = "<Extensions>h;hh;hpp;hxx;hm;inl;inc;xsd</Extensions>";
	lines[10] = "</Filter>";

	lines[11] = "<Filter Include=\"Resource Files\">";
	lines[12] = "<UniqueIdentifier>{" + guid[2] + "}</UniqueIdentifier>";
	lines[13] = "<Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>";
	lines[14] = "</Filter>";

	lines[15] = "</ItemGroup>";
	lines[16] = "</Project>";

	//File write
	std::fstream filters;
	filters.open("test.vcxproj.filters", std::fstream::out);
	for (int i = 0; i < lineAmount; i++)
	{
		filters << lines[i] << std::endl;
	}
	filters.close();
	//Add Error conditions
	return true;
}

void createVCXPROJ( int ver)
{

}




int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		std::cout << "Not enough args passed: " << argc - 1 << " of 2" << std::endl;
		//Stop Auto Closing
		std::getchar();
		return -1;
	}
	
	std::string exePath = argv[0];
	std::cout << exePath << std::endl;
	std::string projectPath = argv[1];
	std::cout << projectPath << std::endl;
	std::string regenPath = argv[2];
	std::cout << regenPath << std::endl;
	std::cout << "Arg Count: " << argc << std::endl;;

	// Write a ifstream that reads a config file 
	
	//createVCfilters();


	std::vector<std::string> filesFound;
	File::findFile("C:\\Users\\Richard\\Desktop\\Testing files\\C files\\*.h", filesFound);
	
	for (int i = 0; i < filesFound.size(); i++)
	{
		std::cout << filesFound[i].c_str() << std::endl;
	}

	//Stop Auto Closing
	std::getchar();

	return 0;
}