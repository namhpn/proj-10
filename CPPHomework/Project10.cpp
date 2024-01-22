#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std;

int ROW,COL;
vector<vector<int> > matrix;
vector<int> steps,steps1,steps2;
int totalStep,totalStep1,totalStep2 = 0;
bool lastVal,lastVal1,lastVal2 = false;

const int COLOR_RED = 12;   //Mau do
const int COLOR_CYAN = 11;   //Mau xanh duong
const int COLOR_RESET = 7;   //Mau trang
const int COLOR_PURPLE = 13;   //Mau tim

void setConsoleColor(int color)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}

struct MaxValue{
    int max_value; // lấy giá trị lớn nhất của các số xung quanh
    int col;       // vị trí cột
    int row;       // vị trí dòng
};

MaxValue maxVal, currLoc;

bool checkEPos(int n, int nn, const vector<int>& a)
{
    for (int i = 0; i < nn; i++)
        if (a[i] == n)
            return true;
    return false;
}

int find_max(int arr[], int n)
{
    int maxVal = -1;

    for (int i = 0; i < n; i++)
        if (!checkEPos(arr[i],totalStep,steps) && arr[i] > maxVal)
            maxVal = arr[i];

    return maxVal;
}

bool inputfromFile(){
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cout<<"Error while opening input file !";
        return false;}

    inputFile>>ROW>>COL;
    //Set giá trị ban đầu
    matrix.resize(ROW, vector<int>(COL));
    steps.resize(ROW * COL);
    //Nhập mảng
    for (int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            inputFile>>matrix[i][j];
    inputFile.close();
    return true;
}

bool findMaxNB(int row, int col)
{
    // Góc trái đầu tiên vị trí [0,0]
    if (row == 0 && col == 0)
    {
        int arr[2] = {matrix[row][col + 1], matrix[row + 1][col]};
        maxVal.max_value = find_max(arr, 2);

        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col + 1;
            maxVal.row = row;
        }
        if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col;
            maxVal.row = row + 1;
        }
    }
    // Góc thứ 2 bên trái vị trí [ROW - 1, 0]
    else if (row == ROW - 1 && col == 0)
    {
        int arr[2] = {matrix[row - 1][0], matrix[row][col + 1]};
        maxVal.max_value = find_max(arr, 2);

        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = 0;
            maxVal.row = row - 1;
        }
        if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col + 1;
            maxVal.row = row;
        }
    }
    // Góc thứ 3 [ROW - 1,COL - 1]
    else if (row == ROW - 1 && col == COL - 1)
    {
        int arr[2] = {matrix[row - 1][col], matrix[row][col - 1]};
        maxVal.max_value = find_max(arr, 2);

        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col;
            maxVal.row = row - 1;
        }
        if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col - 1;
            maxVal.row = row;
        }
    }
    // Góc thứ 4 vị trí [0, COL - 1]
    else if (row == 0 && col == COL - 1)
    {
        int arr[2] = {matrix[0][col - 1], matrix[row + 1][col]};
        maxVal.max_value = find_max(arr, 2);

        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col - 1;
            maxVal.row = 0;
        }
        if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col;
            maxVal.row = row + 1;
        }
    }
    // row 0 => row đầu tiên
    else if (row == 0)
    {
        int arr[3] = {matrix[0][col - 1], matrix[0][col + 1], matrix[row + 1][col]};
        maxVal.max_value = find_max(arr, 3);
        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col - 1;
            maxVal.row = 0;
        }
        else if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col + 1;
            maxVal.row = 0;
        }
        else
        {
            maxVal.col = col;
            maxVal.row = row + 1;
        }
    }
    // row ROW - 1 => row cuối cùng
    else if (row == ROW - 1)
    {
        int arr[3] = {matrix[row][col - 1], matrix[row][col + 1], matrix[row - 1][col]};
        maxVal.max_value = find_max(arr, 3);
        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col - 1;
            maxVal.row = row;
        }
        else if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col + 1;
            maxVal.row = row;
        }
        else
        {
            maxVal.col = col;
            maxVal.row = row - 1;
        }
    }
    // col 0 => col đầu tiên
    else if (col == 0)
    {
        int arr[3] = {matrix[row - 1][0], matrix[row + 1][0], matrix[row][col + 1]};
        maxVal.max_value = find_max(arr, 3);
        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = 0;
            maxVal.row = row - 1;
        }
        else if (arr[1] == maxVal.max_value)
        {
            maxVal.col = 0;
            maxVal.row = row + 1;
        }
        else
        {
            maxVal.col = col + 1;
            maxVal.row = row;
        }
    }
    // row COL - 1 => col cuối cùng
    else if (col == COL - 1)
    {
        int arr[3] = {matrix[row - 1][col], matrix[row + 1][col], matrix[row ][col-1]};
        maxVal.max_value = find_max(arr, 3);
        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col;
            maxVal.row = row - 1;
        }
        else if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col;
            maxVal.row = row + 1;
        }
        else
        {
            maxVal.col = col-1;
            maxVal.row = row;
        }
    }
    // vị trí bất kì, có đủ 4 hướng trên dưới trái phải
    else
    {
        int arr[4] = {matrix[row][col - 1], matrix[row][col + 1], matrix[row - 1][col], matrix[row + 1][col]};
        maxVal.max_value = find_max(arr, 4);
        // Lấy vị trí của max value
        if (arr[0] == maxVal.max_value)
        {
            maxVal.col = col - 1;
            maxVal.row = row;
        }
        else if (arr[1] == maxVal.max_value)
        {
            maxVal.col = col + 1;
            maxVal.row = row;
        }
        else if (arr[2] == maxVal.max_value)
        {
            maxVal.col = col;
            maxVal.row = row - 1;
        }
        else
        {
            maxVal.col = col;
            maxVal.row = row + 1;
        }
    }
    if (maxVal.max_value == -1)
        return false;
    return true;
}

