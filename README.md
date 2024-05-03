# CS4E17

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

----------

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

----------

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

----------

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
