#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

int main()
{
    GioPhutGiay a;
    cout<<"Nhap gio phut giay\n";
    a.Nhap();

    a.Xuat();

    GioPhutGiay b;
    b=a.TinhCongThemMotGiay();
    cout<<"\n\nSau 1 giay:\n";
    b.Xuat();

    return 0;
}