void findPath(int row, int col, int currVal){
    steps[totalStep++] = currVal;

    if (!findMaxNB(row, col)){
        return;}

    findPath(maxVal.row, maxVal.col, matrix[maxVal.row][maxVal.col]);
}

void findPathExcludeDup(int row1, int col1, int row2, int col2, int currVal1, int currVal2)
{

    if(!lastVal1){ //RB 1
        if (totalStep1 == 0){
            steps[totalStep++] = currVal1;
            steps1[totalStep1++] = currVal1;}
        findMaxNB(row1,col1);
        if(!findMaxNB(row1,col1)){lastVal1 = true;}
        else {row1 = maxVal.row;
        col1 = maxVal.col;
        currVal1 = matrix[maxVal.row][maxVal.col];
        steps[totalStep++] = currVal1;
        steps1[totalStep1++] = currVal1;}}

    if(!lastVal2){ //RB2
        if (totalStep2 == 0){
            steps[totalStep++] = currVal2;
            steps2[totalStep2++] = currVal2;}
        if(!findMaxNB(row2,col2)){lastVal2 = true;}
        else {row2 = maxVal.row;
        col2 = maxVal.col;
        currVal2 = matrix[maxVal.row][maxVal.col];
        currVal2 = matrix[maxVal.row][maxVal.col];
        steps[totalStep++] = currVal2;
        steps2[totalStep2++] = currVal2;}}
    if(lastVal1 && lastVal2)
        return;
    findPathExcludeDup(row1,col1,row2,col2,currVal1,currVal2);
}

void printRB(int srow, int scol, int totalS, vector<int>& a){
    for(int k = 0; k <= totalS; k++){
        Sleep(700);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout<<"Vi tri bat dau cua Robot la: ("<<srow<<","<<scol<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
    	for (int j = 0; j < COL; j++)
            cout << "+----";
        cout << "+" << endl;
        for (int i = 0; i < ROW; i++) {
            cout << "|";
            for (int j = 0; j < COL; j++) {
                if (checkEPos(matrix[i][j],k,a))
                    setConsoleColor(COLOR_RED);
                else
                    setConsoleColor(COLOR_RESET);
                cout << setw(4) << matrix[i][j];
                setConsoleColor(COLOR_RESET);
                cout << "|";
            }
            cout << endl;
            // In duong vien giua cac dong
            for (int j = 0; j < COL; j++)
                cout << "+----";
            cout << "+" << endl;
        }
    }
}

