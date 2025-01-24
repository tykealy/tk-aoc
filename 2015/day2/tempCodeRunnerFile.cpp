vector<int> parseDimensions(const string &line)
{
    vector<int> dims;
    stringstream ss(line);
    string token;

    while (getline(ss, token, 'x'))
    {
        dims.push_back(stoi(token));
    }

    return dims;
}