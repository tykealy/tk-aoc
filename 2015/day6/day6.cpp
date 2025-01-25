#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <map>
#include <regex>
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

struct Command
{
    std::string key;
    std::pair<int, int> c1;
    std::pair<int, int> c2;
};

std::vector<Command> extractCommands(const std::vector<std::string> &inputs)
{
    std::vector<Command> commands;
    std::regex pattern(R"((off|on|toggle) (\d+),(\d+) through (\d+),(\d+))");

    for (const auto &input : inputs)
    {
        std::smatch matches;
        if (std::regex_search(input, matches, pattern))
        {
            Command cmd;
            cmd.key = matches[1];
            cmd.c1 = {std::stoi(matches[2]), std::stoi(matches[3])};
            cmd.c2 = {std::stoi(matches[4]), std::stoi(matches[5])};
            commands.push_back(cmd);
        }
    }
    return commands;
}

int main()
{
    auto start = high_resolution_clock::now();
    vector<string> lines = readInput("input.txt");

    map<int, int> grids = {};

    vector<Command> commands = extractCommands(lines);

    for (const auto &cmd : commands)
    {

        for (int i = cmd.c1.first; i <= cmd.c2.first; i++)
        {
            for (int j = cmd.c1.second; j <= cmd.c2.second; j++)
            {

                int key = i * 1000 + j;
                if (cmd.key == "on")
                {
                    grids[key] = grids[key] + 1;
                }
                else if (cmd.key == "off")
                {
                    if (grids[key] > 0)
                        grids[key] = grids[key] - 1;
                }
                else
                {
                    grids[key] = grids[key] + 2;
                }
            }
        }
    }

    int count = 0;
    for (const auto &grid : grids)
    {
        if (grid.second)
        {
            count = count + grid.second;
        }
    }

    cout << "Total lights on: " << count << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Duration: " << duration.count() << "ms" << endl;

    return 0;
}