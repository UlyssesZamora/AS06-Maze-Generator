#ifndef DISJOINTSET_H
#define DISJOINTSET_H

/*
    Isaias Zamora
    izamora@pengo.cabrillo.edu
    Preffered email: Leezam01@gmail.com
    disjoint.h
    assingment name: amazing union find, assignment number : 6
*/
class DisjointSet
{
public:
    DisjointSet(int size);
    ~DisjointSet();
    void unionFind(int x, int y);
    int find(int x);
    int getNumSets();
    bool connected() { return _sets == 1; }
    bool sameSet(int x, int y);

private:
    int *parent;
    int *rank;
    int _size;
    int _sets;
    void link(int x, int y);
};

DisjointSet::DisjointSet(int size)
{
    _size = size;
    _sets = size;
    parent = new int[size];
    rank = new int[size];
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

DisjointSet::~DisjointSet()
{
    delete[] rank;
    delete[] parent;
}

void DisjointSet::unionFind(int x, int y)
{
    link(find(x), find(y));
    _sets--;
}

int DisjointSet::find(int x)
{
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

int DisjointSet::getNumSets()
{
    return _sets;
}

bool DisjointSet::sameSet(int x, int y)
{
    return find(x) == find(y);
}

void DisjointSet::link(int x, int y)
{
    if(x == y)
        return;
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
}
#endif