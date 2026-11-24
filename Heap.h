#pragma once
using namespace std;
#include <vector>

class Heap {
private:
    vector<int> heap;
public:
    Heap();

    void insert(int x);

    int extract();

    int size();

    ~Heap();
};
