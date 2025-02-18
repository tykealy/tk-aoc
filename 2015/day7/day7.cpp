#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <typeinfo>
using namespace std;

unordered_map<string, vector<string>> parseInput(const string &filename)
{
    ifstream file(filename);
    unordered_map<string, vector<string>> instructions;
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string token, lhs, op, rhs, arrow, dest;
        vector<string> parts;

        ss >> lhs;
        if (lhs == "NOT")
        {
            // "NOT x -> y"
            ss >> rhs >> arrow >> dest;
            parts = {"NOT", rhs}; // Store operation and operand
        }
        else
        {
            ss >> op;
            if (op == "->")
            {
                // "123 -> x" or "a -> b"
                dest = op; // Assign dest first
                parts = {"ASSIGN", lhs};
            }
            else
            {
                // "x AND y -> z"
                ss >> rhs >> arrow >> dest;
                parts = {op, lhs, rhs}; // Store full operation
            }
        }

        instructions[dest] = parts; // Store parsed instruction
    }

    return instructions;
}

int main()
{

    string filename = "input.txt";
    unordered_map<string, vector<string>> instructions = parseInput(filename);
    unordered_map<string, int> memo = {};
    // Debugging: Print parsed instructions
    for (const auto &[wire, expr] : instructions)
    {
        cout << wire << " ";
        for (const auto &part : expr)
            cout << part << " ";
        cout << endl;
    }

    return 0;
}
