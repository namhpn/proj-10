#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int ROW,COL;
vector< vector<int> > matrix;

struct MaxValue
{
    int max_value; // lấy giá trị lớn nhất của các số xung quanh
    int col;       // vị trí cột
    int row;       // vị trí dòng
} maxVal;     // lưu các giá trị của struct

      // Chỉ số của mảng max_path, theo dõi vị trí hiện tại của mảng max_path

// kiểm tra item có tồn tại trong đường đi chưa
bool checkE(int n)
{
    for (int i = 0; i < path_index; i++)
    {
        if (max_path[i] == n)
        {
            return true;
        }
    }
    return false;
}

// tìm số lớn nhất trong mảng
int find_max(int arr[], int size)
{
    int max_value = -1; // Giá trị lớn nhất ban đầu là phần tử đầu tiên của mảng
    for (int i = 0; i < size; i++)
    {
        // Kiểm tra item cần check có trong mảng chưa, có thì bỏ qua
        if (checkE(arr[i]))
            continue;
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    return max_value;
}


// Hàm trả về giá trị lớn nhất của 4 điểm xung quanh (trái, phải, trên, dưới)
// tìm giá trị lớn nhất và vị trí của nó trong các xung quanh
void find_max_neighbor(int row, int col)
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
}

// Hàm đệ quy tìm kiếm đường đi lớn nhất
void find_max_path(int row, int col, int current_value)
{
    // Lưu giá trị hiện tại vào mảng max_path
    max_path[path_index++] = current_value;

    find_max_neighbor(row, col);

    if (maxVal.max_value == -1)
        return;

    find_max_path(maxVal.row, maxVal.col, matrix[maxVal.row][maxVal.col]);
}


void find_intersection_positions(int row1, int col1, int row2, int col2)
{
    // Tìm đường đi lớn nhất cho robot thứ nhất
    int start_value1 = matrix[row1][col1];
    find_max_path(row1, col1, start_value1);
    int* max_path1 = new int[path_index];
    int path_index1 = path_index;
    cout<<"RB 1: ";
    for (int i = 0; i < path_index; i++) // sao chép các giá trị từ find_max_path
    {
        max_path1[i] = max_path[i];
        cout<<max_path[i]<<" ";
    }
    // Đặt lại biến path_index và max_path cho robot thứ hai
    path_index = 0;
    int start_value2 = matrix[row2][col2];
    find_max_path(row2, col2, start_value2);
    int* max_path2 = new int[path_index];
    int path_index2 = path_index;
    cout<<endl<<"RB 2: ";
    for (int i = 0; i < path_index; i++)
    {
        max_path2[i] = max_path[i];
        cout<<max_path[i]<<" ";
    }

    cout << endl;
    // mở tệp tin ở chế độ ghi tiếp
    int count = 0;
    ofstream outfile("output.txt", ios_base::app ); // Mở tệp tin ở chế độ ghi tiếp (append)
    if (outfile.is_open())
    {
        outfile << "Cac vi tri cat nhau: ";
        for (int i = 0; i < path_index1; i++)
        {
            for (int j = 0; j < path_index2; j++)
            {
                if (max_path1[i] == max_path2[j])
                {
                    outfile << max_path1[i] << " ";
                    count ++;
                    break; // Nếu đã tìm thấy vị trí cắt nhau, thoát khỏi vòng lặp trong
                }
            }
        }
    outfile << endl << "so lan cat nhau cua hai robot la: " << count << endl;
    outfile.close();
    }
//giải phóng bộ nhớ đã cấp phát động cho mảng max_path1 và max_path2 sau khi đã sử dụng chúng
    delete[] max_path1;
    delete[] max_path2;
}


// Hàm tìm robot chiến thắng
void find_winning_robot(int row1, int col1, int row2, int col2)
{
    cout<<ROW<<" "<<COL;
    bool visited[ROW][COL]; // mảng để đánh dấu đường đi của robot
    for(int i = 0; i<=ROW;i++){
            for(int j = 0; j<= COL;j++){
                visited[i][j]= 0;
            }
    }
    // Tìm đường đi lớn nhất cho robot thứ nhất
    int start_value1 = matrix[row1][col1];
    find_max_path(row1, col1, start_value1);
    int* max_path1 = new int[path_index];
    int path_index1 = path_index;
    int total1 = 0;
    for (int i = 0; i < path_index; i++) // sao chép các giá trị từ find_max_path
    {
        max_path1[i] = max_path[i];
        visited[row1][max_path[i]] = 1; // đánh dấu các ô đả đi qua
        total1 += matrix[row1][max_path[i]];
    }

    // Đặt lại biến path_index và max_path cho robot thứ hai
    path_index = 0;
    int start_value2 = matrix[row2][col2];
    find_max_path(row2, col2, start_value2);
    int* max_path2 = new int[path_index];
    int path_index2 = path_index;
    int total2 = 0;
    for (int i = 0; i < path_index; i++)
    {
        if(visited[row1][max_path[i]]){
            continue;
        }
        max_path2[i] = max_path[i];
        total2 += matrix[row2][max_path[i]];
    }

    cout << endl;
    // mở tệp tin ở chế độ ghi tiếp
    ofstream outfile("output.txt", ios_base::app ); // Mở tệp tin ở chế độ ghi tiếp (append)
    if(total1>total2){
        outfile << "robot 1 chien thang!" << endl;
    }
    else if(total1<total2){
        outfile << "robot 2 chien thang!" << endl;
    }
    else outfile <<"hai robot hoa nhau!" << endl;
        outfile << endl;

    outfile.close();
    //giải phóng bộ nhớ đã cấp phát động cho mảng max_path1 và max_path2 sau khi đã sử dụng chúng
    delete[] max_path1;
    delete[] max_path2;
    }


int main()
{
    //Nhap tu file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout<<"Error while opening input file !";
        return 0;}
    inputFile>>ROW>>COL;
    matrix.resize(ROW, vector<int>(COL)); //Set mảng 2 chiều
    max_path.resize(ROW * COL); // Set mảng

    for (int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            inputFile>>matrix[i][j];

    /*int start_row, start_col;
    cout << "Nhap vi tri bat dau (hang cot): ";
    cin >> start_row >> start_col;
    cout << endl;
    int start_value = matrix[start_row][start_col];
    find_max_path(start_row, start_col, start_value);*/

    ofstream outputFile("output.txt");

    /*outputFile << path_index << endl;
     for (int i = 0; i < path_index; i++)
    {
        outputFile << max_path[i] << " ";
    }

    outputFile << endl;*/
    /*cout <<"nhap vi tri bat dau cua hai robot" << endl;
    int start_row1, start_col1;
    cout << "Nhap vi tri bat dau robot 1 (hang cot): ";
    cin >> start_row1 >> start_col1;
    int start_row2, start_col2;
    cout << "Nhap vi tri bat dau robot 2 (hang cot): ";
    cin >> start_row2 >> start_col2;
    find_intersection_positions(start_row1, start_col1, start_row2, start_col2);*/

    cout <<"tim robot chien thang" << endl;
    int start_row3, start_col3;
    cout << "Nhap vi tri bat dau robot 1 (hang cot): ";
    cin >> start_row3 >> start_col3;
    int start_row4, start_col4;
    cout << "Nhap vi tri bat dau robot 2 (hang cot): ";
    cin >> start_row4 >> start_col4;
    find_winning_robot(start_row3, start_col3, start_row4, start_col4);

    return 0;
}