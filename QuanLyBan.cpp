#include"QuanLyBan.h"
//Constructor
QuanLyBan::QuanLyBan(int number)
{
    //tạo ra 10 bàn trước rồi có chi thêm sau
    this->_number=number;
    this->_p=new Ban[number+1];
    for(int i=0;i<this->_number+1;i++){
        if(i==0) (*this)[i]._id="Dat mang ve";
        else (*this)[i]._id="Ban so "+to_string(i);
    }
}
QuanLyBan::~QuanLyBan()
{
}
//Đa năng hóa toán tử
Ban& QuanLyBan::operator[](const int x){
    return (*(_p+x));
}
//Show tình trạng của dãy bàn
void QuanLyBan::Show(){
    cout<<setw(25)<<"MABAN\t\t\tTINHTRANG"<<endl;
    for(int i=1;i<this->_number+1;i++){
        string status;
        if(((*this)[i]._status==true)) status="Dang trong";
        else status="Chua thanh toan";
        //hàm ỉn ra
        cout<<setw(15)<<(*this)[i]._id<<"\t\t\t"<<status<<endl;
        cout<<"\t======================================"<<endl;
    }
}
//Đặt món
void QuanLyBan::Book(QuanLyHangHoa&p){
    do{
        this->Show();
        string s;
        cout<<"Nhap ban muon dat mon:";cin>>s;
        int x=stoi(s);
        if(x<1||x>this->_number){
            system("cls");
            cout<<"Ban khong hop le, vui long nhap lai:"<<endl;
            continue;
        }else{
            (*this)[x].Book(p);
        }
        system("cls");
        cout<<"Ban so  "<<x<<" dang dat cac mon sau"<<endl;
        cout<<"======================="<<endl;
        (*this)[x].Show();
        cout<<"Ban co muon dat ban nua khong[y/n]:";cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Nhap sai, vui long nhap lai:";
            cin>>s;
        }
        if(s=="n") break;
        else system("cls");
    }while(true) ;
}
//Tính tiền
void QuanLyBan::Bill(){
     do{
        this->Show();
        string s;
        cout<<"Nhap ban thanh toan:";cin>>s;
        int x=stoi(s);
        if(x<1||x>this->_number){
            system("cls");
            cout<<"Ban khong hop le, vui long nhap lai:"<<endl;
            continue;
        }else{
            (*this)[x].Bill();
        }
        cout<<"Ban co muon thanh toan nua khong[y/n]:";cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Nhap sai, vui long nhap lai:";
            cin>>s;
        }
        if(s=="n") break;
        else system("cls");
    }while(true) ;
}
//Đặt mang về
void QuanLyBan::Ship(QuanLyHangHoa&p){
    do {
        string s;
        system("cls");
        cout<<"DAT HANG MANG VE:"<<endl;
        (*this)[0].Book(p);
        system("cls");
        cout<<"Thong tin don hang:"<<endl;
        (*this)[0].Bill();
        cout<<"Ban co muon dat tiep khong[y/n]:";cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Nhap sai,vui long nhap lai:";
            cin>>s;
        }
        if(s=="n") break;
    }while(true);
}
void QuanLyBan::Cancel(QuanLyHangHoa&p){
    do{
        this->Show();
        string s;
        cout<<"Nhap ban muon huy mon:";cin>>s;
        int x=stoi(s);
        if(x<1||x>this->_number){
            system("cls");
            cout<<"Ban khong hop le, vui long nhap lai:"<<endl;
            continue;
        }else if((*this)[x]._status==true) {}
        else
        {
            system("cls");
            (*this)[x].Show();
            cout<<"Nhap ma mon muon huy:";cin>>s;
            (*this)[x].Cancel(s,p);
            if((*this)[x]._q.getNumber()==0){
                (*this)[x]._status=true;
                (*this)[x]._q.Reset();
            }
        }
        system("cls");
        cout<<"Da huy mon thanh cong"<<endl;
        (*this)[x].Show();
        cout<<"Ban co muon huy mon nua khong[y/n]:";cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Nhap sai, vui long nhap lai:";
            cin>>s;
        }
        if(s=="n") break;
        else system("cls");
    }while(true);
}