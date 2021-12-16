#include"QLNV.h"
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
                if(((*(_p+i)).getUser())==(h1.getUser())){
                    cout<<"Tai khoan da ton tai"<<endl;
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
        id = _number + 1; 
        cin.ignore();
        cout<<"Nhap ten Nhan Vien muon them:";getline(cin,name);
        name=" "+name;
        cout<<"Nhap tai khoan:";cin>>user;
        cout<<"Nhap mat khau:";cin>>pass;
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
int QLNV::Delete(int s){                                            //hàm trả về số nguyên để kt nv tồn tại ko
    int k=-1;
    for(int i=0;i<this->_number;i++){
        if(s==((*(this->_p+i)).getID())){
            k=i;
            break;
        }
    }
    if(k==-1) 
    {   
        return -1;
    }    
    if(this->_number==1){
        this->Reset();
        return 1;
    }
    for(int i=k;i<this->_number-1;i++){
        (_p+i+1)->UpdateID();
        *(_p+i)=*(_p+i+1);
    }
    _number--;
    return 1;
}
//Xóa nhiều hàng hóa(Chức năng)
void QLNV::Remove(){
    int a;
    do{ 
        system("cls");
        do{
        //system("cls");
        //string x;
        int s;
        this->Show();
        cout<<"Nhap ma nhan vien muon xoa:";cin>>s;
        a=this->Delete(s);
        cout<<a;
        system("cls");
        this->Show();
        if(a==1){                                            
        cout<<"Da xoa nhan vien!!"<<endl;                                      //cái if ni kiểm tra coi có thèn nv nớ k        
        }
            else 
            {   
                system("cls");
                cout<<"Nhan vien khong ton tai, vui long nhap lai: "<<endl;
            }    
        }while(a==-1);
        cout<<"Ban co muon xoa nua khong[y/n]:";
        string x;
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
void QLNV::Update(){
        do{
        int i,s; 
        string x;
        this->Show();
        cout<<"Nhap ma nhan vien muon cap nhat:";cin>>s;
        cin.ignore();
        for(i=0;i<this->_number;i++){
            if((*this)[i].getID()==s){
                (*this)[i].Update();
                break;
            }
        }
        if(i==this->_number){
            system("cls");
            cout<<"Ma nhan vien khong ton tai!!"<<endl;
            continue;
        }
        system("cls");
        this->Show();
        cout<<"Da cap nhat nhan vien!!"<<endl;
        cout<<"Ban co muon cap nhat nua khong[y/n]:";
        cin>>x;
         while (x!="y"&&x!="n")
        {
            cout<<"Chon sai chuc nang, vui long nhap lai:";
            cin>>x;
        }
        system("cls");
        if(x=="y") continue;
        else break;
    }while(true);
}
