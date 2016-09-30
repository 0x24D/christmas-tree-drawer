#include <iostream> //for cin and cout
#include <cassert> //for assert
#include <iomanip> //for endl and setw/setfill
#include <ctime> //for current time
#include <string> //for outputting a string, month
#include <Windows.h> //for colour
using namespace std;

int main()
{
	const char BLANK(' '); //setting blank character
	const char LEAF('#'); //setting leaf character
	const char WOOD('!'); //setting wood character
	const char EOL('\n'); //setting end of line character
	void getValidHeight(int&); //procedure declaration with int i/o parameter
	void drawBranches(int&, int, const char, const char, const char); //procedure declaration with int i/o, int input and 3 const char input parameters
	void drawTrunk(int, const char, const char, const char); //procedure declaration with int input and 3 const char input parameters
	int treeHeight; //local variable, used in 4 procedures
	int branchLine; //local variable used in 2 procedures
	char answer; //for repeat tree answer
	time_t now = time(0);
	char* dateTime = ctime(&now);
	tm *ltm = localtime(&now);
	string month; //to convert month number into month name (1 -> January)
	switch (ltm->tm_mon){
	case(0) :
		month = "January"; break;
	case(1) :
		month = "February"; break;
	case(2) :
		month = "March"; break;
	case(3) :
		month = "April"; break;
	case(4) :
		month = "May"; break;
	case(5) :
		month = "June"; break;
	case(6) :
		month = "July"; break;
	case(7) :
		month = "August"; break;
	case(8) :
		month = "September"; break;
	case(9) :
		month = "October"; break;
	case(10) :
		month = "November"; break;
	case (11) :
		month = "December";
	}
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo); //getting current colour
	wOldColorAttrs = csbiInfo.wAttributes;
	cout << "Daniel Longfield - " << ltm->tm_mday << " " << month << " " << 1900 + ltm->tm_year << ", " << ltm->tm_hour << ":" <<ltm->tm_min << ":" << setw(2) << setfill('0') <<ltm->tm_sec << endl;
	getValidHeight(treeHeight); //call to procedure, passing treeHeight variable (set as int i/o)
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); //setting font colour to green and background to blue
	drawBranches(branchLine,treeHeight, BLANK, LEAF, EOL); //call to procedure, passing branchLine, treeHeight, BLANK, LEAF and EOL variables (set as int i/o, int input and 3 const char inputs)
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE); //setting font colour to red and background to blue
	drawTrunk(treeHeight, BLANK, WOOD, EOL); //call to procedure, passing treeHeight, BLANK, WOOD and EOL variables (set as int input and 3 const char inputs)
	SetConsoleTextAttribute(h, wOldColorAttrs); //setting colours back to original
	cout << "Would you like another tree? (Y/N) ";
		cin >> answer;
		while ((answer == 'Y') || (answer == 'y')){
			getValidHeight(treeHeight);
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); //setting font colour to green and background to blue
			drawBranches(branchLine, treeHeight, BLANK, LEAF, EOL);
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE); //setting font colour to red and background to blue
			drawTrunk(treeHeight, BLANK, WOOD, EOL);
			SetConsoleTextAttribute(h, wOldColorAttrs); //setting colours back to original
			cout << "Would you like another tree? (Y/N) ";
			cin >> answer;
		}
	system("pause"); //halt system
	return(0); //return error code 0
}

void getValidHeight(int& treeHeight) //get valid height, store in treeHeight variable (main.treeHeight)
{
	cout << "Enter the size of the tree (4-20): ";
	cin >> treeHeight; //input to treeHeight local variable (getValidHeight.treeHeight)
	while ((treeHeight < 4) || (treeHeight > 20)){ //checking for valid height (4-20)
		cout << "\nERROR: Invalid height! Enter the size of the tree(4 - 20): ";
		cin >> treeHeight; //input to treeHeight local variable (getValidHeight.treeHeight)
	}
}

void drawBranches(int& branchLine, int treeHeight, const char BLANK, const char LEAF, const char EOL) //draw branches using the characters that are passed using parameters, then store number of branches in branchLine variable (main.branchLine)
{
	void drawABranch(int, int, const char, const char, const char); //procedure declaration with 2 int inputs and 3 const char inputs
	assert((treeHeight >= 4) && (treeHeight <= 20)); //validating treeHeight 
cout << EOL; //output end of line character
		for (branchLine = 1; branchLine <= (treeHeight - 2); ++branchLine) //tracking tree height (treeHeight - 2, for trunk)
			drawABranch(treeHeight, branchLine, BLANK, LEAF, EOL); //call to procedure, passing treeHeight, branchLine, BLANK, LEAF and EOL variables (set as 2 int inputs and 3 const char inputs)
}

void drawABranch(int treeHeight, int branchLine, const char BLANK, const char LEAF, const char EOL)
{
	for (int spaces = treeHeight - (branchLine + 2); spaces != 0; --spaces) //tracking number of blank characters needed
		cout << BLANK; //outputting blank characters on the left hand side, to shape tree
	for (int leaves = branchLine + (branchLine - 1); leaves != 0; --leaves) //tracking number of leaf characters needed
		cout << LEAF; //outputting leaf characters
	for (int spaces = treeHeight - (branchLine + 2); spaces != 0; --spaces) //tracking number of blank characters needed
		cout << BLANK; //outputting blank characters on the right hand side, for square background
	cout << EOL; //outputting end of line character
}

void drawTrunk(int treeHeight, const char BLANK, const char WOOD, const char EOL)
{
	assert((treeHeight >= 4) && (treeHeight <= 20)); //validating treeHeight
int trunkLine = 1; //set trunkLine as 1
while (trunkLine <= 2){ //continue if trunkLine has a value of 2 or less
	int spaces = 1; //set spaces as 1
		while (spaces <= (treeHeight - 3)){ //calculating the amount of spaces needed to be in the middle of the tree
			cout << BLANK; //outputting blank character
			spaces += 1; //increment spaces by 1
		}
	cout << WOOD; //outputting wood character
	spaces = 1; //set spaces as 1
	while (spaces <= (treeHeight - 3)){ //calculating the amount of spaces needed to be on the right side of the trunk
		cout << BLANK; //outputting blank character
		spaces += 1; //increment spaces by 1
	}
	cout << EOL; //outputting end of line character
	trunkLine += 1; //increment trunkLine by 1, only allows for 2 wood characters to be output
	}
cout << EOL; //outputting end of line character
}