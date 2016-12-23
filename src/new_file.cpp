#include "new_file.hpp"

//////////////
// Includes //
#include <iostream>
#include <fstream>
#include <vector>

//////////
// Code //

using namespace std;

static int fillGroups(ifstream& file, vector<vector<string>>& groups) {
    string value;
    int count = 0;
    while (file >> value) {
        if (file.eof())
            break;
        if (value == "GROUP")
            groups.push_back(vector<string>());
        else {
            groups[groups.size() - 1].push_back(value);
            count++;
        }
    }

    return count;
}

// Loading a new file. Parses by group and automatically connects each person
// within a group.
Graph *loadNewFile(string path) {
    ifstream file(path);
    if (!file)
        return nullptr;

    vector<vector<string>> groups;
    int count = fillGroups(file, groups);

    vector<string> values;
    for (int i = 0; i < groups.size(); i++)
        for (int j = 0; j < groups[i].size(); j++)
            values.push_back(groups[i][j]);

    Graph *g = new Graph(&values[0], count);
    int n = 0;
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].size(); j++)
            for (int k = j + 1; k < groups[i].size(); k++) {
                if (j == k)
                    cout << "HOLLA" << endl;
                g->connect(j + n, k + n);
            }
        n += groups[i].size();
    }

    file.close();

    return g;
}
