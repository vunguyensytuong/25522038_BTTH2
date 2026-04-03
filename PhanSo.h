#ifndef PHANSO_H
#define PHANSO_H

class PhanSo
{
public:
    int iTu, iMau;
    void Nhap();
    void Xuat();
    PhanSo RutGon();
    PhanSo Tong(PhanSo b);
    PhanSo Hieu(PhanSo b);
    PhanSo Tich(PhanSo b);
    PhanSo Thuong(PhanSo b);
    int SoSanh(PhanSo b);
};

#endif // PHANSO_H
