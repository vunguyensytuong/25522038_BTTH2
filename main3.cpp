#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main()
{
    SoPhuc a, b;
    cout<<"Nhap so phuc A: ";
    a.Nhap();
    cout<<"Nhap so phuc B: ";
    b.Nhap();
    cout<<"\nSo phuc A: ";
    a.Xuat();
    cout<<"So phuc B: ";
    b.Xuat();

    SoPhuc tong, hieu, tich, thuong;
    tong=a.Tong(b);
    hieu=a.Hieu(b);
    tich=a.Tich(b);
    thuong=a.Thuong(b);
    cout<<"\nTong 2 so phuc la: ";
    tong.Xuat();
    cout<<"Hieu 2 so phuc la: ";
    hieu.Xuat();
    cout<<"Tich 2 so phuc la: ";
    tich.Xuat();
    cout<<"Thuong 2 so phuc la: ";
    thuong.Xuat();

    return 0;
}
