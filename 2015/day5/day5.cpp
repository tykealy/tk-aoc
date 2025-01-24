#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace std::chrono;

vector<string> readInput(const string &filename)
{
    ifstream file(filename);
    vector<string> lines;
    string line;

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

bool is_nice(const string &line)
{
    unordered_map<string, vector<int>> pair_positions;
    bool condition1 = false;
    bool condition2 = false;

    // Check for condition1: at least one letter which repeats with exactly one letter between them
    for (size_t i = 0; i < line.size() - 2; ++i)
    {
        if (line[i] == line[i + 2])
        {
            condition1 = true;
            break;
        }
    }

    // Check for condition2: at least one pair of letters that appears at least twice without overlapping
    for (size_t i = 0; i < line.size() - 1; ++i)
    {
        string pair = line.substr(i, 2);
        if (pair_positions.find(pair) != pair_positions.end())
        {
            for (int pos : pair_positions[pair])
            {
                if (i - pos > 1)
                {
                    condition2 = true;
                    break;
                }
            }
            if (condition2)
                break;
        }
        pair_positions[pair].push_back(i);
    }

    return condition1 && condition2;
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<string> lines = readInput("input.txt");

    int nice = 0;
    for (const string &line : lines)
    {
        if (is_nice(line))
        {
            nice++;
        }
    }

    cout << "Nice strings: " << nice << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}