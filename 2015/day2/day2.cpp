#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

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

vector<int> parseDimensions(const string &line, char delimiter)
{
    vector<int> dims;
    stringstream ss(line);
    string token;

    while (getline(ss, token, delimiter))
    {
        dims.push_back(stoi(token));
    }

    return dims;
}

int calcualte(const vector<vector<int>> &dimensions)
{
    int total = 0;

    for (const vector<int> &dims : dimensions)
    {
        int l = dims[0];
        int w = dims[1];
        int h = dims[2];

        int tie = l * w * h;
        int smallest_perimeter = 2 * (l + w + h - max(max(l, w), h));

        total += tie + smallest_perimeter;
    }

    return total;
}

int main()
{
    vector<string> lines = readInput("input.txt");

    vector<vector<int>> dimensions;

    for (const string &line : lines)
    {
        dimensions.push_back(parseDimensions(line, 'x'));
    }

    cout << calcualte(dimensions) << endl;
}