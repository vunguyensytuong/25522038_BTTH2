#include <iostream>
#include <string>
#include "SoPhuc.h"
using namespace std;

// chuyển string sang int
float strtofloat(string a){
    return stof(a);
}

// kiểm tra string có phải số nguyên hợp lệ không
//input: một chuỗi
// trả về true nếu đúng

bool checkfloat(string a){
    int bdau=0;
    int demDauCham=0;

    if (a[0]=='-'){
        if (a.length()==1) return false; // chỉ có dấu -
        bdau=1;
    }

    for (int i=bdau;i<a.length();i++){
        if(a[i]=='.'){
            demDauCham++;
            if(demDauCham>1) return false;
        }
        else if (a[i]<'0'||a[i]>'9') return false;
    }
    if (a=="." || a=="-.") return false;
    return true;
}


//input: nhập 2 chuỗi string; output: gán 2 chuỗi string vào số phức a
void SoPhuc::Nhap(){
    string tem1, tem2;
    while(true){
        cin>>tem1>>tem2;
        if(checkfloat(tem1)&&checkfloat(tem2)){
            iThuc=strtofloat(tem1);
            iAo=strtofloat(tem2);
            break;
        }
        cout<<"Nhap khong hop le.\nVui long nhap lai: ";
    }
}

//input: số phức a; output: in ra màn hình số phức a dạng a+bi
void SoPhuc::Xuat(){
    if (iThuc==0&&iAo==0) cout<<0;
    else if (iAo==0) cout<<iThuc;
    else if (iThuc==0) cout<<iAo<<'i';
    else{
        if(iAo > 0) cout<<iThuc<<'+'<<iAo<<'i';
        else cout<<iThuc<<iAo<<'i';
    }
    cout<<'\n';
}

//input: 2 số phức; output: tổng của 2 số phức
SoPhuc SoPhuc::Tong(SoPhuc b){
    SoPhuc tong;
    tong.iThuc=iThuc+b.iThuc;
    tong.iAo=iAo+b.iAo;
    return tong;
}

//input: 2 số phức; output: hiệu 2 số phức
SoPhuc SoPhuc::Hieu(SoPhuc b){
    SoPhuc hieu;
    hieu.iThuc=iThuc-b.iThuc;
    hieu.iAo=iAo-b.iAo;
    return hieu;
}

//input: 2 số phức; output: tích 2 số phức
SoPhuc SoPhuc::Tich(SoPhuc b){
    SoPhuc tich;
    tich.iThuc=(iThuc*b.iThuc-iAo*b.iAo);
    tich.iAo=(iThuc*b.iAo+iAo*b.iThuc);
    return tich;
}

//input: 2 số phức; output: thương 2 số phức
SoPhuc SoPhuc::Thuong(SoPhuc b){
    SoPhuc thuong;
    float mau = b.iAo*b.iAo+b.iThuc*b.iThuc;
    if(mau == 0){
        cout<<"Loi: Mau bang 0.\n";
        thuong.iThuc = 0;
        thuong.iAo = 0;
        return thuong;
    }
    thuong.iThuc=(iThuc*b.iThuc+iAo*b.iAo)/mau;
    thuong.iAo=(iAo*b.iThuc-iThuc*b.iAo)/mau;
    return thuong;
}
