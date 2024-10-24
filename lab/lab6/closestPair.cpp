/*
 * Name: Dylan Harvey
 * Date Submitted: 10/24/2024
 * Lab Section: 005
 * Assignment Name: Lab 6: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

#define DEBUG 1

using namespace std;

struct point
{
    double x;
    double y;
};

// Helper function to calculate the distance between two points
// May condense into closestPair at some point
auto calcDistance(const point& a, const point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Helper function to print the entire grid (DONT TRY TO USE FOR 250K!!!)
void printGrid(const vector<vector<vector<point>>>& grid) {
    int b = grid.size();
    cout << "Grid contents:" << endl;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            cout << "Cell (" << i << ", " << j << "): ";
            for (const point& p : grid[i][j]) {
                cout << "(" << p.x << ", " << p.y << ") ";
            }
            cout << endl;
        }
    }
}

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file: " << filename << endl;
        return -1;
    }

    int n;
    file >> n; // Number of points
    if (DEBUG) cout << "Number of points: " << n << endl;

    // Calculate b (using sqrt of n)
    int b = static_cast<int>(sqrt(n));
    if (DEBUG) cout << "Grid size (b x b): " << b << "x" << b << endl;

    // 2D Vector of size b x b (triple vector)
    vector<vector<vector<point>>> grid(b, vector<vector<point>>(b));

    // Read the points into the grid
    for (int i = 0; i < n; ++i) {
        point p;
        file >> p.x >> p.y;
        int cellX = static_cast<int>(p.x * b);
        int cellY = static_cast<int>(p.y * b);
        grid[cellX][cellY].push_back(p);

        if (DEBUG) cout << "Point " << i + 1 << ": (" << p.x << ", " << p.y << ") placed in cell (" << cellX << ", " << cellY << ")" << endl;
    }

    file.close();

    if (DEBUG) printGrid(grid);

    // Start the min distance at infinity so it can only go down from here
    double minDistance = numeric_limits<double>::infinity();

    // Iterate through each cell in the grid
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            // Check current and specific neighboring cells
            for (const point& p1 : grid[i][j]) {
                // Only check neighboring cells in a certain order to avoid redundant checks
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int ni = i + dx;
                        int nj = j + dy;

                        // Skip out of bounds cells
                        if (ni < 0 || ni >= b || nj < 0 || nj >= b) continue;

                        // Compare with all points in neighboring cell
                        for (const point& p2 :  grid[ni][nj]) {
                            if (&p1 == &p2) continue; // Don't compare same point
                            double dist = calcDistance(p1, p2);

                            if (DEBUG) cout << "Comparing Point (" << p1.x << ", " << p1.y << ") with Point (" << p2.x << ", " << p2.y << "), Distance: " << dist << endl;

                            if (dist < minDistance) {
                                minDistance = dist;

                                if (DEBUG) cout << "New minimum distance found: " << minDistance << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return minDistance;
}


int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}