#ifndef MAZEGEN_H
#define MAZEGEN_H
#include <cstdlib>
#include <iostream>
#include <vector>
#include "disjointset.h"
/*
    Isaias Zamora
    izamora@pengo.cabrillo.edu
    Preffered email: Leezam01@gmail.com
    mazegen.h
    assingment name: amazing union find, assignment number : 6
*/

const int RIGHTWALL = 14;
const int LEFTWALL = 11;
const int TOPWALL = 7;
const int BOTTOMWALL = 13;

class MazeGen
{
public:
    MazeGen(int n);
    ~MazeGen();
    void printMaze();
    void generateMaze();

private:
    int _n;
    int _size;
    int *maze;
    int *shufMaze;
    DisjointSet *A;
    void shuffleMaze(int array[]);
    void removeWalls(int i);
    int right(int i)
    {
        if ((i + 1) % _n == 0)
            return -1;
        return i + 1;
    }
    int below(int i)
    {
        if (i + _n >= _size)
            return -1;
        return i + _n;
    }
    int left(int i)
    {
        if (i % _n == 0)
            return -1;
        return i - 1;
    }
    int above(int i)
    {
        if (i - _n < 0)
            return -1;
        return i - _n;
    }
};

MazeGen::MazeGen(int n)
{
    srand(time(0));
    _n = n;
    _size = n * n;
    shufMaze = new int[_size];
    maze = new int[_size];
    A = new DisjointSet(_size);
}

MazeGen::~MazeGen()
{
    delete A;
    delete[] maze;
    delete[] shufMaze;
}

void MazeGen::generateMaze()
{
    for (int i = 0; i < _size; i++)
        maze[i] = 15;
    maze[0] = 11;
    maze[_size - 1] = 14;
    for (int i = 1; i < _size; i++)
        shufMaze[i] = i;
    shuffleMaze(shufMaze);
    int index = 0;
    while(A->getNumSets() != 1) {
        removeWalls(shufMaze[index]);
        index++;
    }
}

void MazeGen::shuffleMaze(int array [])
{
    int randNum;
    for (int i = _size - 1; i > 0; i--)
    {
        randNum = std::rand() % i;
        std::swap(array[i], array[randNum]);
    }
}

void MazeGen::removeWalls(int i)
{
    int randWall = 4;
    while (randWall > 0)
    {
        switch (rand() % randWall)
        {
        case 3:
            if (below(i) < 0 || A->sameSet(i, below(i)));
            else
            {
                maze[i] = maze[i] & BOTTOMWALL;
                maze[below(i)] = maze[below(i)] & TOPWALL;
                A->unionFind(i, below(i));
            }
            break;
        case 2:
            if (above(i) < 0 || A->sameSet(i, above(i)));
            else
            {
                maze[i] = maze[i] & TOPWALL;
                maze[above(i)] = maze[above(i)] & BOTTOMWALL;
                A->unionFind(i, above(i));
            }
            break;
        case 1:
            if (right(i) < 0 || A->sameSet(i, right(i)));
            else
            {
                maze[i] = maze[i] & RIGHTWALL;
                maze[right(i)] = maze[right(i)] & LEFTWALL;
                A->unionFind(i, right(i));
            }
            break;
        case 0:
            if (left(i) < 0 || A->sameSet(i, left(i)));
            else
            {
                maze[i] = maze[i] & LEFTWALL;
                maze[left(i)] = maze[left(i)] & RIGHTWALL;
                A->unionFind(i, left(i));
            }
            break;
        }
        randWall--;
    }
}

void MazeGen::printMaze()
{
    for (int i = 0; i < _size; i++)
    {
        if (maze[i] < 10)
            std::cout << maze[i];
        else if (maze[i] >= 10)
            std::cout << (char) (maze[i] + 87);
        if ((i + 1) % _n == 0)
            std::cout << std::endl;
    }
}
#endif