void printScndRB(int srow, int scol, int totalS1, int totalS2, vector<int>& a, vector<int>& b){
    for(int k = 0; k <= totalS1; k++){
        Sleep(700);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout<<"Vi tri bat dau cua Robot la: ("<<srow<<","<<scol<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
    	for (int j = 0; j < COL; j++)
            cout << "+----";
        cout << "+" << endl;
        for (int i = 0; i < ROW; i++) {
            cout << "|";
            for (int j = 0; j < COL; j++) {
                if (checkEPos(matrix[i][j],totalS2,b))
                    setConsoleColor(COLOR_RED);
                if (checkEPos(matrix[i][j],k,a) && checkEPos(matrix[i][j],totalS2,b))
                    setConsoleColor(COLOR_CYAN);
                else if (checkEPos(matrix[i][j],k,a))
                    setConsoleColor(COLOR_PURPLE);
                else if (!checkEPos(matrix[i][j],totalS2,b))
                    setConsoleColor(COLOR_RESET);
                cout << setw(4) << matrix[i][j];
                setConsoleColor(COLOR_RESET);
                cout << "|";
            }
            cout << endl;
            // In duong vien giua cac dong
            for (int j = 0; j < COL; j++)
                cout << "+----";
            cout << "+" << endl;
        }
    }
}

void printBothRB(int totalS1, int totalS2, vector<int>& a, vector<int>& b){
    int nn = 1; lastVal1 = false; lastVal2 = false;
    while(true){
        Sleep(700);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout << "Duong di cua Robot: " << endl;
    	for (int j = 0; j < COL; j++)
            cout << "+----";
        cout << "+" << endl;
        for (int i = 0; i < ROW; i++) {
            cout << "|";
            for (int j = 0; j < COL; j++) {
                if (checkEPos(matrix[i][j],nn,a)){
                    setConsoleColor(COLOR_RED);
                    if (totalS1 == nn-1) lastVal1 = true;}
                else if (checkEPos(matrix[i][j],nn,b)){
                    setConsoleColor(COLOR_PURPLE);
                    if (totalS2 == nn-1) lastVal2 = true;}
                else
                    setConsoleColor(COLOR_RESET);
                cout << setw(4) << matrix[i][j];
                setConsoleColor(COLOR_RESET);
                cout << "|";
            }
            cout << endl;
            // In duong vien giua cac dong
            for (int j = 0; j < COL; j++)
                cout << "+----";
            cout << "+" << endl;
        }
    nn++;
    if(lastVal1 && lastVal2)
        return;
    }
}

bool updateLoc(int row, int col){
    if (row < ROW && col < COL && row >= 0 && row >= 0){
        currLoc.row = row; currLoc.col = col;
        steps[totalStep++] = matrix[row][col];
        return true;}
    else return false;
}

bool inputNextStep(){
    char *n = new char; int *row = new int, *col = new int;
    while(true){
        cout<<"\n Buoc tiep ? (W/A/S/D): "; cin>>*n;
        switch(*n){
            case 'W': case 'w':
                *row = currLoc.row - 1; *col = currLoc.col;
                if (!updateLoc(*row,*col)){cout<<"Nhap lai!"; break;}
                delete[] n,row,col;
                return true;
            case 'A': case 'a':
                *row = currLoc.row; *col = currLoc.col - 1;
                if (!updateLoc(*row,*col)){cout<<"\nNhap lai!"; break;}
                delete[] n,row,col;
                return true;
            case 'S': case 's':
                *row = currLoc.row + 1; *col = currLoc.col;
                if (!updateLoc(*row,*col)){cout<<"\nNhap lai!"; break;}
                delete[] n,row,col;
                return true;    
            case 'D': case 'd':
                *row = currLoc.row; *col = currLoc.col + 1;
                if (!updateLoc(*row,*col)){cout<<"\nNhap lai!"; break;}
                delete[] n,row,col;
                return true;
            default:
                cout<<"Nhap lai!";
        }
    }
}

void OnePlayer(){
    int start_row = 0, start_col = 0,total=0;
    while(true){
        cout << "Nhap vi tri bat dau (hang cot, mac dinh: 0 0): "; cin >> start_row >> start_col;
        if(start_row < ROW && start_col < COL && start_row >= 0 && start_col >= 0)
            break;
        else cout<<"Nhap lai! ";
    }

    findPath(start_row, start_col, matrix[start_row][start_col]);

    printRB(start_row,start_col,totalStep,steps); //In

    ofstream outputFile("output.txt");
    outputFile << totalStep << endl;
    for (int i = 0; i < totalStep; i++)
    {
        outputFile << steps[i] << " ";
        total+=steps[i];
    }
    outputFile << endl;
    cout<<"So diem cua robot la: "<<total;
}

