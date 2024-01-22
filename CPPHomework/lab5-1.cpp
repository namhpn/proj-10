#include <iostream>
#include <cmath>

using namespace std;

struct point{double x,y;};

struct segment{point A,B;};

struct line{double a,b,c;};

struct vector{point source,target;};

struct triangle{point a,b,c;};

struct rectangle{point a,b,c,d;};

struct circle{point i; float r;};

float dodai(segment cc){
    float val;
    val = sqrt(pow(cc.B.x-cc.A.x,2) + pow(cc.B.y-cc.A.y,2));
    return val;
}

void inputPoint(point &A){
    cout<<"Nhap X: "; cin>>A.x;
    cout<<"Nhap Y: "; cin>>A.y;
}

void inputTG(triangle &T){
    cout<<"Nhap diem A"<<endl; inputPoint(T.a);
    cout<<"Nhap diem B"<<endl; inputPoint(T.b);
    cout<<"Nhap diem C"<<endl; inputPoint(T.c);
}

void inputLine(line &A){
    cout<<"PT Ax + By +C = 0"<<endl;
    cout<<"Nhap A B C: "; cin>>D.a>>D.b>>D.c;
}

void inputVT(vector &A){
    cout<<"Nhap diem Source: "; inputPoint(A.source);
    cout<<"Nhap diem Target: "; inputPoint(A.target);

}

bool checkTG(triangle A){
    segment AB = {A.a,A.b},AC = {A.a,A.c},BC = {A.b,A.c};
    if (dodai(AB)+dodai(BC) > dodai(AC) && dodai(AB)+dodai(AC) > dodai(BC) && dodai(AC)+dodai(BC) > dodai(AB))
        return true;
    else return false;
}

float distanceP2L(point A, line D){
    float kc = abs(D.a*A.x +D.b*A.y +D.c)/sqrt(pow(D.a,2)+pow(D.b,2));
    return kc;
}

bool checkVTZero(vector A){
    if (A.source.x == A.target.x && A.source.y == A.target.y)
        return true;
    return false;
}

float gocHaiVT(vector A, vector B){
    float s = acos((A.source.x*A.target.x + A.source.x*A.target.y)/(sqrt(pow(A.source.x,2)+pow(A.source.y,2))*sqrt(pow(A.target.x,2)+pow(A.target.y,2))));
    return s;
}

int main(){

}
