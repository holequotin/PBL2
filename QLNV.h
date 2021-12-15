#include"NhanVien.h"
#pragma once
class QLNV{
    protected:
    int _dem=0;
    int _number;
    NhanVien *_p;
    public:
    QLNV(int=0,NhanVien*p=nullptr);
    ~QLNV();
    void Save();    //lưu lại thông tin nv vào file sau khi chỉnh sửa
    void Show();    //show thông tin nv
    void Add(NhanVien);                   //2 hàm dùng để thêm nv
    void Add(int,string,string,string);   
    void Addelement();                    //them 1 luc nhieu nv
    void Delete(int);                     //xoa 1 nv
    void Remove();                        //xoa nhieu nv
    NhanVien& operator[](int);            //đa năng hoá toán tử
    void Reset();                         //reset dsnv
    int getNumber();    
    void Update();                  
};