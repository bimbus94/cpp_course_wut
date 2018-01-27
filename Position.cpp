#include "Position.hpp"

Position::Position() {}

Position::Position(const int& xx, const int& yy, const int& w, const int& h,const char& s_a)
    :x(xx),y(yy), width(w), height(h), symbol(s_a)
{
    indxx=indxx+1;
    Indx=indxx;
    erasedIndx=-1;
}



void Position::setPositionX(int x) //ustawianie wspolrzednej x
{
    this->x=x;
}

void Position::setPositionY(int y) //ustawianie wspolrzednej y
{
    this->y=y;
}

int Position::getPositionX() //zwracanie pozycji x
{
    return (this->x);
}

int Position::getPositionY() //zwracanie pozycji y
{
    return (this->y);
}

bool Position::operator == (Position &pos)
{
    return ((this->x==pos.getPositionX()) && (this->y==pos.getPositionY()));
}

char Position::getSymbol()
{
    return this->symbol;
}

void Position::setSymbol(char& s)
{
    this->symbol=s;
}

int Position::getWidth()
{
    return this->width;
}

void Position::setWidth(int& w)
{
    this->width=w;
}


int Position::getHeight()
{
    return this->height;
}

void Position::setHeight(int& h)
{
    this->height=h;
}

int Position::indxx;

int Position::getIndx()
{
    return this->Indx;
}


void Position::zeroIndx()
{
    Indx=0;
};

void Position::eraseIndx()
{
    erasedIndx=Indx;

};

int Position::getErasedIndx()
{
    return erasedIndx;
};




