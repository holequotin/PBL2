#include"Ban.h"

//Constructor
Ban::Ban(string id,QuanLyMenu q,bool status,int pay):_id(id),_q(q),_status(status),_pay(pay)
{}
//hàm này chỉ lấy số tiền chứ chưa chuyển trạng thái
int Ban::Pay(){
    int sum=0;
    for(int i=0;i<_q.getNumber();i++){
        sum=sum+_q[i].getNumber()*_q[i].getPrice();
    }
    return sum;
}
//Đặt bàn (chức năng)
void Ban::Book(QuanLyHangHoa &p){
    //_status=false;
    do{
        set_color(7);
        system("cls");
        p.Show();
        string s;
        set_color(14);
        int n,i;
        cout<<"Nhap ma hang hoa:";cin>>s;
        cout<<"Nhap so luong:";cin>>n;
        //check ở danh sách đã gọi trước
        int x=_q.getNumber(s);
        if(x==-1){//trường hợp chưa có trong danh sách
            if(p.getNumber(s)==-1) {
                set_color(4);
                cout<<"Ma hang hoa khong ton tai"<<endl;
                // if(this->_q.getNumber()==0){
                // _q.Reset();
                // this->_status=true;
                // this->_pay=0;
                // }
                set_color(7);
            }
            else{
                HangHoa h=p.Element(s);
                h.setNumber(n);
                p.Order(s,n);
                _q.Add(h);
                _status=false;
            }
        }else{//trường hợp đã có trong danh sách
            set_color(4);
            if(n>p.getNumber(s)) cout<<"Hang trong kho khong du"<<endl;
            else{
                p.Order(s,n);
                _q.setNumber(s,x+n);
            }
        }
        set_color(14);
        cout<<"Ban co muon goi mon nua khong[y/n]:";cin>>s;
        while (s!="y"&&s!="n")
        {   set_color(4);
            cout<<"Nhap sai, vui long nhap lai:";cin>>s;
        }
        if(s=="n") break;else continue;
    }while(true);
}
//Xem thông tin của bàn(chức năng)
void Ban::Show(){
    if(this->_status==true){
        set_color(2);
        cout<<"Ban nay dang trong"<<endl;
    }else{
        set_color(14);
        cout<<"Ma ban:"<<this->_id<<endl;
        cout<<"Tinh trang ban: Chua thanh toan"<<endl;
        cout<<"Cac mon da dat"<<endl;
        set_color(7);
        _q.Show();
        set_color(2);
        cout<<"Tong tien :"<<this->Pay()<<endl;
        set_color(7);
    }
}
//Hàm thanh toán (in ra hóa đơn và trả lại trạng thái của bàn)
void Ban::Cancel(string s,QuanLyHangHoa &p){
    int x=_q.getNumber(s);//lấy số lượng món 
    _q.Delete(s);//xóa khỏi danh sách đã gọi
    p.Return(s,x);//trả về thực đơn
}
//thanh toán và in hóa đơn ra file
void Ban::Bill(QuanLyChiTieu&a,QuanLyPhienLamViec&b){
    if(this->_status==true){
        cout<<"Ban nay dang trong"<<endl;
    }
    else{
    ofstream myfile("Hoadon.txt",ios::app);
    set_color(2);
    cout<<endl<<"Thong tin cua hoa don"<<endl;
    myfile<<"Thong tin cua hoa don"<<endl;
    cout<<"Ma ban: "<<this->_id<<endl;
    myfile<<"Ma ban: "<<this->_id<<endl;
    set_color(7);
    _q.Show();
    myfile<<"MAHH"<<setw(25)<<"TEN HANG HOA"<<"\t\t"<<"SO LUONG"<<"\t"<<"DON GIA"<<endl;
    for(int i=0;i<_q.getNumber();i++){
        myfile<<_q[i].getID()<<setw(25)<<_q[i].getName()<<"\t\t"<<_q[i].getNumber()
            <<"\t\t"<<_q[i].getPrice()<<endl;
    }
    set_color(2);
    cout<<"Tonng tien: "<<this->Pay()<<endl;
    myfile<<"Tong tien: "<<this->Pay()<<endl;
    int add = this->Pay();
            a.ThuTien(add);
            b.LuuTruTienNV(add);
    cout<<"================================"<<endl;
    myfile<<"==============================="<<endl;
    myfile.close();
    //đưa về trạng thái trống
    _q.Reset();
    this->_status=true;
    this->_pay=0;
    }
}