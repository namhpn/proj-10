#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int ROW,COL;
vector<vector<int> > matrix;
vector<int> steps,steps1,steps2;
int totalStep,totalStep1,totalStep2 = 0;

bool lastVal,lastVal1,lastVal2 = false;


struct MaxValue{
    int max_value; // lấy giá trị lớn nhất của các số xung quanh
    int col;       // vị trí cột
    int row;       // vị trí dòng
} maxVal;

struct Neighbor{
    int val;
    int row;
    int col;
};

bool checkE(int n)
{
    for (int i = 0; i < totalStep; i++)
        if (steps[i] == n)
            return true;
    return false;
}

int find_max(int arr[], int n)
{
    int maxVal = -1;
    for (int i = 0; i < n; i++)
        if (!checkE(arr[i]) && arr[i] > maxVal)
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

void findMaxNB(int row, int col)
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
        lastVal = true;
}

void findPath(int row, int col, int currVal)
{
    // Lưu giá trị hiện tại vào mảng steps
    steps[totalStep++] = currVal;

    findMaxNB(row, col);

    if (lastVal){
        lastVal = false;
        return;}

    findPath(maxVal.row, maxVal.col, matrix[maxVal.row][maxVal.col]);
}

void findPathExcludeDup(int row1, int col1, int row2, int col2, int currVal1, int currVal2)
{
    if(!lastVal1){
        steps[totalStep++] = currVal1;
        steps1[totalStep1++] = currVal1;
        findMaxNB(row1,col1);
        if(lastVal){
            lastVal = false;
            lastVal1 = true;}
        row1 = maxVal.row;
        col1 = maxVal.col;
        currVal1 = matrix[maxVal.row][maxVal.col];}

    if(!lastVal2){
        steps[totalStep++] = currVal2;
        steps2[totalStep2++] = currVal2;
        findMaxNB(row2,col2);
        if(lastVal){
            lastVal = false;
            lastVal2 = true;}
        row2 = maxVal.row;
        col2 = maxVal.col;
        currVal2 = matrix[maxVal.row][maxVal.col];}
    if(lastVal1 && lastVal2)
        return;
    findPathExcludeDup(row1,col1,row2,col2,currVal1,currVal2);
}

void OnePlayer(){
    int start_row, start_col;
    cout << "Nhap vi tri bat dau (hang cot): ";
    cin >> start_row >> start_col;
    cout << endl;

    int start_value = matrix[start_row][start_col];
    findPath(start_row, start_col, start_value);

    ofstream outputFile("output.txt");
    outputFile << totalStep << endl;
    for (int i = 0; i < totalStep; i++)
    {
        outputFile << steps[i] << " ";
    }
    outputFile << endl;
}

void TwoPlayerDuplicate(){
    steps1.resize(ROW * COL);
    steps2.resize(ROW * COL);

    int start_row1, start_col1;
    cout << "Nhap vi tri bat dau ROBOT 1 (hang cot): ";
    cin >> start_row1 >> start_col1;
    //Mo file
    ofstream outputFile("output.txt");
    //Chạy RB 1
    findPath(start_row1, start_col1, matrix[start_row1][start_col1]);
    int totalP;
    totalStep1 = totalStep; totalStep = 0;
    outputFile<<"RB 1: ";
    for(int i = 0; i < totalStep1; i++){
        totalP += steps1[i];
        outputFile << steps1[i]<<" ";}
    outputFile<<"Tong Diem RB 1: "<<totalP;
    outputFile << endl;
    //Chạy RB 2
    
    int start_row2, start_col2;
    cout << "Nhap vi tri bat dau ROBOT 2 (hang cot): ";
    cin >> start_row2 >> start_col2;
    findPath(start_row2, start_col2, matrix[start_row2][start_col2]);
    totalStep2 = totalStep; totalStep = 0; totalP = 0;
    outputFile<<"RB 2: ";
    for(int i = 0; i < totalStep2; i++){
        totalP += steps2[i];
        outputFile << steps2[i]<<" ";}
    outputFile<<"Tong Diem RB 2: "<<totalP;

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

    int start_row1, start_col1, start_row2, start_col2, totalP = 0;
    cout << "Nhap vi tri bat dau ROBOT 1 (hang cot): "; cin >> start_row1 >> start_col1;
    cout << "Nhap vi tri bat dau ROBOT 2 (hang cot): "; cin >> start_row2 >> start_col2;
    findPathExcludeDup(start_row1,start_col1,start_row2,start_col2,matrix[start_row1][start_col1],matrix[start_row2][start_col2]);
    outputFile <<"RB 1: ";
    for(int i = 0; i < totalStep1; i++){
        outputFile <<steps1[i]<<" ";
        totalP += steps1[i];}
    outputFile<<"Tong Diem RB 1: "<<totalP;
    outputFile << endl;

    int totalP1 = totalP; totalP = 0;
    outputFile <<"RB 2: ";
    for(int i = 0; i < totalStep2; i++){
        outputFile <<steps2[i]<<" ";
        totalP += steps2[i];}
    outputFile<<"Tong Diem RB 2: "<<totalP;
    outputFile << endl;
}

int main()
{
    if(!inputfromFile())
        return 0;

    char opt;
    nl: cout<<"Co cac che do sau day: "<<endl;
    cout<<"\t\tA. Mot Robot di tren me cung."<<endl;
    cout<<"\t\tB. Hai Robot di tren mot me cung va co the di nhung o trung nhau."<<endl;
    cout<<"\t\tC. Hai Robot lan luot di tren mot me cung nhung khong di nhung o trung nhau."<<endl;
    cout<<"\t\tD. Thoat game."<<endl; cin>>opt;

    switch(opt){
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
        cout<<"Hen gap lai!";
        return 0;
    default:
        goto nl;
        break;
    }
    return 0;
}