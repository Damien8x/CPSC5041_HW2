#include "DynamicList.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// function prototype 
void fileCommand(string command, DynamicList & list);

int main()
{

// string will hold value of inFile line
string command = 0;
// create infile object and open stream to read from "input_trace.txt" 
ifstream inFile;
inFile.open("input_trace.txt");

// retrieve first line of file and convert string to integer.
// value will be argument for DynamicList object and set list's intitial capacity
getline(inFile, command);
int listSize = stoi(command);

// create list object with argument equal to first line of file
DynamicList list(listSize);

// initiate while loop with termination value of "EXIT" (end of file)
while(command != "EXIT")
{
	// retrieve line and assign value to command;
	getline(inFile, command);
		// break if value equal to EXIT
		if(command == "EXIT")	
			break;
	// call method passing reference to list and command (current value of line in file)
	fileCommand(command, list);
}

// close file stream
inFile.close();
return 0;
}

// method designed to handle commands from file input_trace.txt
void fileCommand(string command, DynamicList & list)
{
	// value PRINT calls DynamicList.print_list() method
	if(command == "PRINT")
		list.print_list();
	// value DELETE calls DynamicList.remove_item() method
	else if(command == "DELETE")
		list.remove_item();
	// else statement handles value ADD and all invalid values
	else
	{
		// try/catch to avoid crash for invalid values in file
		try{
			// set size of digits for added integer
			// subtract 4 from command to account for "ADD "
			int strSize = command.length() -4;
			// set value of command to just string value to be added to list
			command = command.substr(4, strSize);
			// convert string to corresponding integer value
			int addInt = stoi(command);
			// add integer to list
			list.add_item(addInt);
		}catch(exception e){cout << "error: command not recognized" << endl;}
	}
}
