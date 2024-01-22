#include <iostream>

using namespace std;

int n;

struct SinhVien{
    int id;
    string ten;
    int tuoi;
    float diem;
};

void inputSV(SinhVien *&S, int &n){
    cout<<"SL Sinh Vien: "; cin>>n;
    S = new SinhVien[n];
    for(int i = 0; i < n; i++){
        cout<<"Nhap SV"<<i+1<<endl;
        cout<<"Nhap ID: "; cin>>(S+i)->id;
        cout<<"Nhap Ten: "; cin.ignore(); getline(cin, (S+i)->ten);
        cout<<"Nhap Tuoi: "; cin>>(S+i)->tuoi;
        cout<<"Nhap Diem: "; cin>>(S+i)->diem;
    }
}

void xuatAllSV(const SinhVien *S){
    for(int i = 0; i < n; i++){
        cout<<"SV "<<i+1<<":";
        cout<<endl<<"ID: "<<(S+i)->id;
        cout<<endl<<"Ten: "<<(S+i)->ten;
        cout<<endl<<"Tuoi: "<<(S+i)->tuoi;
        cout<<endl<<"Diem: "<<(S+i)->diem;
        cout<<endl<<"---------*---------\n";
    }
}

void xuatSV(const SinhVien *S,int currPos){
    cout<<endl<<"ID: "<<(S+currPos)->id;
    cout<<endl<<"Ten: "<<(S+currPos)->ten;
    cout<<endl<<"Tuoi: "<<(S+currPos)->tuoi;
    cout<<endl<<"Diem: "<<(S+currPos)->diem<<endl;
}

float diemTB(const SinhVien *S, int n){
    float d = 0;
    for(int i = 0; i < n; i++)
        d+=(S+i)->diem; 
    return (d/n);
}

float diemCN(const SinhVien *S,int currPos,float ln){
    while (currPos < n){
        if ((S+currPos)->diem > ln)
            ln = (S+currPos)->diem;
        return diemCN(S,currPos+1,ln);
    }
    return ln;
}

void xuatSVDiemCN(const SinhVien *S){
    cout<<"Sinh vien co diem cao nhat: ";
    float ln = diemCN(S,0,0);
    for (int i = 0; i < n; i++)
        if ((S+i)->diem == ln)
            xuatSV(S,i);
}

float diemTN(const SinhVien *S,int currPos,float nn){
    while (currPos < n){
        if ((S+currPos)->diem < nn){
            nn = (S+currPos)->diem;
        }
        return diemTN(S,currPos+1,nn);
    }
    return nn;
}

void xuatSVDiemTN(const SinhVien *S){
    cout<<"Sinh vien co diem thap nhat: ";
    float tn = diemTN(S,0,10);
    for (int i = 0; i < n; i++)
        if ((S+i)->diem == tn)
            xuatSV(S, i);
}

void timSVtheoID(const SinhVien *S){
    int nid;
    cout<<"Nhap ID can tim: "; cin>>nid;
    for(int i = 0; i < n; i++)
        if(nid == (S+i)->id)
            xuatSV(S,i);
}

void sortTongDiemThi(SinhVien *S){
    for (int i = 0; i < n; i++){
        if((S+i)->diem != diemCN(S,i,0)){
            for(int j = i+1; j < n; j++)
                if((S+j)->diem == diemCN(S,i,0)){
                    int id = (S+j)->id; string ten = (S+j)->ten; int tuoi = (S+j)->tuoi; float diem = (S+j)->diem;
                    (S+j)->id = (S+i)->id; (S+j)->ten = (S+i)->ten; (S+j)->tuoi = (S+i)->tuoi; (S+j)->diem = (S+i)->diem;
                    (S+i)->id = id; (S+i)->ten = ten; (S+i)->tuoi = tuoi; (S+i)->diem = diem;
                    break;
                }
        }
    }
}

int main(){
    int opt; SinhVien* S = nullptr;

    while (true) {
        cout << "==============================MENU============================" << endl;
        cout << "1. Nhap thong tin sinh vien lop hoc" << endl;
        cout << "2. Hien thi tat ca sinh vien" << endl;
        cout << "3. Tinh diem trung binh cua lop hoc" << endl;
        cout << "4. Hien thi sinh vien co tong diem cao nhat" << endl;
        cout << "5. Hien thi sinh vien co tong diem thap nhat" << endl;
        cout << "6. Tim sinh vien boi ID" << endl;
        cout << "7. Sap xep cac ban ghi boi tong diem thi cua sinh vien" << endl;
        cout << "8. Exit"<<endl;
        cout << "Nhap lua chon: "; cin >> opt;

        switch (opt) {
            case 1:
                inputSV(S,n);
                break;
            case 2:
                xuatAllSV(S);
                break;
            case 3:
                cout<<"Diem TB cua ca lop: "<<diemTB(S,n)<<endl;
                break;
            case 4:
                xuatSVDiemCN(S);
                break;
            case 5:
                xuatSVDiemTN(S);
                break;
            case 6:
                timSVtheoID(S);
                break;
            case 7:
                sortTongDiemThi(S);
                cout<<"Da sap xep!"<<endl;
                break;
            case 8:
                delete[] S;
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon tu 1 den 8." << endl;
                break;
        }
    }
}

