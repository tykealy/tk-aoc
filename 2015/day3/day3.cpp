#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Main function
int main()
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Open the input file
    ifstream file("input.txt");

    // Read the input
    string input;
    file >> input;

    map<int, int> grid;
    char up = '^';
    char down = 'v';
    char left = '<';
    char right = '>';

    vector<int> position = {0, 0};
    vector<int> robot_santa = {0, 0};
    grid[0] = 1;

    bool santa = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == up)
        {
            if (santa)
            {
                position[0]++;
                int encode = position[0] * 100000 + position[1];
                grid[encode]++;
                santa = false;
            }
            else
            {
                robot_santa[0]++;
                int encode = robot_santa[0] * 100000 + robot_santa[1];
                grid[encode]++;
                santa = true;
            }
        }
        else if (input[i] == down)
        {
            if (santa)
            {
                position[0]--;
                int encode = position[0] * 100000 + position[1];
                grid[encode]++;
                santa = false;
            }
            else
            {
                robot_santa[0]--;
                int encode = robot_santa[0] * 100000 + robot_santa[1];
                grid[encode]++;
                santa = true;
            }
        }
        else if (input[i] == left)
        {
            if (santa)
            {
                position[1]--;
                int encode = position[0] * 100000 + position[1];
                grid[encode]++;
                santa = false;
            }
            else
            {
                robot_santa[1]--;
                int encode = robot_santa[0] * 100000 + robot_santa[1];
                grid[encode]++;
                santa = true;
            }
        }
        else if (input[i] == right)
        {
            if (santa)
            {
                position[1]++;
                int encode = position[0] * 100000 + position[1];
                grid[encode]++;
                santa = false;
            }
            else
            {
                robot_santa[1]++;
                int encode = robot_santa[0] * 100000 + robot_santa[1];
                grid[encode]++;
                santa = true;
            }
        }
    }

    cout << grid.size() << endl;

    // End timing and calculate duration
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;
}
