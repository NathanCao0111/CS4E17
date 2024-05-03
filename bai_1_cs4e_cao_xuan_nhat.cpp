/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// bai 1
#include <iostream>
using namespace std;

int tongUoc(const int& so) {
    int tong = 0;
    for (int i = 1; i <= so; ++i) {
        if (so % i == 0) {
            tong += i;
        }
    }
    return tong;
}

bool kiemTraTestCase(const int& so) {
    return so >= 1 && so <= 100;
}

bool kiemTraSoNguyenDuong(const int& so) {
    return so >= 1 && so <= 10^9;
}

int main()
{
    int testCase = 0;
    cout << "nhap so luong test case: ";
    cin >> testCase;
    
    if (!kiemTraTestCase(testCase)) {
        cout << "so test case phai lon hon hoac bang 1 va be hon hoac bang 100!" << endl;
        return 0;
    } 

    for (int i = 0; i < testCase; ++i) {
        cout << "test case " << i + 1 << endl;
        
        int soNguyen = 0;
        cout << "nhap 1 so nguyen duong: ";
        cin.ignore();
        cin >> soNguyen;
        
        if (!kiemTraSoNguyenDuong(soNguyen)) {
            cout << "so nguyen duong phai lon hon hoac bang 1 va be hon hoac bang 10^9!" << endl;
            break;
        }
        
        int ketQua = tongUoc(soNguyen);
        cout << "tong uoc cua so nguyen " << soNguyen << " la: " << ketQua << endl;
    }

    return 0;
}
