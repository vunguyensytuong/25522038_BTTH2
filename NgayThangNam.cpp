#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;

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

//input: 3 số nguyên đại diện cho ngày tháng năm; output: true nêú ngày hợp lệ
bool KiemTraNgayHopLe(int a, int b, int c){
    if (a<=0||b<=0||c<=0) return false;
    switch (b) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: if (a>31) return false; break;
    case 4:
    case 6:
    case 9:
    case 11: if (a>30) return false; break;
    case 2:
        if (c%4==0) {if (a>29) {return false;} break;}
        if (a>28) return false; break;
    default: return false;
    }
    return true;
}

//input: 3 chuỗi string, kiểm tra xem có phải ngày hợp lệ không; output: ngày tháng năm được gán vào biến a
void NgayThangNam::Nhap(){
    string tem1, tem2, tem3;
    bool hopLe = false;

    while (!hopLe) {
        cin >> tem1 >> tem2 >> tem3;

        if (!checkint(tem1) || !checkint(tem2) || !checkint(tem3)) {
            cout << "Loi: Ngay, thang, nam phai la so nguyen (khong chua chu cai/ky tu dac biet).\nVui long nhap lai: ";
            continue;
        }

        int d = strtoint(tem1);
        int m = strtoint(tem2);
        int y = strtoint(tem3);

        if (d <= 0 || m <= 0 || y <= 0) {
            cout << "Loi: Ngay, thang, nam phai la so duong (lon hon 0).\nVui long nhap lai: ";
            continue;
        }

        if (m > 12) {
            cout << "Loi: Mot nam chi co 12 thang.\nVui long nhap lai: ";
            continue;
        }

        if (!KiemTraNgayHopLe(d, m, y)) {
            if (m == 2) {
                if (y % 4 == 0) cout << "-> Loi: Thang 2 nam nhuan chi co toi da 29 ngay.\nVui long nhap lai: ";
                else cout << "Loi: Thang 2 nam khong nhuan chi co toi da 28 ngay.\nVui long nhap lai: ";
            } else {
                cout << "Loi: Thang " << m << " khong the co " << d << " ngay.\nVui long nhap lai: ";
            }
            continue;
        }

        iNgay = d;
        iThang = m;
        iNam = y;
        hopLe = true;
    }
}

//input: Ngày tháng năm; output: ngày tháng năm theo d/m/y
void NgayThangNam::Xuat(){
    cout<<iNgay<<'/'<<iThang<<'/'<<iNam<<"\n\n";
}

//input: Ngày tháng năm; output: ngày tháng năm tiếp theo, nếu qua tháng/năm mới sẽ cập nhật
NgayThangNam NgayThangNam::NgayThangNamTiepTheo(){
    NgayThangNam kq = *this;
    kq.iNgay = kq.iNgay + 1;
    switch (kq.iThang) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10: if (kq.iNgay>31) {kq.iNgay=1; kq.iThang=kq.iThang+1;} break;
    case 12: if (kq.iNgay>31) {kq.iNgay=1; kq.iThang=1; kq.iNam=kq.iNam+1;} break;
    case 4:
    case 6:
    case 9:
    case 11: if (kq.iNgay>30) {kq.iNgay=1; kq.iThang=kq.iThang+1;} break;
    case 2:
        if (kq.iNam%4==0) {
            if (kq.iNgay>29) {kq.iNgay=1; kq.iThang=kq.iThang+1;}
        } else {
            if (kq.iNgay>28) {kq.iNgay=1; kq.iThang=kq.iThang+1;}
        }
        break;
    }
    return kq;
}
