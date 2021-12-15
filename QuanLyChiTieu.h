#include<string>
#include<ctime>
#include<cstdio>
#include<fstream>
#include<iostream>
using namespace std;
class QuanLyChiTieu{
    public:
        int TongTienThu;
        int TongTienChi;
    public:
        QuanLyChiTieu();
        ~QuanLyChiTieu();
        void ThuTien(int);
        int XuatTienThu();
        int XuatTienThuHD();
        void ChiTien(int);
        int XuatTienChi();
        void resetTienThu();
        void resetTienThuHD();
};