#include<iostream>
#include"QuanLyMenu.h"
#include"QuanLyPhienLamViec.h"
#pragma once
using namespace std;
class Ban{
    public:
    string _id;
    QuanLyMenu _q;//dánh sách các món đã kêu
    bool _status;//true là đang trống, false là đang có khách
    int _pay;//Số tiền phải thanh toán
    public:
    Ban(string id="0",QuanLyMenu q = QuanLyMenu(0,nullptr),bool=true,int=0);
    //~Ban();
    //trả về giá trị tiền đang có ở bàn
    int Pay();
    //hàm đặt bàn từ danh sách món ăn p
    void Book(QuanLyHangHoa &p);
    //hàm đặt thêm món=>hình như là trùng với hàm book
    //void Order(string);
    //xem tình trạng của bàn
    void Show();
    //hàm hủy món ăn
    void Cancel(string,QuanLyHangHoa&);//Huy mon an co ma la string
    //in ra hóa đơn ra file Hoadon.txt rồi trả bàn
    void Bill(QuanLyChiTieu &a,QuanLyPhienLamViec &b);
    

};
