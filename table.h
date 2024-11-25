#ifndef TABLE_H
#define TABLE_H

#include "db.h"
#include <vector>

class Table
{
public:
    Table();
    Value search(int v);
    void edit(int v, const string &s, int& iteration);
    void insert(const string &s);
    bool remove(int v);
    void SaveToFile(const string &file_name);
    void LoadFromFile(const string &file_name);


private:
    Node* root;
    std::vector<Value> records;
    int count;
};

#endif // TABLE_H
