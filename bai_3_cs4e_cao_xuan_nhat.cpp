/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// bai 3
#include <iostream>
#include <string>
using namespace std;

string maHoa(const string &chuoi) {
    string ketQua = "";
    int count = 1;
    
    for (int i = 0; i < chuoi.length(); ++i) {
        if (chuoi[i] == chuoi[i + 1] && i + 1 < chuoi.length()) {
            count++;
        } else {
            ketQua += chuoi[i] + to_string(count);
            count = 1;
        }
    }
    
    return ketQua;
}

bool kiemTraKyTu(const string &chuoi) {
    for (char ch : chuoi) {
        if (isspace(ch)) return false;
    }
    return true;
}

int main()
{
    string chuoi;
    cout << "nhap vao 1 chuoi de ma hoa: ";
    getline(cin, chuoi);
    
    if (!kiemTraKyTu(chuoi)) {
        cout << "chuoi nhap vao khong hop le. vui long thu lai!" << endl;
        return 0;
    }
    
    string ketQua = maHoa(chuoi);
    cout << "chuoi sau khi ma hoa: " << ketQua << endl;

    return 0;
}
