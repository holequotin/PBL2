#include"HangHoa.h"
#include<iomanip>
#include<fstream>
#include<string>
#include"QuanLyChiTieu.h"
class QuanLyHangHoa{
    protected:
    int _number;
    HangHoa *_p;
    public:
    QuanLyHangHoa(int=0,HangHoa*p=nullptr);
    ~QuanLyHangHoa();
    void Save();
    //lấy số lượng hàng hóa trong dãy
    int getNumber();
    //lấy số lượng của hàng hóa có mã là string
    int getNumber(string);
    void setNumber(string,int);
    void Show();//chức năng
    void Add(HangHoa);
    void Add(string,string,int,int);
    void AddElement();//chức năng
    void Delete(string);//Delete one elemnet have id=string s
    void Remove();//chức năng
    void Update();
    //In ra thông tin của hàng hóa có mã là s
    HangHoa Element(string);
    void EnterStock(QuanLyChiTieu&a);//Nhập kho
    void ExportStock(); //Xuất kho
    HangHoa& operator[](int);
    void Order(string ,int );
    void Return(string ,int);
    void Reset();
};