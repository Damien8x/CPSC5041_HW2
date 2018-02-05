#include "DynamicList.h"
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

void fileCommand(string command, DynamicList & list);

int main()
{
string command;
string listSizeString = "";
ifstream inFile;

inFile.open("input_trace.txt");

getline(inFile, listSizeString);
int listSize = stoi(listSizeString);

DynamicList list(listSize);


while(command != "EXIT")
{
	

	getline(inFile, command);
		if(command == "EXIT")	
			break;
	fileCommand(command, list);
}


inFile.close();
return 0;
}

void fileCommand(string command, DynamicList & list)
{
	if(command == "PRINT")
		list.print_list();
	else if(command == "DELETE")
		list.remove_item();
	else
	{
		int strSize = command.length() -4;
		command = command.substr(4, strSize);
		int addInt = stoi(command);
		list.add_item(addInt);
	}
}
