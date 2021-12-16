#include"QuanLyPhienLamViec.h"
    QuanLyPhienLamViec::QuanLyPhienLamViec(){};
    QuanLyPhienLamViec::~QuanLyPhienLamViec(){};

int QuanLyPhienLamViec::DangNhap(){
    system("cls");
    int id;
    string tk,mk;
    string name,user,pass;    
    int a=0,b;
    time_t curr_time;                               
    curr_time = time(NULL);                //3 dòng ni dùng tạo time
    char *tm = ctime(&curr_time);
    do{
    cout<<"\t\t=========================================="<<endl;
    cout<<"\t\t\t\tDANG NHAP"<<endl;
    cout<<"\t\t=========================================="<<endl;
    cout<< "\t\tTai Khoan: ";
    cin>> tk;
    // cout<< "Mat Khau: ";
    // cin>> mk;
    mk=this->NhapPass();
    ifstream kiemtra("NhanVien.txt");
    kiemtra>>id;
    getline(kiemtra,name);
    string nameUD = name.substr(1);
    kiemtra>>user;
    kiemtra>>pass;
    if(tk==user&&mk==pass){
        _name=nameUD;  //dùng để lưu tên nv đăng nhập, khi xuất tiền dô file thì lấy dùng
        ofstream Fileqltime("QuanLytime.txt",ios::app);     //lưu time đang nhap của nv
        Fileqltime<< nameUD << endl << "da dang nhap vao luc :" << tm;
        Fileqltime.close();  
        return 1;
    }
    while (!kiemtra.eof())
    {
    kiemtra>>id;
    getline(kiemtra,name);
    string nameUD = name.substr(1);
    kiemtra>>user;
    kiemtra>>pass;
        if(tk==user&&mk==pass){       //check xem tk và mk có trùng ko
            a++;
            _name=nameUD;  //dùng để lưu tên nv đăng nhập, khi xuất tiền dô file thì lấy dùng
            ofstream Fileqltime("QuanLytime.txt",ios::app);     //lưu time đang nhap của nv
            Fileqltime<< nameUD << endl << "da dang nhap vao luc :" << tm;
            Fileqltime.close();  
            break;
        }
    }
    kiemtra.close();
    if(a==0){
        system("cls");
        cout<< "\t\tBan da nhap sai tai khoan hoac mat khau. Vui long nhap lai"<<endl; 
    }
    }while(a==0);
    return -1;
}    
void QuanLyPhienLamViec::LuuTruTienNV(int TongTien){
    string str;
    int a;
    ifstream xuattien("TongTienTrongNgay.txt");             //lưu đỡ tiền thu từng hoá đơn cộng dồn dô đây
    if(!xuattien.eof()){                                    // vì ghi tiếp data nên phải lưu đỡ
        getline(xuattien,str);
        xuattien>>a;
    }
    xuattien.close();
    a+=TongTien;
    ofstream FileThu("TongTienTrongNgay.txt",ios::trunc);
    FileThu<<"Tong tien da thu:"<<endl;                                     
    FileThu<<a;
    FileThu.close();
}
void QuanLyPhienLamViec::TongTienNV(){
    string str;
    int a;
    time_t curr_time;
    curr_time = time(NULL);                                         
    char *tm = ctime(&curr_time);
    ifstream xuattien("TongTienTrongNgay.txt");         // cuối ngày lấy tiền từ file ra
    if(!xuattien.eof()){
        getline(xuattien,str);
        xuattien>>a;
    }
    xuattien.close();
    ofstream Filereset("TongTienTrongNgay.txt",ios::trunc);
    Filereset<<"Tong tien da thu:"<<endl;                      //reset tiền về 0, để ngày sau cộng dô ko lỗi         
    Filereset<<"0";                             
    Filereset.close();
    ofstream FileThu("TienThuTheoNV.txt",ios::app);
    FileThu<<_name<<endl;   //_name dùng lại
    FileThu<<"Tong tien NV "<< _name << " da thu trong : "<< tm ;                //lưu tiền nv thu trong ngày vào
    FileThu<<a<<endl;
    FileThu.close();
}
void QuanLyPhienLamViec::xuatNV(){
    int id;
    string name,user,pass;
    ifstream kiemtra("NhanVien.txt");
    cout<< "ID" << ". "<< left << setw(20) << "Ten"  << left << setw(20) <<  "Tai khoan" << left << setw(20) << "Mat khau" << endl ;   
    while (!kiemtra.eof())
    {
        kiemtra>>id;
        getline(kiemtra,name);
        string nameUD = name.substr(1);
        kiemtra>>user;
        kiemtra>>pass;
        cout<< id << ".  "<< left << setw(20) << nameUD  << left << setw(20) <<  user << left << setw(20) << pass << endl ;     }
        kiemtra.close();
}
void QuanLyPhienLamViec::xuattimedn(){
    system("cls");
    do{
    int id,a=0,n,p=0;
    string name,user,pass,copy;
        do{
        ifstream xuat("NhanVien.txt");
        this->xuatNV();
        cout<< endl <<"nhap id nhan vien: ";
        cin >> n;
        while (!xuat.eof())
        {
            xuat>>id;
            getline(xuat,name);
            copy = name.substr(1);                //kiểm tra id
            xuat>>user;
            xuat>>pass;
            if(id==n)
            {
                a++;
                break;
            } 
        }
        system("cls");
        if(a==0)
        {   
            //system("cls");
            cout<<"Ban da nhap sai ID vui long nhap lai"<<endl;
        }
        xuat.close();
        }while(a==0);   
        string name1,tt;
        ifstream open("QuanLytime.txt");
        while (!open.eof())
        {
            getline(open,name1);            
            getline(open,tt);
            if(name1==copy)                 //chạy tìm tên nv cần xuất r in ra
            {   
                p++;
                cout<< name1 << endl << tt << endl;
            } 
        }
        open.close();
        if(p==0)cout<<"Nhan vien "<< copy << " chua dang nhap lan nao."<<endl;
    cout<<"Ban co muon xem nua khong[y/n]:";
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
void QuanLyPhienLamViec::xuatTNNV(){
    do{
    system("cls");
    int id,a=0,n;
    string name,user,pass,copy;
    ifstream xuat("NhanVien.txt");
    do{
        ifstream xuat("NhanVien.txt");
        this->xuatNV();
        cout<< endl <<"nhap id nhan vien muon xem thu nhap theo phien lam viec: ";
        cin >> n;
        while (!xuat.eof())
        {
            xuat>>id;
            getline(xuat,name);
            copy = name.substr(1);                //kiểm tra id
            xuat>>user;
            xuat>>pass;
            if(id==n)
            {
                a++;
                break;
            } 
        }
        system("cls");
        if(a==0)
        {   
            //system("cls");
            cout<<"Ban da nhap sai ID vui long nhap lai"<<endl;
        }
        xuat.close();
        }while(a==0); 
    string name1,tt,tien;
    int p=0;
    ifstream open("TienThuTheoNV.txt");
    while (!open.eof())
    {
        getline(open,name1);
        getline(open,tt);                   
        getline(open,tien);
        if(name1==copy)                 //chạy tìm name giống r in ra
        {
            p++;
            cout << tt << "la :" << tien << endl;
        } 
        
    }
    if(p==0)cout<<"Nhan vien " << copy << " chua co thu nhap."<<endl;
    open.close();
        cout<<"Ban co muon xem nua khong[y/n]:";
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
void QuanLyPhienLamViec::xuatHD(){
    do{
    system("cls");
    int id,a=0,n,p=0;
    string name,user,pass,copy;
    ifstream xuat("NhanVien.txt");
    do{
        ifstream xuat("NhanVien.txt");
        this->xuatNV();
        cout<< endl <<"nhap id nhan vien: ";
        cin >> n;
        while (!xuat.eof())
        {
            xuat>>id;
            getline(xuat,name);
            copy = name.substr(1);                //kiểm tra id
            xuat>>user;
            xuat>>pass;
            if(id==n)
            {
                a++;
                break;
            } 
        }
        system("cls");
        if(a==0)
        {   
            //system("cls");
            cout<<"Ban da nhap sai ID vui long nhap lai"<<endl;
        }
        xuat.close();
        }while(a==0);  
    string line1,line2,line3,line4;
    ifstream open("HoaDon.txt");
    while (!open.eof())
    {   
        ofstream open1("fileNhap.txt",ios::app);            //dùng 1 file tạm để lưu 1 hoá đơn của nv vào
        getline(open,line1);
        if(line1=="Thong tin cua hoa don")                  //lặp khi gặp dòng đầu tiên của hoá đơn, sẽ reset file để thêm 1 HĐ mới
        {
            this->reset();
            open1<<line1<<endl;
        }
        else open1<<line1<<endl;                            //ko phải đầu HĐ thì sẽ thêm vào file như bth
        open1.close();
        line2= line1.substr(0,4);
        if(line2=="Nhan")                                   //tại cuối hoá đơn kiểm tra tên có giống với tên nv cần xem k
        {                                                   
            line4 = "Nhan vien thu tien: " + copy;
            if(line1==line4)
            {   
                p++;
                ifstream open1("fileNhap.txt");
                while (!open1.eof())
                {   
                    getline(open1,line3);                   //nếu đúng thì in HĐ đã lưu ở file tạm ra
                    cout<< line3<<endl;
                }
                cout<<"==============================="<<endl<<endl;
                open1.close();
            }
        }    
    }
    open.close();
    if(p==0)cout<<"Nhan vien "<< copy <<" chua thanh toan lan nao."<<endl;
    cout<<"Ban co muon xem nua khong[y/n]:";
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
string QuanLyPhienLamViec::getName(){
    return this->_name;
}
void QuanLyPhienLamViec::reset(){
    FILE *f = fopen("fileNhap.txt", "w");
}
string QuanLyPhienLamViec::NhapPass()
{
    string pass = "";
    char _ipt;
    cout << "\t\tMat khau: ";
    while (true)
    {
        _ipt = getch();
        if (_ipt == 13)
        {
            cout << endl;
            return pass;
        }
        else if (_ipt == 8 && pass.length() == 0)
        {
            continue;
        }
        else if (_ipt == 8 && pass.length() != 0)
        {
            pass.pop_back();
            cout << "\b \b";
            continue;
        }
        cout << "*";
        pass.push_back(_ipt);
    }
}