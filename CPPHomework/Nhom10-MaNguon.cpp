#include <iostream>
#include <string>
#include <fstream>
	#include <windows.h>
#include <iomanip>                //De dinh dang khoang cach cac so trong ma tran
#include <sstream>

using namespace std;

const int COLOR_RED = 12;   //Mau do
const int COLOR_CYAN = 11;   //Mau xanh duong
const int COLOR_RESET = 7;   //Mau trang
const int COLOR_PURPLE = 13;   //Mau tim

//Ham set mau
void setConsoleColor(int color)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}
//Ham in ra dong Loading
void loading() {
	char a = 178, b = 219;   //Dua tren bang ma ASCII
	setConsoleColor(COLOR_CYAN);
	cout << "\n\t\t\t\t\t\t      Loading...";
	cout << "\n";
	for (int i = 0; i < 119; i++) {
		cout << a;
	}
	cout << "\r";
	for (int j = 0; j < 119; j++) {
		cout << b;
		Sleep(10);//Su dung thu vien Windows.h
	}
	cout << "\n\n";
	setConsoleColor(COLOR_RESET);
}
//Ve hinh Robot
void drawRobot(){
    setConsoleColor(COLOR_RED);
    cout << "\t\t\t\t\t\t       .-\"\"\"-." << endl;
    Sleep(50);  //Dung Sleep de chuyen dong cham
    cout << "\t\t\t\t\t\t      / .===. \\" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t      \\/  6  \\/" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t      ( \\___/ )" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t   _  /       \\  _" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t  / \\/         \\/ \\" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t  \\_/           \\_/" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t     \\  Robot  /" << endl;
    Sleep(50);
    cout << "\t\t\t\t\t\t      '-...-'" << endl;

    setConsoleColor(COLOR_RESET);
}
//Tao struct position
struct position {
	int x;
	int y;
};

// Ham de ve khung Luat choi
void drawCenteredLine(const string& text, int width) {//text tham chieu, const la de khong thay doi chuoi string duoc truyen vao
    int padding = (width - text.length()) / 2;
    cout << string(padding, ' ') << text << endl; //String(padding,' ') de tao mot chuoi chua padding khoan trang
}

