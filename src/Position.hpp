#ifndef POSITION_H
#define POSITION_H
class Position
{

protected:

    int x,y;
    int Indx;
    int width; //szerokosc statku,pocisku itp
    int height; //wyskosc statku, pocisku itp
    char symbol; // symbol
    int erasedIndx;

public:
    static int indxx;

    Position();

    Position(const int&, const int& , const int&, const int&, const char&);

    void setPositionX(int x);

    void setPositionY(int y);

    int getPositionX();

    int getPositionY();

    bool operator == (Position&);

    char getSymbol();

    void setSymbol(char&);

    int getWidth();

    void setWidth(int&);

    int getHeight();

    void setHeight(int&);

    int getIndx();

    void zeroIndx();

    void eraseIndx();

    int getErasedIndx();



};

#endif
