#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<ctime>
#pragma once
using namespace std;
class QuanLyPhienLamViec{
    private:
        string _name;
        int taikhoan;
    public:
        QuanLyPhienLamViec();
        ~QuanLyPhienLamViec();
        int DangNhap();            //đăng nhập
        void LuuTruTienNV(int);     //lưu trữ tiền nv thu được trong 1 ngày
        void TongTienNV();          //hổ trợ hàm trên
        void xuatNV();              //xuất tên nv, để chọn tên khi dùng chuc năng khác
        void xuattimedn(int);       //xuất thời gian nv đăng nhập
        void xuatTNNV(int);//xuất tiền nv thu trong các ngày có time kèm
        string getName();         
};