//In ra menu luat choi
void menu(){
	cout<<"Co cac che do sau day: "<<endl;
    cout<<"\t\t1. Mot Robot di tren me cung."<<endl;
    cout<<"\t\t2. Hai Robot lan luot di tren mot me cung nhung khong di nhung o trung nhau."<<endl;
    cout<<"\t\t3. Hai Robot di tren mot me cung va co the di nhung o trung nhau."<<endl;
    cout<<"\t\t4. Thoat game."<<endl;
}
//Ham tim vi tri cua che do 1
void timViTri(int arrCopy[][100], int x, int y, int row_numbers, int col_numbers) {
    position robot_position = {x, y};  //x hang, y cot 
	int tong = 0;
    int result[50];
    int temp_x = x, temp_y = y;
    result[0] = arrCopy[x][y];
    int result_count = 1;
    arrCopy[x][y]= 0;
    while (true) {
        Sleep(500);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout<<"Vi tri bat dau cua Robot la: ("<<temp_x<<","<<temp_y<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
        // In duong vien tren cung
        for (int j = 0; j < col_numbers; j++) {
            cout << "+----";
        }
        cout << "+" << endl;

        // In cac dong cua ma tran
        for (int i = 0; i < row_numbers; i++) {
            // In dau "|" o dau moi dong
            cout << "|";

            for (int j = 0; j < col_numbers; j++) {
                if (arrCopy[i][j] == 0) {
                    setConsoleColor(COLOR_RED);  // Set mau cho cac o co gia tri 0
                } else {
                    setConsoleColor(COLOR_RESET);  //Dat mau mac dinh danh cho cac o khac
                }
                cout << setw(4) << arrCopy[i][j]; // Dinh dang do rong la 4
                setConsoleColor(COLOR_RESET);  // Dat mau sac danh cho cac o khac
                cout << "|"; // In dau "|" sau moi phan tu
            }

            cout << endl;

            // In duong vien giua cac dong
            for (int j = 0; j < col_numbers; j++) {
                cout << "+----";
            }
            cout << "+" << endl;
        }

        int temp_max = 0;
        int max = 0;
        position new_position = robot_position;

        if ((y - 1) >= 0 && arrCopy[x][y - 1] > max) { // Ben trai
            max = arrCopy[x][y - 1];
            new_position = {x, y - 1};
        }
        if ((x - 1) >= 0 && arrCopy[x - 1][y] > max) { // Ben tren
            max = arrCopy[x - 1][y];
            new_position = {x - 1, y};
        }
        if ((y + 1) < col_numbers && arrCopy[x][y + 1] > max) { // Ben phai
            max = arrCopy[x][y + 1];
            new_position = {x, y + 1};
        }
        if ((x + 1) < row_numbers && arrCopy[x + 1][y] > max) { // Ben duoi
            max = arrCopy[x + 1][y];
            new_position = {x + 1, y};
        }
        if (temp_max == max) {
            break;
        } else {
            arrCopy[new_position.x][new_position.y] = 0;
            x = new_position.x;
            y = new_position.y;
            robot_position = new_position;
            result[result_count] = max;
            result_count++;
        }
    }
    cout<<"Duong di cua Robot la: ";
    for (int i=0; i<result_count; ++i){
    	cout<<result[i]<<" ";
	}
	cout<<endl;
	
	for (int i=0; i<result_count; ++i){
    	tong += result[i];
	}
	cout<<"Tong gia tri cac o ma Robot da di qua la: "<<tong<<endl;
	//Ghi vao File
	ofstream MyFile("Output.txt");
	MyFile<<result_count<<endl;
	for (int i=0; i<result_count; ++i){
		MyFile<<result[i]<<" ";
	}
	MyFile<<endl;
	MyFile.close();
	cout<<"Da ghi vao File."<<endl;
}

//Mot Robot che do 1
void duongDiCuaRoBot(const int arr[][100], int x, int y,  int row_numbers, int col_numbers ){
    int arrCopy[100][100];
	for (int i = 0; i < row_numbers; i++) {
        for (int j = 0; j < col_numbers; j++) {
            arrCopy[i][j] = arr[i][j];
        }
    } 
    
    timViTri(arrCopy, x,  y, row_numbers, col_numbers);
}