void TwoPlayerDuplicate(){
    steps1.resize(ROW * COL);
    steps2.resize(ROW * COL);

    int start_row1 = 0, start_col1 = 0;
    while(true){
        cout << "Nhap vi tri bat dau ROBOT 1 (hang cot): "; cin >> start_row1 >> start_col1;
        if(start_row1 < ROW && start_col1 < COL && start_row1 >= 0 && start_col1 >= 0)
            break;
        else cout<<"Nhap lai! ";
    }

    //Mo file
    ofstream outputFile("output.txt");
    //Chạy RB 1
    findPath(start_row1, start_col1, matrix[start_row1][start_col1]);
    int total1 = 0;
    totalStep1 = totalStep; totalStep = 0;
    outputFile<<"RB 1: ";
    for(int i = 0; i < totalStep1; i++){
        steps1[i] = steps[i];
        total1 += steps1[i];
        outputFile << steps[i]<<" ";}
    outputFile<<"Tong Diem RB 1: "<<total1;
    outputFile << endl;

    //In RB 1
    printRB(start_row1,start_col1,totalStep1,steps1);
    cout<<"Tong diem robot 1 la: "<<total1;
    //Chạy RB 2
    int start_row2 = 0, start_col2 = 0, total2 = 0;
    
    while(true){
        cout << "\nNhap vi tri bat dau ROBOT 2 (hang cot): "; cin >> start_row2 >> start_col2;
        if(start_row2 < ROW && start_col2 < COL && start_row2 >= 0 && start_col2 >= 0)
            break;
        else cout<<"Nhap lai! ";
    }

    findPath(start_row2, start_col2, matrix[start_row2][start_col2]);
    totalStep2 = totalStep; totalStep = 0; total2 = 0;
    outputFile<<"RB 2: ";
    for(int i = 0; i < totalStep2; i++){
        steps2[i] = steps[i];
        total2 += steps2[i];
        outputFile << steps[i]<<" ";}
    outputFile<<"Tong Diem RB 2: "<<total2;
    //in
    printScndRB(start_row2,start_col2,totalStep2,totalStep1,steps2,steps1);
    cout<<"Tong diem cua robot 2 la: "<<total2;
    //robot chiến thắng
    if (total1>total2)
        cout<<"\nRobot 1 chien thang!";
    else if (total2>total1)
        cout<<"\nRobot 2 chien thang!";
    else cout<<"Hai robot hoa nhau!";
    //outTrung
    outputFile<<"\nVi tri trung: ";
    for(int i = 0; i < totalStep1; i++)
        for (int j = 0; j < totalStep2; j++)
            if (steps1[i] == steps2[j]){
                outputFile<<steps1[i]<<" ";
                break;}
    outputFile << endl;
}

void TwoPlayerExcludeDup(){
    //Mo file
    ofstream outputFile("output.txt");
    steps1.resize(ROW * COL);
    steps2.resize(ROW * COL);

    int start_row1 = 0, start_col1 = 0, start_row2 = 0, start_col2 = 0, total1 = 0;
    while(true){
        cout << "Nhap vi tri bat dau ROBOT 1 (hang cot): "; cin >> start_row1 >> start_col1;
        if(start_row1 < ROW && start_col1 < COL && start_row1 >= 0 && start_col1 >= 0)
            break;
        else cout<<"Nhap lai! ";
    }
    while(true){
        cout << "Nhap vi tri bat dau ROBOT 2 (hang cot): "; cin >> start_row2 >> start_col2;
        if(start_row2 < ROW && start_col2 < COL && start_row2 >= 0 && start_col2 >= 0)
            break;
        else cout<<"Nhap lai! ";
    }
    findPathExcludeDup(start_row1,start_col1,start_row2,start_col2,matrix[start_row1][start_col1],matrix[start_row2][start_col2]);
    outputFile <<"RB 1: ";
    for(int i = 0; i < totalStep1; i++){
        outputFile <<steps1[i]<<" ";
        total1 += steps1[i];}
    outputFile<<"Tong Diem RB 1: "<<total1;
    outputFile << endl;

    int total2 = 0;
    outputFile <<"RB 2: ";
    for(int i = 0; i < totalStep2; i++){
        outputFile <<steps2[i]<<" ";
        total2 += steps2[i];}
    outputFile<<"Tong Diem RB 2: "<<total2;
    outputFile << endl;
    printBothRB(totalStep1,totalStep2,steps1,steps2);
    cout<<"\nTong diem RB 1: "<<total1;
    cout<<"\nTong diem RB 2: "<<total2;
    if (total1>total2)
        cout<<"\nRobot 1 chien thang!";
    else if (total2>total1)
        cout<<"\nRobot 2 chien thang!";
    else cout<<"Hai robot hoa nhau!";
}

