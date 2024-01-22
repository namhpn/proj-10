#include <iostream>
using namespace std;

void taoMangTrung(int *dau1,int n, int *dau2, int &nn){
    for (int* i = dau1; i < dau1+n; i++)
        for(int* j = i+1; j < dau1+n; j++)
        {
            bool found = false;
            for(int* k = dau2; k < dau2+nn; k++)
                if(*k == *j)
                    {found = true; break;}
            if (*i == *j && !found)
            {   int *t = dau2+nn;
                *t = *j;
                nn++;}
        }
}

void mainProb(int *dau1, int n){
    int *dau2, k = 0;
    dau2 = new int[n];
    taoMangTrung(dau1,n,dau2,k);
    if(k == 0)
        cout<<"Khong co phan tu trung!";
    else 
        for(int* i = dau2; i<dau2+k; i++)
        {
            cout<<endl<<*i;
            int c = 0;
            for(int* j = dau1; j<dau1+n; j++)
                if (*j == *i)
                    c++;
            cout<<" - "<<c;
        }
    delete dau2;
}

int main()
{
    int *dau1,*dau2, *p, n, tong=0;
    cout<<"N: "; cin>>n;
    dau1 = new int[n];
    for (p = dau1; p<dau1+n; p++)
        {cout << "So thu " << p-dau1+1 << ": " ; cin >> *p;}
    mainProb(dau1,n);
    delete dau1;
}