//Hai Robot nhung khong di trung nhau che do 2
void duongDiCuaHaiRoBotKhac(const int arr[][100],  int row_numbers, int col_numbers ){
	//Tao ban sao
    int arrCopy[100][100];
	for (int i = 0; i < row_numbers; i++) {
        for (int j = 0; j < col_numbers; j++) {
            arrCopy[i][j] = arr[i][j];
        }
    } 
    //Robot thu nhat 
	int x1, y1;
	int x2, y2;
	position robot_position1 = {x1, y1}; // x1 hang, y2 cot
	position robot_position2 = {x2, y2}; // x2 hang, y2 cot
	//De phong truong hop nguoi dung nhap khong dung
	while (true){
		cout<<"Vui long nhap toa do x cho Robot thu nhat: "<<endl;
		cin>>x1;
		cout<<"Vui long nhap toa do y cho Robot thu nhat: "<<endl;
		cin>>y1;
		cout<<"Vui long nhap toa do x cho Robot thu hai: "<<endl;
		cin>>x2;
		cout<<"Vui long nhap toa do y cho Robot thu hai: "<<endl;
		cin>>y2;
		if (x2==x1 and y2==y1){
			cout<<"Toa do nay cua Robot thu nhat, vui long nhap lai!"<<endl;
		}
		else if (x1<0 or x2<0 or x1>=row_numbers or x2>=row_numbers or y1<0 or y2<0 or y1>=col_numbers or y2>=col_numbers){
			cout<<"Toa do ban nhap da vuot qua me cung, vui long nhap lai!"<<endl;
		}
		else{
			break;
	}
	}
	int tong1 = 0;
	int tong2 = 0; 
    int result1[50];
    int result2[50];
    int temp_x1 = x1, temp_y1 = y1;
    int temp_x2 = x2, temp_y2 = y2;
    result1[0] = arrCopy[x1][y1];
    result2[0] = arrCopy[x2][y2];
    int result_count1 = 1;
    int result_count2 = 1;
    arrCopy[x1][y1]= 0;
    arrCopy[x2][y2] = -1;
	int luot_di = 0;
	int flag1 = 0;
	int flag2 = 0;
    while (true) {
        Sleep(500);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout<<"Vi tri bat dau cua Robot thu nhat la: ("<<temp_x1<<","<<temp_y1<<")"<<endl;
    	cout<<"Vi tri bat dau cua Robot thu hai la: ("<<temp_x2<<","<<temp_y2<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
        // In duong vien tren cung
        for (int j = 0; j < col_numbers; j++) {
            cout << "+----";
        }
        cout << "+" << endl;

        // In cac dong cua ma tran
        for (int i = 0; i < row_numbers; i++) {
            // In dau "|" o dau moi dong
            cout << "|";

            for (int j = 0; j < col_numbers; j++) {
                if (arrCopy[i][j] == 0) {
                    setConsoleColor(COLOR_RED);  // Set mau cho cac o co gia tri 0
                } 
				else if (arrCopy[i][j] == -1){
					setConsoleColor(COLOR_CYAN); 
				}
				else {
                    setConsoleColor(COLOR_RESET);  //Dat mau mac dinh danh cho cac o khac
                }
                cout <<setw(4) << arrCopy[i][j]; // Dinh dang do rong la 4
                setConsoleColor(COLOR_RESET);  // Dat mau sac danh cho cac o khac
                cout << "|"; // In dau "|" sau moi phan tu
            }

            cout << endl;

            // In duong vien giua cac dong
            for (int j = 0; j < col_numbers; j++) {
                cout << "+----";
            }
            cout << "+" << endl;
        }
        if (flag1!=1){
			if (luot_di%2==0 or luot_di==-1){
		        int temp_max1 = 0;
		        int max1 = 0;
		        position new_position1 = robot_position1;
		
		        if ((y1 - 1) >= 0 && arrCopy[x1][y1 - 1] > max1) { // Ben trai
		            max1 = arrCopy[x1][y1 - 1];
		            new_position1 = {x1, y1 - 1};
		        }
		        if ((x1 - 1) >= 0 && arrCopy[x1 - 1][y1] > max1) { // Ben tren
		            max1 = arrCopy[x1 - 1][y1];
		            new_position1 = {x1 - 1, y1};
		        }
		        if ((y1 + 1) < col_numbers && arrCopy[x1][y1 + 1] > max1) { // Ben phai
		            max1 = arrCopy[x1][y1 + 1];
		            new_position1 = {x1, y1 + 1};
		        }
		        if ((x1 + 1) < row_numbers && arrCopy[x1 + 1][y1] > max1) { // Ben duoi
		            max1 = arrCopy[x1 + 1][y1];
		            new_position1 = {x1 + 1, y1};
		        }
		        if (temp_max1 == max1) {
		            luot_di == -6;
		            flag1 = 1;
		        } else {
		            arrCopy[new_position1.x][new_position1.y] = 0;
		            x1 = new_position1.x;
		            y1 = new_position1.y;
		            robot_position1 = new_position1;
		            result1[result_count1] = max1;
		            result_count1++;
		        }
		        if (luot_di==-1){
		        	luot_di = -2;
				}
			}
	}
	
		if(luot_di%2!=0) {
			if (flag2!=1){
		        int temp_max2 = 0;
		        int max2 = 0;
		        position new_position2 = robot_position2;
		
		        if ((y2 - 1) >= 0 && arrCopy[x2][y2 - 1] > max2) { // Ben trai
		            max2 = arrCopy[x2][y2 - 1];
		            new_position2 = {x2, y2 - 1};
		        }
		        if ((x2 - 1) >= 0 && arrCopy[x2 - 1][y2] > max2) { // Ben tren
		            max2 = arrCopy[x2 - 1][y2];
		            new_position2 = {x2 - 1, y2};
		        }
		        if ((y2 + 1) < col_numbers && arrCopy[x2][y2 + 1] > max2) { // Ben phai
		            max2 = arrCopy[x2][y2 + 1];
		            new_position2 = {x2, y2 + 1};
		        }
		        if ((x2 + 1) < row_numbers && arrCopy[x2 + 1][y2] > max2) { // Ben duoi
		            max2 = arrCopy[x2 + 1][y2];
		            new_position2 = {x2 + 1, y2};
		        }
		        if (temp_max2 == max2) {
		        	luot_di = -2;
		        	flag2 = 1;
		        } else {
		            arrCopy[new_position2.x][new_position2.y] = -1;
		            x2 = new_position2.x;
		            y2 = new_position2.y;
		            robot_position2 = new_position2;
		            result2[result_count2] = max2;
		            result_count2++;
		        }
		        if (luot_di==-5){
		        	luot_di == -6;
				}
			}
		}
		luot_di += 1;
		if (flag1==1 and flag2==1){
			break;
		}
    }
    	
    //In ra duong di va tong
	cout<<"Duong di cua Robot thu nhat(0) la: ";
	for (int i=0; i<result_count1; ++i){
		cout<<result1[i]<<" ";
	}
	cout<<endl;
	
	for (int i=0; i<result_count1; ++i){
		tong1 += result1[i];
	}
	cout<<"\t-->Tong gia tri cac o ma Robot thu nhat da di qua la: "<<tong1<<endl;
	
    cout<<"Duong di cua Robot thu hai(-1) la: ";
    for (int i=0; i<result_count2; ++i){
    	cout<<result2[i]<<" ";
	}
	cout<<endl;
	
	for (int i=0; i<result_count2; ++i){
    	tong2 += result2[i];
	}
	cout<<"\t-->Tong gia tri cac o ma Robot thu hai da di qua la: "<<tong2<<endl;
	
	if (tong1 > tong2){
		cout<<"Robot thu nhat Win!"<<endl;
	}
	else if (tong1 < tong2){
		cout<<"Robot thu hai Win!"<<endl;
	}
	else {
		cout<<"Hai Robot hoa nhau!"<<endl;
	}
	//Ghi vao File
	ofstream MyFile("Output.txt");
	MyFile<<"Duong di cua Robot thu nhat: ";
	for (int i=0; i<result_count1; ++i){
		MyFile<<result1[i]<<" ";
	}
	MyFile<<endl;
	MyFile<<"Tong gia tri cac o ma Robot thu nhat da di qua la: "<<tong1<<endl;
	MyFile<<endl;
	MyFile<<"Duong di cua Robot thu hai: ";
	for (int i=0; i<result_count2; ++i){
		MyFile<<result2[i]<<" ";
	}
	MyFile<<endl;
	MyFile<<"Tong gia tri cac o ma Robot thu hai da di qua la: "<<tong2<<endl;
	if (tong1 > tong2){
		MyFile<<"Robot thu nhat Win!"<<endl;
	}
	else if (tong1 < tong2){
		MyFile<<"Robot thu hai Win!"<<endl;
	}
	else {
		MyFile<<"Hai Robot hoa nhau!"<<endl;
	}
	MyFile.close();
	cout<<"Da ghi vao File."<<endl;
}

