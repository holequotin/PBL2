#include"QuanLyHangHoa.h"
//Constructor
QuanLyHangHoa::QuanLyHangHoa(int n,HangHoa*p){
    this->_p=p;
    this->_number=n;
    ifstream myfile("HangHoa.txt");
    while (!myfile.eof())
    {
        string id;
        string name;
        int number,price;
        myfile>>id;
        getline(myfile,name);
        myfile>>number;
        myfile>>price;
        HangHoa h(id,name,number,price);
        this->Add(h);
    }
    //nhớ là phải đóng file
    myfile.close();
};
//Destructor
QuanLyHangHoa::~QuanLyHangHoa(){}  
//Lưu thông tin
void QuanLyHangHoa::Save(){
    ofstream myfile("HangHoa.txt");
    for(int i=0;i<this->getNumber();i++){
        myfile<<(*(this))[i].getID()<<(*(this))[i].getName()<<"\n"<<(*(this))[i].getNumber()<<" "<<(*(this))[i].getPrice();
        if(i!=this->getNumber()-1) myfile<<"\n";
    }
}
//Hien thi danh sach hang hoa(Chức năng)
void QuanLyHangHoa::Show(){
    set_color(14);
    cout<<"MAHH"<<setw(25)<<"TEN HANG HOA"<<"\t\t"<<"SO LUONG"<<"\t"<<"DON GIA"<<endl;
    set_color(7);
    for(int i=0;i<this->_number;i++){
        cout<<(*(_p+i)).getID()<<setw(25)<<(*(_p+i)).getName()<<"\t\t"<<(*(_p+i)).getNumber()
            <<"\t\t"<<(*(_p+i)).getPrice()<<endl;
    }
}
//Thêm 1 hàng hóa
void QuanLyHangHoa::Add(HangHoa h1){
        if(this->_number==0){
            this->_p=new HangHoa[_number+1];
            *(_p+_number)=h1;
            _number++;
        }else{
            HangHoa temp[_number];
            for(int i=0;i<this->_number;i++){
                if(((*(_p+i)).getID())==(h1.getID())){
                    cout<<"Ma hang hoa da ton tai"<<endl;
                    return;
                }
                temp[i]=*(this->_p+i);
            }
            _number++;
            this->_p=new HangHoa[_number];
            for(int i=0;i<this->_number-1;i++){
                *(this->_p+i)=temp[i];
            }
            *(this->_p+_number-1)=h1;
}
}
//Thêm 1 hàng hóa
void QuanLyHangHoa::Add(string id,string name,int number,int price){
    HangHoa h1(id,name,number,price);
    Add(h1);
}
//Thêm nhiều hàng hóa(Chức năng)
void QuanLyHangHoa::AddElement(){
    do{
        system("cls");
        string id,name,x;
        int number,price;
        this->Show();
        cout<<"Nhap ma hang hoa";cin>>id;
        cin.ignore();
        cout<<"Nhap ten hang hoa:";getline(cin,name);
        name=" "+name;
        cout<<"Nhap so luong hang hoa:";cin>>number;
        cout<<"Nhap don gia:";cin>>price;
        system("cls");
        this->Add(id,name,number,price);
        this->Show();
        cout<<"Ban co muon them nua khong[y/n]:";
        cin>>x;
         while (x!="y"&&x!="n")
        {
            cout<<"Chon sai chuc nang, vui long nhap lai:";
            cin>>x;
        }
        if(x=="y") continue;
        else break;
    }while(true);
    
}
//Xem thông tin hàng hóa có mã là s
HangHoa QuanLyHangHoa::Element(string s){
    for(int i=0;i<this->_number;i++){
        if(s==((*this)[i].getID())){
            return (*this)[i];
        }
    }
    return (*this)[0];
}
//Xóa 1 hàng hóa
void QuanLyHangHoa::Delete(string s){
    int k=-1;
    for(int i=0;i<this->_number;i++){
        if(s==((*(this->_p+i)).getID())){
            k=i;
            break;
        }
    }
    if(k==-1) return;
    if(this->_number==1){
        this->Reset();
        return;
    }
    for(int i=k;i<this->_number-1;i++){
        *(_p+i)=*(_p+i+1);
    }
    _number--;
}
//Xóa nhiều hàng hóa(Chức năng)
void QuanLyHangHoa::Remove(){
    do{ 
        system("cls");
        string s,x;
        this->Show();
        cout<<"Nhap ma hang hoa muon xoa:";cin>>s;
        this->Delete(s);
        system("cls");
        this->Show();
        cout<<"Da xoa hang hoa khoi kho!!"<<endl;
        cout<<"Ban co muon xoa nua khong[y/n]:";
        cin>>x;
         while (x!="y"&&x!="n")
        {
            cout<<"Chon sai chuc nang, vui long nhap lai:";
            cin>>x;
        }
        if(x=="y") continue;
        else break;
    }while(true);
}
//Đa năng hóa toán tử
HangHoa& QuanLyHangHoa::operator[](int x){
    return *(this->_p+x);
}
//Nhập kho(Chức năng)
void QuanLyHangHoa::EnterStock(){
    system("cls");
    do{
    this->Show();
     int index=-1;
     string s;
     cout<<"Nhap ma hang hoa:";
     cin>>s;
     for(int i=0;i<this->getNumber();i++){
         if(s==(_p[i].getID())){
             index=i;
             break;
         }
     }
     if(index==-1){
         system("cls");
         cout<<"Ma hang hoa khong ton tai, vui long nhap lai:"<<endl;
         continue;
     }else{
         int n;
         string s;
         cout<<"Nhap so luong nhap vao kho:";
         cin>>n;
         system("cls");
         (*(this))[index].AddNumber(n);
         this->Show();
         cout<<"Ban co muon nhap them hang[y/n]:";
         cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Chon sai chuc nang, vui long nhap lai:";
            cin>>s;
        }
        if(s=="y") continue;
        else break;
        }
     }
    while (true);
}
//Xuất kho(chức năng)
void QuanLyHangHoa::ExportStock(){
    do{
    system("cls");
     int index=-1;
     string s;
     this->Show();
     cout<<"Nhap ma hang hoa:";
     cin>>s;
     for(int i=0;i<this->getNumber();i++){
         if(s==(_p[i].getID())){
             index=i;
             break;
         }
     }
     if(index==-1){
         system("cls");
         //this->Show();
         cout<<"Ma hang hoa khong ton tai, vui long nhap lai:"<<endl;
         continue;
     }else{
         int n;
         string s;
         cout<<"Nhap so luong xuat kho:";
         cin>>n;
         system("cls");
         (*(this))[index].DeleteNumber(n);
         this->Show();
         cout<<"Ban co muon xuat them hang[y/n]:";
         cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Chon sai chuc nang, vui long nhap lai:";
            cin>>s;
        }
        if(s=="y") continue;
        else break;
        }
     }
    while (true);
}
//Trả về số lượng hàng hóa có trong dãy
int QuanLyHangHoa::getNumber(){
    return this->_number;
}
//Trả về số lượng của hàng hóa có mã là s
int QuanLyHangHoa::getNumber(string s){
    for(int i=0;i<this->_number;i++){
        if((*this)[i].getID()==s){
            return (*this)[i].getNumber();
        }
    }
    return -1;
}
//Set số lượng hàng hóa có mã là s
void QuanLyHangHoa::setNumber(string s,int number){
    for(int i=0;i<this->_number;i++){
        if((*this)[i].getID()==s){
            (*this)[i].setNumber(number);
            break;
        }
    }
}
//Hàm trừ đi số lượng của hàng hóa có mã là s
void QuanLyHangHoa::Order(string s,int n){
    for(int i=0;i<this->_number;i++){
        if((*this)[i].getID()==s){
            (*this)[i].DeleteNumber(n);
            break;
        }
    }
}
//Hàm trả lại kho hàng hóa có mã là s với số lượng n
void QuanLyHangHoa::Return(string s,int n){
    for(int i=0;i<this->_number;i++){
        if((*this)[i].getID()==s){
            (*this)[i].AddNumber(n);
            break;
        }
    }
}
//Reset lại kho
void QuanLyHangHoa::Reset(){
    this->_number=0;
    this->_p=nullptr;
}