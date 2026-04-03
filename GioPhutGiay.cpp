#include <iostream>
#include <string>
#include "GioPhutGiay.h"
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

//Kiểm tra giờ hợp lệ
//input: số nguyên chỉ giờ; output: đúng nếu giờ hợp lệ
bool Gio(int a){
    if (a<0||a>=24) return false;
    return true;
}

//Kiểm tra phút hoặc giây
//input: số nguyên chỉ phút/giây; output: đúng nếu phút/giây hợp lệ
bool PhutGiay(int a){
    if (a<0||a>=60) return false;
    return true;
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

//input: 3 chuỗi; output: giờ phút giây
void GioPhutGiay::Nhap(){
    string tem1, tem2, tem3;
    cout<<"Nhap gio: ";
    cin>>tem1;
    while (!checkint(tem1) || !Gio(strtoint(tem1))){
        if (!checkint(tem1)) {
            cout<<"Loi: Gio phai la so nguyen (khong chua chu/ky tu).\nVui long nhap lai: ";
        } else {
            cout<<"Loi: Gio phai nam trong khoang tu 0 den 23.\nVui long nhap lai: ";
        }
        cin>>tem1;
    }
    iGio=strtoint(tem1);

    cout<<"Nhap phut: ";
    cin>>tem2;
    while (!checkint(tem2) || !PhutGiay(strtoint(tem2))){
        if (!checkint(tem2)) {
            cout<<"Loi: Phut phai la so nguyen (khong chua chu/ky tu).\nVui long nhap lai: ";
        } else {
            cout<<"Loi: Phut phai nam trong khoang tu 0 den 59.\nVui long nhap lai: ";
        }
        cin>>tem2;
    }
    iPhut=strtoint(tem2);

    cout<<"Nhap giay: ";
    cin>>tem3;
    while (!checkint(tem3) || !PhutGiay(strtoint(tem3))){
        if (!checkint(tem3)) {
            cout<<"Loi: Giay phai la so nguyen (khong chua chu/ky tu).\nVui long nhap lai: ";
        } else {
            cout<<"Loi: Giay phai nam trong khoang tu 0 den 59.\nVui long nhap lai: ";
        }
        cin>>tem3;
    }
    iGiay=strtoint(tem3);
}

//input: Giờ phút giây; output: Xuất ra màn hình giờ phút giây
void GioPhutGiay::Xuat(){
    cout<<iGio<<" gio "<<iPhut<<" phut "<<iGiay<<" giay.\n";
}

//input: giờ phút giây; output: giờ phút giây sau khi đã cộng thêm 1 giây
//kiểm tra, nếu giây 60, phút thêm 1, giây về 0; phút 60, giờ cộng 1, phút về 0; giờ 24, giờ về 0
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay(){
    GioPhutGiay a = *this;
    a.iGiay=a.iGiay+1;
    if (!PhutGiay(a.iGiay)){
        a.iPhut=a.iPhut+1;
        a.iGiay=0;
        if (!PhutGiay(a.iPhut)){
            a.iPhut=0;
            a.iGio=a.iGio+1;
            if (!Gio(a.iGio)) a.iGio=0;
        }
    }
    return a;
}