void UserPlayer(){
    int srow = 0, scol = 0, total = 0;

    while(true){
        cout << "Nhap vi tri bat dau (hang cot, mac dinh: 0 0): "; cin >> srow >> scol;
        if(srow < ROW && scol < COL && srow >= 0 && scol >= 0)
            break;
        else cout<<"Nhap lai! ";
    }

    currLoc.row = srow; currLoc.col = scol; steps[totalStep++] = matrix[currLoc.row][currLoc.col];
    while(!lastVal){
        Sleep(700);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout<<"Vi tri bat dau cua Robot la: ("<<srow<<","<<scol<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
    	for (int j = 0; j < COL; j++)
            cout << "+----";
        cout << "+" << endl;
        for (int i = 0; i < ROW; i++) {
            cout << "|";
            for (int j = 0; j < COL; j++) {
                if (checkEPos(matrix[i][j],totalStep,steps))
                    setConsoleColor(COLOR_RED);
                else
                    setConsoleColor(COLOR_RESET);
                cout << setw(4) << matrix[i][j];
                setConsoleColor(COLOR_RESET);
                cout << "|";
            }
            cout << endl;
            // In duong vien giua cac dong
            for (int j = 0; j < COL; j++)
                cout << "+----";
            cout << "+" << endl;
        }
        if (findMaxNB(currLoc.row, currLoc.col))
            inputNextStep();
        else lastVal = true;
    }
    
    ofstream outputFile("output.txt");
    outputFile << totalStep << endl;
    for (int i = 0; i < totalStep; i++)
    {
        outputFile << steps[i] << " ";
        total+=steps[i];
    }
    outputFile << endl;
    cout<<"So diem cua robot la: "<<total;
}

int main()
{
    while(true){
        if(!inputfromFile())
            return 0;
        char *opt = new char;
        system("cls");
        for (int j = 0; j < COL; j++)
            cout << "+----";
        cout<<"+"<<endl;
        for (int i = 0; i < ROW; i++) {
            cout << "|";
            for (int j = 0; j < COL; j++) {
                cout << setw(4) << matrix[i][j]; // Dinh d?ng do rong la 4
                cout << "|"; // In dau "|" sau moi phan tu
            }
            cout << endl;
            // In duong vien giua cac dong
            for (int j = 0; j < COL; j++)
                cout << "+----";
            cout << "+" << endl;
        }
        cout<<"Co cac che do sau day: "<<endl;
        cout<<"\t\tA. Mot Robot di tren me cung."<<endl;
        cout<<"\t\tB. Hai Robot di tren mot me cung va co the di nhung o trung nhau."<<endl;
        cout<<"\t\tC. Hai Robot lan luot di tren mot me cung nhung khong di nhung o trung nhau."<<endl;
        cout<<"\t\tD. Nguoi choi tu chon buoc di tiep theo cua robot."<<endl;
        cout<<"\t\tE. Thoat game."<<endl;
        cout<<"\t\tVui long chon [A/B/C/D/E]: "; cin>>*opt;

        switch(*opt){
            case 'A': case 'a':
                OnePlayer();
                break;
            case 'B': case 'b':
                TwoPlayerDuplicate();
                break;
            case 'C': case 'c':
                TwoPlayerExcludeDup();
                break;
            case 'D': case 'd':
                UserPlayer();
                break;
            case 'E': case 'e':
                cout<<"Hen gap lai!";
                return 0;
        }
        cout<<"\nTiep tuc ? (Y/n): "; cin>>*opt;
        switch(*opt){
            case 'N': case 'n':
                delete[] opt;
                cout<<"\nBaiiiiii";
                return 0;
            case 'Y': case 'y':
                steps.clear(); steps1.clear(); steps2.clear(); matrix.clear();
                totalStep = 0; totalStep1 = 0; totalStep2 = 0;
                lastVal = false; lastVal1 = false; lastVal2 = false;
        }
        delete[] opt;
    }
}
