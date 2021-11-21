#include<iostream>
#include<string>
using namespace std;
class HangHoa{
    protected:
    string _id;
    string _name;
    int _number;//dùng chung cho kho và bàn
    int _price;
    public:
    HangHoa(string="0",string="No name",int = 0, int = 0);
    string getID();
    string getName();
    int getNumber();
    void setNumber(int);
    int getPrice();
    void Show();
    void Update();
    void AddNumber(int);
    void DeleteNumber(int);
};