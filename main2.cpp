#include <iostream>
#include "PhanSo.h"

using namespace std;

int main()
{
    PhanSo a, b;
    cout<<"Nhap phan so A: ";
    a.Nhap();
    cout<<"Nhap phan so B: ";
    b.Nhap();

    cout<<"\nPhan so A: ";
    a.RutGon();
    a.Xuat();
    cout<<"\nPhan so B: ";
    b.RutGon();
    b.Xuat();

    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);

    cout<<"\n\nTong: ";
    tong.Xuat();
    cout<<"\nHieu: ";
    hieu.Xuat();
    cout<<"\nTich: ";
    tich.Xuat();
    PhanSo thuong = a.Thuong(b);
    if (thuong.SoSanh(thuong) != -1) {
        cout << "\Thuong: ";
        thuong.Xuat();
    }

    cout<<"\n\n";
    int tem = a.SoSanh(b);
    if (tem==0) cout<<"2 phan so bang nhau.";
    else if (tem==1){
        cout<<"Phan so A lon hon";
    }
    else{
        cout<<"Phan so B lon hon";
    }
    return 0;
}
