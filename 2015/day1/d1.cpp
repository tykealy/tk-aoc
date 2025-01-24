#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Main function
int main()
{
    // Open the input file
    ifstream file("input.txt");

    // Read the input
    string input;
    file >> input;

    int count = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            count++;

            if (count == -1)
            {
                cout << i + 1 << endl;
                break;
            }
        }
        else
        {
            count--;

            if (count == -1)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    cout << count << endl;
}
