#include"HangHoa.h"
void set_color ( int code ) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}
HangHoa::HangHoa(string id,string name,int number,int price){
    this->_id=id;
    this->_name=name;
    this->_number=number;
    this->_price=price;
}
void HangHoa::Show(){
    cout<<_id<<"\t\t"<<_name<<"\t\t"<<_number<<"\t\t"<<_price<<endl;
}
void HangHoa::Update(){
    int n;
    cout<<"Nhap ma san pham:";cin>>this->_id;
    cout<<"Nhap ten san pham:";cin>>this->_name;
    cout<<"Cap nhat so luong:";
    cin>>n;
    this->_number=n;
    cout<<"Cap nhat don gia:";
    cin>>n;
    this->_price=n;
}

string HangHoa::getID(){
    return this->_id;
}
string HangHoa::getName(){
    return this->_name;
}
int HangHoa::getNumber(){
    return this->_number;
}
int HangHoa::getPrice(){
    return this->_price;
}
void HangHoa::AddNumber(int n){
    this->_number=this->_number+n;
}
void HangHoa::DeleteNumber(int n){
    if(n>this->getNumber()){
        cout<<"SO LUONG HANG TRONG KHO KHONG DU"<<endl;
    }
    else{
         this->_number=this->_number-n;
    }
}
void HangHoa::setNumber(int n){
    this->_number=n;
}