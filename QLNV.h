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
    void Save();    //lÆ°u láº¡i thÃ´ng tin nv vÃ o file sau khi chá»‰nh sá»­a
    void Show();    //show thÃ´ng tin nv
    void Add(NhanVien);                   //2 hÃ m dÃ¹ng Ä‘á»ƒ thÃªm nv
    void Add(int,string,string,string);   
    void Addelement();                    //them 1 luc nhieu nv
    int Delete(int);                     //xoa 1 nv
    void Remove();                        //xoa nhieu nv
    NhanVien& operator[](int);            //Ä‘a nÄƒng hoÃ¡ toÃ¡n tá»­
    void Reset();                         //reset dsnv
    int getNumber();    
    void Update();                  
};