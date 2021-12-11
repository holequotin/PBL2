#include"QuanLyNV.h"
QLNV::QLNV(int n,NhanVien*p){
    this->_p=p;
    this->_number=n;
    ifstream myfile("NhanVien.txt");
    while (!myfile.eof())
    {
        int id;
        string name;
        string user,pass;
        myfile>>id;
        getline(myfile,name);
        myfile>>user;
        myfile>>pass;
        NhanVien h(id,name,user,pass);
        this->Add(h);
    }
    myfile.close();
}
//Destructor
QLNV::~QLNV(){}

void QLNV::Add(int id,string name,string user,string pass){
    NhanVien h1(id,name,user,pass);
    Add(h1);
}
void QLNV::Add(NhanVien h1){
        if(this->_number==0){
            this->_p=new NhanVien[_number+1];
            *(_p+_number)=h1;
            _number++;
        }else{
            NhanVien temp[_number];
            for(int i=0;i<this->_number;i++){
                if(((*(_p+i)).getID())==(h1.getID())){
                    cout<<"Ma hang hoa da ton tai"<<endl;
                    return;
                }
                temp[i]=*(this->_p+i);
            }
            _number++;
            this->_p=new NhanVien[_number];
            for(int i=0;i<this->_number-1;i++){
                *(this->_p+i)=temp[i];
            }
            *(this->_p+_number-1)=h1;
}
}
//Thêm nhiều hàng hóa(Chức năng)
void QLNV::Addelement(){
    do{
        system("cls");
        string name,user,x,pass;
        int id;
        this->Show();
        cout<<"Nhap ma Nhan Vien";cin>>id;
        cin.ignore();
        cout<<"Nhap ten Nhan Vien:";getline(cin,name);
        name=" "+name;
        cout<<"Nhap tai khoan:";cin>>user;
        cout<<"Nhap don gia:";cin>>pass;
        system("cls");
        this->Add(id,name,user,pass);
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
NhanVien& QLNV::operator[](int x){
    return *(this->_p+x);
}
void QLNV::Delete(int s){
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
void QLNV::Remove(){
    do{ 
        system("cls");
        string x;
        int s;
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
void QLNV::Show(){
    cout<<"MANV"<<setw(25)<<"TEN NHAN VIEN"<<"\t\t"<<"TAI KHOAN"<<"\t"<<"MAT KHAU"<<endl;
    for(int i=0;i<this->_number;i++){
        cout<<(*(_p+i)).getID()<<setw(25)<<(*(_p+i)).getName()<<"\t\t"<<(*(_p+i)).getUser()
            <<"\t\t"<<(*(_p+i)).getPass()<<endl;
    }
}
void QLNV::Save(){
    ofstream myfile("NhanVien.txt");
    for(int i=0;i<this->getNumber();i++){
        myfile<<(*(this))[i].getID()<<(*(this))[i].getName()<<"\n"<<(*(this))[i].getUser()<<" "<<(*(this))[i].getPass();
        if(i!=this->getNumber()-1) myfile<<"\n";
    }
}
int QLNV::getNumber(){
    return this->_number;
}
void QLNV::Reset(){
    this->_number=0;
    this->_p=nullptr;
}