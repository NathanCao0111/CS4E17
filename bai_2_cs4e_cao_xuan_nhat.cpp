/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// bai 2
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Vemaybay {
    private:
    string tenchuyen;
    string ngaybay;
    int giave;
    
    public:
    Vemaybay() {
        this->tenchuyen = "";
        this->ngaybay = "";
        this->giave = 0;
    }
    ~Vemaybay() {
        this->tenchuyen = "";
        this->ngaybay = "";
        this->giave = 0;
    }
    void nhap() {
        cout << "nhap ten chuyen: ";
        getline(cin, this->tenchuyen);
        
        cout << "nhap ngay bay: ";
        getline(cin, this->ngaybay);
        
        cout << "nhap gia ve: ";
        cin >> this->giave;
    }
    void xuat() {
        cout << "ten chuyen: " << this->tenchuyen << endl;
        cout << "ngay bay: " << this->ngaybay << endl;
        cout << "gia ve: " << this->giave << endl;
    }
    int getgiave() {
        return this->giave;
    }
};

class Nguoi {
    private:
    string hoten;
    string gioitinh;
    int tuoi;
    
    public:
    Nguoi() {
        this->hoten = "";
        this->gioitinh = "";
        this->tuoi = 0;
    }
    ~Nguoi() {
        this->hoten = "";
        this->gioitinh = "";
        this->tuoi = 0;
    }
    void nhap() {
        cout << "nhap ho ten: ";
        getline(cin, this->hoten);
        
        cout << "nhap gioi tinh: ";
        getline(cin, this->gioitinh);
        
        cout << "nhap tuoi: ";
        cin >> this->tuoi;
    }
    void xuat() {
        cout << "ho ten: " << this->hoten << endl;
        cout << "gioi tinh: " << this->gioitinh << endl;
        cout << "tuoi: " << this->tuoi << endl;
    }
};

class hanhkhach : public Nguoi {
    private:
    int soluong;
    Vemaybay* ve;
    
    public:
    hanhkhach() {
        this->soluong = 0;
        this->ve = nullptr;
    }
    ~hanhkhach() {
        this->soluong = 0;
        delete[] ve;
    }
    void nhap() {
        Nguoi::nhap();
        cout << "nhap so luong ve may bay: ";
        cin >> this->soluong;
        
        this->ve = new Vemaybay[this->soluong];
        for (int i = 0; i < this->soluong; ++i) {
            cout << "nhap thong tin ve may bay thu " << i + 1 << endl;
            cin.ignore();
            ve[i].nhap();
        }
    }
    void xuat() {
        Nguoi::xuat();
        
        for (int i = 0; i < this->soluong; ++i) {
            cout << "thong tin ve may bay thu " << i + 1 << endl;
            ve[i].xuat();
        }
        
        cout << "tong tien phai tra: " << tongtien() << endl;
    }
    int tongtien() {
        int tong = 0;
        for (int i = 0; i < this->soluong; ++i) {
            tong += ve[i].getgiave();
        }
        return tong;
    }
};

bool soSanh(hanhkhach &a, hanhkhach &b) {
    return a.tongtien() > b.tongtien();
}

int main()
{
    int size;
    cout << "nhap so luong hanh khach: ";
    cin >> size;
    
    hanhkhach *danhsach = new hanhkhach[size];
    
    for (int i = 0; i < size; ++i) {
        cout << "nhap thong tin hanh khach thu " << i + 1 << endl;
        cin.ignore();
        danhsach[i].nhap();
    }
    
    cout << "danh sach hanh khach truoc khi sap xep" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "thong tin hanh khach thu " << i + 1 << endl;
        danhsach[i].xuat();
    }
    
    sort(danhsach, danhsach + size, soSanh);
    
    cout << "danh sach hanh khach sau khi sap xep theo thu tu giam dan (theo gia ve)" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "thong tin hanh khach thu " << i + 1 << endl;
        danhsach[i].xuat();
    }
    
    delete[] danhsach;

    return 0;
}
