#include <iostream>

using namespace std;

struct point{
    float x;
    float y;
};

struct line{
    float a;
    float b;
};

struct ConvexPoly{
    int size;
    point *points;
};

void inputPoint(point &p){
    cout<<"\nNhap X Y : "; cin>>p.x>>p.y;
}

float pLine(point p, line l){
    //y = ax + b
    return (l.a*p.x + l.b - p.y);
}

line buildLine(point A, point B){
    line l;
    l.a = (A.y - B.y)/(A.x - B.x);
    l.b = A.y - (A.x*l.a);
    return l;
}

ConvexPoly buildCPoly(){
    ConvexPoly cp;
    cout<<"Nhap SL: "; cin>>cp.size;
    cp.points = new point[cp.size];
    
    for(point *i = cp.points; i < (cp.points + cp.size); i++){
        cout<<"Nhap diem thu "<<(i-cp.points+1);
        inputPoint(*i);
    }
    return cp;
}

bool CheckCPoly(ConvexPoly cp){
    float temp;
    for(point *i =(cp.points+3); i<cp.points+cp.size; i++){
        temp=1;
        for(point *j =(cp.points+1); j<i; j++)
            temp *= pLine(*j,buildLine(*cp.points,*i));
        if(temp < 0)
            return false;
    }
    return true;
}

float findLargestX(ConvexPoly cp){
    float x = 0;
    for(point *i = cp.points; i< cp.points+cp.size; i++)
        if (x < *i.x)
            x = *i.x;
    return x;
}

float findLargestY(ConvexPoly cp){
    float y = 0;
    for(point *i = cp.points; i< cp.points+cp.size; i++)
        if (y < *i.y)
            y = *i.y;
    return y;
}

void drawDots(ConvexPoly cp){
    int ii = 0;
    cout<<"^\n"
    for(int i = 0; i < findLargestY(cp)*2; i++)
        if(i)
        
}

int main(){
    point A = {-1,1},B = {-2,1},C = {-1.5,1};
    line l = buildLine(A,B);
    ConvexPoly n = buildCPoly();
    if (CheckCPoly(n))
        cout<<"DG Loi";
    else
        cout<<"DG Lom";
}