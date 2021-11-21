#include"HangHoa.h"
#include<iomanip>
#include<fstream>
#include<string>
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
    void Show();
    // /void ShowMenu();
    void Add(HangHoa);
    void Add(string,string,int,int);
    void AddElement();
    void Delete(string);//Delete one elemnet have id=string s
    //xóa một lúc nhiều hàng hóa
    void Remove();
    //Show element has ID=string input from keyboard
    HangHoa Element(string);
    void EnterStock();
    void ExportStock();
    HangHoa& operator[](int);
    void Order(string ,int );
    void Return(string ,int);
    void Reset();
};