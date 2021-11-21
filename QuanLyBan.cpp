#include"QuanLyBan.h"
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
Ban& QuanLyBan::operator[](const int x){
    return (*(_p+x));
}
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
}//hàm show tạm ổn
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
        cout<<"Ban co muon dat mon nua khong[y/n]:";cin>>s;
        while (s!="y"&&s!="n")
        {
            cout<<"Nhap sai, vui long nhap lai:";
            cin>>s;
        }
        if(s=="n") break;
        else system("cls");
    }while(true) ;
}
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