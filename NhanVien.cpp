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
    string s;
    cout<<"Nhap ten nhan vien:";
    getline(cin,s);
    this->_name=s;
    cout<<"Cap nhat tai khoan:";
    getline(cin,s);
    this->_user=s;
    cout<<"Cap nhat mat khau:";
    getline(cin,s);
    this->_pass=s;
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
void NhanVien::updeatID(){
    this->_id--;
}
