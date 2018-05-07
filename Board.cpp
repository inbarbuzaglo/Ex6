#include "Board.h"

Board::Board(int n)
{
    this->n = n;
    this->mat = new Node *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new Node[n];
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
            mat[i][j] = Node('.');
    }
}
Board::Board(const Board &b)
{
    this->n = b.n;
    this->mat = new Node *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new Node[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = Node(b.mat[i][j].getC());
    }
}
void Board::deleteB(Node **mat)
{
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}
Board::~Board()
{
    deleteB(this->mat);
}
Node &Board::operator[](list<int> l)
{
    int a = l.front(), b = l.back();
    ;
    if (a < n && a >= 0 && b < n && b >= 0)
        return this->mat[a][b];
    else
    {
        IllegalCoordinateException ex;
        ex.setA(a);
        ex.setB(b);
        throw ex;
    } //exp
}
Board &Board::operator=(char c)
{
    if (c == '.')
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                mat[i][j].setC(c);
        }
        return *this;
    }
    else
    {
        IllegalCharException ex;
        ex.setInput(c);
        throw ex;
    }
    return *this;
}

Board &Board::operator=(const Board &b)
{
    if (this == &b)
        return *this;
    this->n = b.n;
    if (b.n != this->n)
    {
        deleteB(this->mat);
        this->mat = new Node *[b.n];
        for (int i = 0; i < n; i++)
        {
            mat[i] = new Node[n];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            this->mat[i][j].setC(b.mat[i][j].getC());
    }
    return *this;
}
