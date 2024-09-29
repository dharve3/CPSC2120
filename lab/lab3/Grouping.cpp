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
// int main()
// {
//     Grouping input1("input1.txt");
//     input1.printGroups();
    
//     return 0;
// }

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
    // cout << "DEBUG: fileName: " << fileName << endl;
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
            // cout << "DEBUG: " << input << endl;
            num = (input == 'X') ? 1 : 0;
            grid[i][j] = num;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1) {  // If the square is occupied
                vector<GridSquare> newGroup;
                findGroup(i, j, newGroup);  // Group this square and its neighbors
                groups.push_back(newGroup);  // Add the new group to the list of groups
            }
        }
    }
}

void Grouping::findGroup(int r, int c, vector<GridSquare> &currentGroup) { // Implemented recursive method
    // Base case, out of bounds or empty
    if (r < 0 || r >= 10 || c < 0 || c >= 10 || grid[r][c] == 0)
        return;

    // Mark as visited
    grid[r][c] = 0;

    // Add the current square to the current group
    currentGroup.push_back(GridSquare(r, c));

    // Check all 4 directions
    findGroup(r-1, c, currentGroup); // up
    findGroup(r+1, c, currentGroup); // down
    findGroup(r, c-1, currentGroup); // left
    findGroup(r, c+1, currentGroup); // right
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
