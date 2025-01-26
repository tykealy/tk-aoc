#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <regex>
using namespace std;
using namespace std::chrono;

struct Wire
{
    string name;
    string operation;
    string input1;
    string input2;
    unsigned int value = 0;
};

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

vector<Wire> parseInstructions(const string &input)
{
    // Define regex patterns
    regex assignmentRegex(R"((\d+|[a-z]+) -> ([a-z]+))");                                 // Matches `123 -> x`
    regex binaryRegex(R"((\d+|[a-z]+) (AND|OR|LSHIFT|RSHIFT) (\d+|[a-z]+) -> ([a-z]+))"); // Matches `x AND y -> d`
    regex unaryRegex(R"(NOT (\d+|[a-z]+) -> ([a-z]+))");                                  // Matches `NOT x -> h`

    vector<Wire> parsedInstructions;
    smatch match;

    // Split input into lines
    stringstream ss(input);
    string line;
    while (getline(ss, line))
    {
        if (regex_match(line, match, assignmentRegex))
        {
            // Assignment operation
            parsedInstructions.push_back({match[1], "", "ASSIGN", match[2]});
        }
        else if (regex_match(line, match, binaryRegex))
        {
            // Binary operation
            parsedInstructions.push_back({match[1], match[3], match[2], match[4]});
        }
        else if (regex_match(line, match, unaryRegex))
        {
            // Unary operation
            parsedInstructions.push_back({match[1], "", "NOT", match[2]});
        }
    }

    return parsedInstructions;
}

int main()
{
    vector<string> lines = readInput("input.txt");
    // Parse the instructions
    vector<Wire> parsedInstructions;
    for (const auto &line : lines)
    {
        auto parsedLine = parseInstructions(line);
        parsedInstructions.insert(parsedInstructions.end(), parsedLine.begin(), parsedLine.end());
    }

    // Output the parsed instructions
    for (const auto &instr : parsedInstructions)
    {
    }
}