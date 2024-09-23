/*
 * Name: Dylan Harvey
 * Date Submitted: 9/--/2024
 * Lab Section: 005
 * Assignment Name: Lab 3: Finding Groups Using Recursion
 */

#include "Grouping.h"

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below






//Simple main function to test Grouping
//Be sure to comment out main() before submitting
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

Grouping::Grouping(string fileName) { // Implemented Constructor to read file
    cout << "DEBUG: fileName: " << fileName << endl;
    ifstream infile(fileName); // Open file
    if (!infile.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    char input;
    int num;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            infile >> input;
            cout << "DEBUG: " << input << endl;
            num = (input == 'X') ? 1 : 0;
            grid[i][j] = num;
        }
    }

    // TEST TO PRINT
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Grouping::findGroup(int r, int c) { // Implemented recursive method

}

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}