//Hai Robot co the di trung nhau che do 3
void haiRoBot(int arr[][100],  int row_numbers, int col_numbers ){       //Ghi len ma tran goc
    int arrCopy1[100][100];
    int arrCopy2[100][100];
    int arrCopy[100][100];
	for (int i = 0; i < row_numbers; i++) {
        for (int j = 0; j < col_numbers; j++) {
            arrCopy1[i][j] = arr[i][j];
        }
    } 
    for (int i = 0; i < row_numbers; i++) {
        for (int j = 0; j < col_numbers; j++) {
            arrCopy2[i][j] = arr[i][j];
        }
    } 
    for (int i = 0; i < row_numbers; i++) {
        for (int j = 0; j < col_numbers; j++) {
            arrCopy[i][j] = arr[i][j];
        }
    } 
    //Robot thu nhat 
	int x, y;
	position robot_position = {x, y}; // x hang, y cot
	//De phong truong hop nguoi dung nhap khong dung
	while (true){
		cout<<"Vui long nhap toa do x cho Robot thu nhat: "<<endl;
		cin>>x;
		cout<<"Vui long nhap toa do y cho Robot thu nhat: "<<endl;
		cin>>y;
		if (x<0 or x>=row_numbers or y<0 or y>=col_numbers){
			cout<<"Vi tri ban chon da vuot qua ma tran, vui long nhap lai!"<<endl;
		}
		else{
			break;
		}
	}
	int tong1 = 0;
    int result1[50];
    int temp_x1 = x, temp_y1 = y;
    result1[0] = arrCopy1[x][y];
    arrCopy1[x][y] = 0;
    int result_count1 = 1;
    arrCopy[x][y]= 0;
    while (true) {
        Sleep(500);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
    	cout<<"Vi tri bat dau cua Robot thu nhat la: ("<<temp_x1<<","<<temp_y1<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
        // In duong vien tren cung
        for (int j = 0; j < col_numbers; j++) {
            cout << "+----";
        }
        cout << "+" << endl;

        // In cac dong cua ma tran
        for (int i = 0; i < row_numbers; i++) {
            // In dau "|" dau moi dong
            cout << "|";

            for (int j = 0; j < col_numbers; j++) {
                if (arrCopy[i][j] == 0) {
                    setConsoleColor(COLOR_RED);  // Set mau cho o co gia tri 0
                } else {
                    setConsoleColor(COLOR_RESET);  // Dat mau danh cho cac o khac
                }
                cout << setw(4) << arrCopy[i][j]; //  Dinh dang do rong la 4
                setConsoleColor(COLOR_RESET);  // Dat mau danh cho cac o khac
                cout << "|"; // In dau "|" sau moi phan tu
            }

            cout << endl;

            // In duong vien giua cac dong
            for (int j = 0; j < col_numbers; j++) {
                cout << "+----";
            }
            cout << "+" << endl;
        }

        int temp_max = 0;
        int max = 0;
        position new_position = robot_position;

        if ((y - 1) >= 0 && arrCopy1[x][y - 1] > max) { // Ben trai
            max = arrCopy1[x][y - 1];
            new_position = {x, y - 1};
        }
        if ((x - 1) >= 0 && arrCopy1[x - 1][y] > max) { // Ben tren
            max = arrCopy1[x - 1][y];
            new_position = {x - 1, y};
        }
        if ((y + 1) < col_numbers && arrCopy1[x][y + 1] > max) { // Ben phai
            max = arrCopy1[x][y + 1];
            new_position = {x, y + 1};
        }
        if ((x + 1) < row_numbers && arrCopy1[x + 1][y] > max) { // Ben duoi
            max = arrCopy1[x + 1][y];
            new_position = {x + 1, y};
        }
        if (temp_max == max) {
            break;
        } else {
            arrCopy[new_position.x][new_position.y] = 0;
            arrCopy1[new_position.x][new_position.y] = 0;
            x = new_position.x;
            y = new_position.y;
            robot_position = new_position;
            result1[result_count1] = max;
            result_count1++;
        }
	}
    //Robot thu hai
	//De phong truong hop nguoi dung nhap khong dung
	while (true){
		cout<<"Vui long nhap toa do x cho Robot thu hai: "<<endl;
		cin>>x;
		cout<<"Vui long nhap toa do y cho Robot thu hai: "<<endl;
		cin>>y;
		if ((x<0 or x>=row_numbers) or (y<0 or y>=col_numbers)){
			cout<<"Vi tri ban chon da vuot qua ma tran, vui long nhap lai!"<<endl;
		}
		else{
			break;
		}
	}
	
	int tong2 = 0;
    int result2[50];
    int temp_x2 = x, temp_y2 = y;
    result2[0] = arrCopy2[x][y];
    int result_count2 = 1;
    int trungNhau[100];
    int demTrungNhau = -1;
    if (arrCopy[x][y]==0){
    	demTrungNhau = 0;
    	trungNhau[demTrungNhau] = arrCopy2[x][y];
	}
	arrCopy2[x][y] = -1 ;
    arrCopy[x][y]= -1;
    while (true) {
        Sleep(500);
        system("cls");          //Xoa tat ca de co the thao tac tren ma tran
        cout<<"Vi tri bat dau cua Robot thu nhat la: ("<<temp_x1<<","<<temp_y1<<")"<<endl;
    	cout<<"Vi tri bat dau cua Robot thu hai la: ("<<temp_x2<<","<<temp_y2<<")"<<endl;
    	cout << "Duong di cua Robot: " << endl;
        // In duong vien tren cung
        for (int j = 0; j < col_numbers; j++) {
            cout << "+----";
        }
        cout << "+" << endl;

        // In cac dong cua ma tran
        for (int i = 0; i < row_numbers; i++) {
            // In dau "|" dau moi dong
            cout << "|";

            for (int j = 0; j < col_numbers; j++) {
            	if (arrCopy1[i][j]==0 and arrCopy2[i][j]==-1) {
                    setConsoleColor(COLOR_PURPLE);  // Set mau cho o co gia tri 0
				}
				else
				{
            		if (arrCopy[i][j]==0){
						setConsoleColor(COLOR_RED);
					}
					else if(arrCopy[i][j]==-1){
                		setConsoleColor(COLOR_CYAN);
            		}
            		else {
                    	setConsoleColor(COLOR_RESET);  // Dat mau mac dinh danh cho cac o khac
                		}
        		}
                cout << setw(4) << arrCopy[i][j]; // Dinh dang do rong la 4
                setConsoleColor(COLOR_RESET);  // Dat mau mac dinh danh cho cac o khac
                cout << "|"; // In dau "|" sau moi phan tu
            }

            cout << endl;

            // In duong vien giua cac dong
            for (int j = 0; j < col_numbers; j++) {
                cout << "+----";
            }
            cout << "+" << endl;
        }

        int temp_max = 0;
        int max = 0;
        position new_position = robot_position;

        if ((y - 1) >= 0 && arrCopy2[x][y - 1] > max) { // Ben trai
            max = arrCopy2[x][y - 1];
            new_position = {x, y - 1};
        }
        if ((x - 1) >= 0 && arrCopy2[x - 1][y] > max) { // Ben tren
            max = arrCopy2[x - 1][y];
            new_position = {x - 1, y};
        }
        if ((y + 1) < col_numbers && arrCopy2[x][y + 1] > max) { // Ben phai
            max = arrCopy2[x][y + 1];
            new_position = {x, y + 1};
        }
        if ((x + 1) < row_numbers && arrCopy2[x + 1][y] > max) { // Ben duoi
            max = arrCopy2[x + 1][y];
            new_position = {x + 1, y};
        }
        if (temp_max == max) {
            break;
        } else {
        	if (arrCopy[new_position.x][new_position.y]==0){
        		demTrungNhau += 1;
        		trungNhau[demTrungNhau] = arrCopy2[new_position.x][new_position.y]; 
			}
            arrCopy[new_position.x][new_position.y] = -1;
            arrCopy2[new_position.x][new_position.y] = -1;
            x = new_position.x;
            y = new_position.y;
            robot_position = new_position;
            result2[result_count2] = max;
            result_count2++;
        }
    }
    //In ra duong di va tong
	cout<<"Duong di cua Robot thu nhat(0) la: ";
	for (int i=0; i<result_count1; ++i){
		cout<<result1[i]<<" ";
	}
	cout<<endl;
	
	for (int i=0; i<result_count1; ++i){
		tong1 += result1[i];
	}
	cout<<"\t-->Tong gia tri cac o ma Robot thu nhat da di qua la: "<<tong1<<endl;
	
    cout<<"Duong di cua Robot thu hai(-1) la: ";
    for (int i=0; i<result_count2; ++i){
    	cout<<result2[i]<<" ";
	}
	cout<<endl;
	
	for (int i=0; i<result_count2; ++i){
    	tong2 += result2[i];
	}
	cout<<"\t-->Tong gia tri cac o ma Robot thu hai da di qua la: "<<tong2<<endl;
	
	if (tong1 > tong2){
		cout<<"Robot thu nhat Win!"<<endl;
	}
	else if (tong1 < tong2){
		cout<<"Robot thu hai Win!"<<endl;
	}
	else {
		cout<<"Hai Robot hoa nhau!"<<endl;
	}
	cout<<"Hai Robot di trung nhau nhung o co gia tri: ";
	for (int i=0; i<=demTrungNhau; ++i){
		cout<<trungNhau[i]<<" ";
	}
	cout<<endl;
	//Ghi vao File
	ofstream MyFile("Output.txt");
	MyFile<<"Duong di cua Robot thu nhat: ";
	for (int i=0; i<result_count1; ++i){
		MyFile<<result1[i]<<" ";
	}
	MyFile<<endl;
	MyFile<<"Tong gia tri cac o ma Robot thu nhat da di qua la: "<<tong1<<endl;
	MyFile<<endl;
	MyFile<<"Duong di cua Robot thu hai: ";
	for (int i=0; i<result_count2; ++i){
		MyFile<<result2[i]<<" ";
	}
	MyFile<<endl;
	MyFile<<"Tong gia tri cac o ma Robot thu hai da di qua la: "<<tong2<<endl;
	if (tong1 > tong2){
		MyFile<<"Robot thu nhat Win!"<<endl;
	}
	else if (tong1 < tong2){
		MyFile<<"Robot thu hai Win!"<<endl;
	}
	else {
		MyFile<<"Hai Robot hoa nhau!"<<endl;
	}
	MyFile<<"Hai Robot di trung nhau nhung o co gia tri: ";
	for (int i=0; i<=demTrungNhau; ++i){
		MyFile<<trungNhau[i]<<" ";
	}
	MyFile.close();
	cout<<"Da ghi vao File."<<endl;
}

