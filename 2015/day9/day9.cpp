#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Parse input and build distance map
void parseInput(const string &filename, unordered_map<string, unordered_map<string, int>> &cityDistances, set<string> &cities)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        // Parse "City1 to City2 = Distance"
        istringstream iss(line);
        string city1, to, city2, equals;
        int distance;

        if (!(iss >> city1 >> to >> city2 >> equals >> distance))
        {
            cerr << "Error parsing line: " << line << endl;
            continue;
        }

        // Store both directions
        cityDistances[city1][city2] = distance;
        cityDistances[city2][city1] = distance;

        // Keep track of all cities
        cities.insert(city1);
        cities.insert(city2);
    }
}

// Get distance between two cities
int getDistance(const string &city1, const string &city2,
                const unordered_map<string, unordered_map<string, int>> &cityDistances)
{
    return cityDistances.at(city1).at(city2);
}

// Print the distance map for verification
void printDistanceMap(const unordered_map<string, unordered_map<string, int>> &cityDistances)
{
    for (const auto &[city1, destinations] : cityDistances)
    {
        for (const auto &[city2, distance] : destinations)
        {
            cout << city1 << " to " << city2 << " = " << distance << endl;
        }
    }
}

// Safe version of getDistance that checks if cities exist
int safeGetDistance(const string &city1, const string &city2,
                    const unordered_map<string, unordered_map<string, int>> &cityDistances)
{
    if (cityDistances.find(city1) == cityDistances.end())
    {
        cerr << "City not found: " << city1 << endl;
        return -1;
    }

    if (cityDistances.at(city1).find(city2) == cityDistances.at(city1).end())
    {
        cerr << "Route not found: " << city1 << " to " << city2 << endl;
        return -1;
    }

    return cityDistances.at(city1).at(city2);
}

int main()
{
    try
    {
        unordered_map<string, unordered_map<string, int>> cityDistances;
        set<string> cities;

        // Parse input file
        parseInput("input.txt", cityDistances, cities);

        // Print all cities
        cout << "Cities in the map:" << endl;
        for (const auto &city : cities)
        {
            cout << "- " << city << endl;
        }
        cout << endl;

        // Print the entire distance map for verification
        cout << "Distance Map:" << endl;
        printDistanceMap(cityDistances);
        cout << endl;

        // Example: Get distance between two cities
        cout << "Example distance lookups:" << endl;
        cout << "Faerun to Norrath: " << safeGetDistance("Faerun", "Norrath", cityDistances) << endl;
        cout << "Norrath to Faerun: " << safeGetDistance("Norrath", "Faerun", cityDistances) << endl;
        cout << "AlphaCentauri to Snowdin: " << safeGetDistance("AlphaCentauri", "Snowdin", cityDistances) << endl;
        cout << endl;

        cout << "Total number of cities: " << cities.size() << endl;
        cout << "Total number of routes: " << cityDistances.size() * (cityDistances.size() - 1) / 2 << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
