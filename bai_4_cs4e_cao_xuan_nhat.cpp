/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// bai 4
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool kiemTraSoNguyenTo(int so) {
    if (so <= 1) return false;
    
    for (int i = 2; i < so; ++i) {
        if (so % i == 0) return false;
    }
    
    return true;
}

bool kiemTraSoSieuNguyenTo (int so) {
    if (!kiemTraSoNguyenTo(so)) return false;
    
    int temp = so;
    while (temp > 0) {
        if (!kiemTraSoNguyenTo(temp)) return false;
        temp /= 10;
    }
    
    return true;
}

vector<int> superPrimeNumber(int so) {
    vector<int> myVector;
    queue<int> q;
    
    for (int i = 2; i <= so; ++i) {
        if (kiemTraSoSieuNguyenTo(i)) {
            myVector.push_back(i);
            q.push(i);
        }
    }
    
    return myVector;
}

int main()
{
    int so;
    cout << "nhap vao 1 so nguyen duong: ";
    cin >> so;
    
    vector<int> superPrimeNumbers = superPrimeNumber(so);
    
    cout << "cac so sieu nguyen to be hon " << so << " la: " << endl;
    if (superPrimeNumbers.empty()) {
        cout << "khong co so nguyen duong hop le!" << endl;
    } else {
        for (int i : superPrimeNumbers) {
            cout << i << " ";
        }
    }

    return 0;
}
