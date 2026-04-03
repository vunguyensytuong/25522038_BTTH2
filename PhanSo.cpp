#include <iostream>
#include <string>
#include <cmath>
#include "PhanSo.h"
using namespace std;

// hàm tìm ước chung lớn nhất (dùng đệ quy)
//input: 2 số nguyên; output: ước chung lớn nhất của 2 số
int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return ucln(b, a % b);
}

// chuyển string sang int
int strtoint(string a){
    int nhan=1,bdau=0,kq=0;

    // kiểm tra dấu âm
    if (a[0]=='-'){
        nhan=-1;
        bdau=1;
    }

    // duyệt từng ký tự để chuyển sang số
    for (int i=bdau;i<a.length();i++){
        kq=(a[i]-'0')+kq*10;
    }
    return kq*nhan;
}

// kiểm tra string có phải số nguyên hợp lệ không
//input: một chuỗi
// trả về true nếu đúng
bool checkint(string a){
    int bdau=0;

    if (a[0]=='-'){
        if (a.length()==1) return false; // chỉ có dấu -
        bdau=1;
    }

    for (int i=bdau;i<a.length();i++){
        if (a[i]<'0'||a[i]>'9') return false;
    }
    return true;
}

void PhanSo::Nhap(){
    string tem1, tem2;
    bool hopLe = false;

    while (!hopLe) {
        //nhập vào 2 chuỗi, xét xem 2 chuỗi có phải số nguyên và hợp lệ không
        cin >> tem1 >> tem2;

        if (!checkint(tem1) || !checkint(tem2)) {
            cout << "Loi: Tu so hoac mau so chua ky tu khong hop le.\nVui long nhap lai: ";
            continue;
        }

        int tu = strtoint(tem1);
        int mau = strtoint(tem2);

        if (mau == 0) {
            cout << "Loi: Mau so khong duoc phep bang 0.\nVui long nhap lai: ";
            continue;
        }

        iTu = tu;
        iMau = mau;
        hopLe = true;
    }
}

void PhanSo::Xuat(){
    // in kết quả
    if (iTu==0||iMau==1) cout<<iTu<<"\n";
    else cout<<iTu<<'/'<<iMau<<"\n";
}

//input: 1 phân số chưa rút gọn; output: phân số đã rút gọn và đã chuẩn hóa
PhanSo PhanSo::RutGon(){
    int i=ucln(iTu,iMau);

    iTu=iTu/i;
    iMau=iMau/i;

    // chuẩn hóa dấu: mẫu số luôn dương
    if (iMau < 0){
        iMau *= -1;
        iTu *= -1;
    }

    return *this;
}

//input: 2 số nguyên; output: bcnn của 2 số
int bcnn(int a, int b){
    return abs(a*b)/ucln(a,b);
}

//input: 2 phân số; output: 2 phân số đã quy đồng
void quydong(PhanSo &a, PhanSo &b){
    int m1=a.iMau, m2=b.iMau;
    // quy đồng
    int bc=bcnn(m1,m2);

    a.iTu=a.iTu*bc/a.iMau;
    b.iTu=b.iTu*bc/b.iMau;
    a.iMau=bc;
    b.iMau=bc;
}

//input: 2 phân số; output; Tổng của 2 phân số đã rút gọn
PhanSo PhanSo::Tong(PhanSo b){
    PhanSo c;
    PhanSo tempA = *this;
    quydong(tempA, b);
    c.iMau=tempA.iMau;
    c.iTu=tempA.iTu+b.iTu;
    return c.RutGon();
}

//input: 2 phân số; output; Hiệu của 2 phân số đã rút gọn
PhanSo PhanSo::Hieu(PhanSo b){
    PhanSo c;
    PhanSo tempA = *this;
    quydong(tempA, b);
    c.iMau=tempA.iMau;
    c.iTu=tempA.iTu-b.iTu;
    return c.RutGon();
}

//input: 2 phân số; output: tích đã rút gọn
PhanSo PhanSo::Tich(PhanSo b){
    PhanSo c;
    //Rút gọn để khi nhân vào số không quá lớn
    PhanSo tempA = *this;
    tempA.RutGon();
    b.RutGon();

    c.iMau=tempA.iMau*b.iMau;
    c.iTu=tempA.iTu*b.iTu;
    return c.RutGon();
}

//input: 2 phân số; output: thương đã rút gọn
PhanSo PhanSo::Thuong(PhanSo b){
    PhanSo c;
    PhanSo tempA = *this;
    tempA.RutGon();
    b.RutGon();

    if (b.iTu == 0){
        cout<<"\nKhong the chia cho 0.";
        c.iTu = 0;
        c.iMau = 0;
        return c;
    }

    c.iTu=tempA.iTu*b.iMau;
    c.iMau=tempA.iMau*b.iTu;
    return c.RutGon();
}

//input: 2 phân số; output: phân số lớn hơn
int PhanSo::SoSanh(PhanSo b){
    PhanSo tempA = *this;
    quydong(tempA, b);
    if (tempA.iTu==b.iTu) return 0;
    if(tempA.iTu>b.iTu) return 1;
    return 2;
}