int main(){
//Phan dau
	//In dong Loading
	loading();
	//In hinh robot
	drawRobot();
	//In dong Welcome
	string message = ">WELCOME TO ROBOT BATTLE GAMES<";
	setConsoleColor(COLOR_CYAN);
	int messageLength = message.length();
	for (int i = 0; i < (119 - messageLength) / 2; i++) {
	    cout << "-";
	    Sleep(10);
	}
	for (int i = 0; i < messageLength; i++) {
	    char c = message[i];
	    cout << c;
	    Sleep(10);
	}
    for (int i=0; i<(119-message.length())/2; i++){
		cout<<"-";
		Sleep(10);
	} 
	cout<<endl;
	setConsoleColor(COLOR_RESET);
	//In ra Luat choi
	string title = "LUAT CHOI";
    string rule1 = "Robot se chon cac o co gia tri lon nhat xung quanh no de di chuyen.";
    string rule2 = "Robot se dung lai khi khong con o nao de di.";
    int maxLength = max(max(title.length(), rule1.length()), rule2.length());
    int frameWidth = maxLength + 50;
    string horizontalLine(frameWidth, '=');
    cout << horizontalLine << endl;
    drawCenteredLine(title, frameWidth);
    cout << horizontalLine << endl;
    drawCenteredLine(rule1, frameWidth);
    drawCenteredLine(rule2, frameWidth);

    cout << horizontalLine << endl;
    
//Doc File
	const int MAX_ROWS = 100;
	const int MAX_COLS = 100;
    int arr[MAX_ROWS][MAX_COLS];
    int count = 0;
	string mang;
	
    ifstream MyReadFile("Input.txt");
	getline(MyReadFile, mang);	
	stringstream ss(mang);      //ss su dung noi dung cua bien mang va ss thao tac voi chuoi ki tu do
    int row_numbers, col_numbers;
    ss >> row_numbers >> col_numbers; //Gan gtri tu ss vao hai bien row_ va col_
    while (getline(MyReadFile, mang)) {
    	stringstream ss2(mang);
    	int value;
    	int col = 0;
    	while (ss2 >> value) {
        arr[count][col] = value;
        col++;
    	}
    	count++;
	}	
    MyReadFile.close();  //Phai dong file de khong gay ra loi
//In ra ma tran da doc duoc tu File
	cout << "So do me cung: " << endl;
        // In duong vien tren cung
        for (int j = 0; j < col_numbers; j++) {
            cout << "+----";
        }
        cout << "+" << endl;
        // In cac dong cua ma tran
        for (int i = 0; i < row_numbers; i++) {
            // In dau "|" dau moi dong
            cout << "|";
            for (int j = 0; j < col_numbers; j++) {
                cout << setw(4) << arr[i][j]; // Dinh d?ng do rong la 4
                cout << "|"; // In dau "|" sau moi phan tu
            }
            cout << endl;
            // In duong vien giua cac dong
            for (int j = 0; j < col_numbers; j++) {
                cout << "+----";
            }
            cout << "+" << endl;
        }
//Nguoi dung chon che do va choi
	int x;
	int y;
    int cheDo;
    menu();
    cout<<"Vui long chon che do bang cach nhap so: "<<endl;
    cin>>cheDo;
    while (true){
		if (cheDo==1){
			//De phong truong hop nguoi dung nhap khong dung
			while (true){
				cout<<"Vui long nhap toa do x: "<<endl;
				cin>>x;
				cout<<"Vui long nhap toa do y: "<<endl;
				cin>>y;
				if ((x<0 or x>=row_numbers) or (y<0 or y>=col_numbers)){
					cout<<"Vi tri ban chon da vuot qua ma tran, vui long nhap lai!"<<endl;
				}
				else{
					break;
				}
			}
		    duongDiCuaRoBot(arr, x, y, row_numbers, col_numbers);
		    cout<<"--------------------------------------------------"<<endl;
		    menu();
		    cout<<"Vui long chon che do bang cach nhap so: "<<endl;
		    cin>>cheDo;
		}
		if (cheDo==2){
			duongDiCuaHaiRoBotKhac(arr,  row_numbers, col_numbers );
			cout<<"--------------------------------------------------"<<endl;
		    menu();
		    cout<<"Vui long chon che do bang cach nhap so: "<<endl;
		    cin>>cheDo;
		}
		if (cheDo==3){
			haiRoBot(arr,  row_numbers, col_numbers );
			cout<<"--------------------------------------------------"<<endl;
		    menu();
		    cout<<"Vui long chon che do bang cach nhap so: "<<endl;
		    cin>>cheDo;
		}
		if (cheDo<=0 or cheDo>4){
			cout<<"Vui long nhap dung yeu cau!"<<endl;
			cout<<"--------------------------------------------------"<<endl;
			menu();
    		cout<<"Vui long chon che do bang cach nhap so: "<<endl;
    		cin>>cheDo;
		}
		if (cheDo==4){
			string message1 = ">HEN GAP LAI<";
			setConsoleColor(COLOR_CYAN);
			int messageLength = message1.length();
			
			for (int i = 0; i < (119 - messageLength) / 2; i++) {
			    cout << " ";
			    Sleep(5);
			}
			
			for (int i = 0; i < messageLength; i++) {
			    char c = message1[i];
			    cout << c;
			    Sleep(5);
			}
		    for (int i=0; i<(119-message.length())/2; i++){
				cout<<" ";
				Sleep(5);
			} 
			setConsoleColor(COLOR_RESET);
			break;
		}
	}
	return 0;
}

