#include"NhanVien.h"
NhanVien::NhanVien(int id, string name,string user,string pass){
    this->_id=id;
    this->_name=name;
    this->_user=user;
    this->_pass=pass;
}
NhanVien::~NhanVien(){};
void NhanVien::Show(){
    cout<<_id<<"\t\t"<<_name<<"\t\t"<<_user<<"\t\t"<<_pass<<endl;
}
void NhanVien::Update(){
    int n;
    cout<<"Nhap ma nhan vien:";cin>>this->_id;
    cout<<"Nhap ten nhan vien:";cin>>this->_name;
    cout<<"Cap nhat tai khoan:";
    cin>>this->_user;
    cout<<"Cap nhat mat khau:";
    cin>>this->_pass;
}
int NhanVien::getID(){
    return this->_id;
}
string NhanVien::getName(){
    return this->_name;
}
string NhanVien::getUser(){
    return this->_user;
}
string NhanVien::getPass(){
    return this->_pass;
}
