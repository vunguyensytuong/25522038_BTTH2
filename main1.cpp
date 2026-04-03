#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main()
{
    NgayThangNam a;

    cout<<"Nhap ngay thang nam: ";
    a.Nhap();

    cout<<"\nNgay thang nam vua nhap la: ";
    a.Xuat();

    NgayThangNam b;
    b = a.NgayThangNamTiepTheo();

    cout<<"\nNgay thang nam tiep theo la: ";
    b.Xuat();

    return 0;
}
