#include"QuanLyPhienLamViec.h"
    QuanLyPhienLamViec::QuanLyPhienLamViec(){};
    QuanLyPhienLamViec::~QuanLyPhienLamViec(){};

int QuanLyPhienLamViec::DangNhap(){
    int id;
    string tk,mk;
    string name,user,pass;    
    int a=0,b;
    time_t curr_time;                               
    curr_time = time(NULL);                //3 dòng ni dùng tạo time
    char *tm = ctime(&curr_time);
    do{
    cout<< "Tai Khoan: ";
    cin>> tk;
    cout<< "Mat Khau: ";
    cin>> mk;
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
    if(a==0)cout<< "Ban da nhap sai tai khoan hoac mat khau. Vui long nhap lai"; 
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
    while (!kiemtra.eof())
    {
        kiemtra>>id;
        getline(kiemtra,name);
        string nameUD = name.substr(1);
        kiemtra>>user;
        kiemtra>>pass;
        cout<< id << ". " << nameUD << "\t";                 //xuất id và name nv
    }
    kiemtra.close();
}
void QuanLyPhienLamViec::xuattimedn(int n){
    int id,a=0;
    string name,user,pass,copy;
    ifstream xuat("NhanVien.txt");
    do{
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
    if(a==0)cout<<"Ban da nhap sai ID vui long nhap lai";
    }while(a==0);
    string name1,tt;
    ifstream open("QuanLytime.txt");
    while (!open.eof())
    {
        getline(open,name1);            
        getline(open,tt);
        if(name1==copy)                 //chạy tìm tên nv cần xuất r in ra
        {
            cout<< name1 << endl << tt << endl;
        } 
    }
    xuat.close();
    open.close();
}
void QuanLyPhienLamViec::xuatTNNV(int n){
    int id,a=0;
    string name,user,pass,copy;
    ifstream xuat("NhanVien.txt");
    do{
    while (!xuat.eof())
    {
        xuat>>id;
        getline(xuat,name);
        copy = name.substr(1);                     // kiểm tra id
        xuat>>user;
        xuat>>pass;
        if(id==n)
        {
            a++;
            break;
        } 
    }
    if(a==0)cout<<"Ban da nhap sai ID vui long nhap lai";
    }while(a==0);
    string name1,tt,tien;
    ifstream open("TienThuTheoNV.txt");
    while (!open.eof())
    {
        getline(open,name1);
        getline(open,tt);                   
        getline(open,tien);
        if(name1==copy)                 //chạy tìm name giống r in ra
        {
            cout << tt << "la :" << tien << endl;
        } 
    }
    xuat.close();
    open.close();
}
void QuanLyPhienLamViec::xuatHD(int n){
    int id,a=0;
    string name,user,pass,copy;
    ifstream xuat("NhanVien.txt");
    do{
    while (!xuat.eof())
    {
        xuat>>id;
        getline(xuat,name);
        copy = name.substr(1);                     // kiểm tra id
        xuat>>user;
        xuat>>pass;
        if(id==n)
        {
            a++;
            break;
        } 
    }
    if(a==0)cout<<"Ban da nhap sai ID vui long nhap lai";
    }while(a==0);
    string line1,line2,line3,line4;
    ifstream open("HoaDon.txt");
    //fstream open1("fileNhap.txt",ios::app);
    while (!open.eof())
    {   
        ofstream open1("fileNhap.txt",ios::app);
        getline(open,line1);
        if(line1=="Thong tin cua hoa don")
        {
            this->reset();
            open1<<line1<<endl;
        }
        else open1<<line1<<endl;
        open1.close();
        line2= line1.substr(0,4);
        if(line2=="Nhan")
        {      
            line4 = "Nhan vien thu tien: " + copy;
            if(line1==line4)
            {
                ifstream open1("fileNhap.txt");
                while (!open1.eof())
                {   
                    getline(open1,line3);
                    cout<< line3<<endl;
                }
                open1.close();
            }
        }    
    }
    xuat.close();
    open.close();
    //open1.close();
}
string QuanLyPhienLamViec::getName(){
    return this->_name;
}
void QuanLyPhienLamViec::reset(){
    FILE *f = fopen("fileNhap.txt", "w");
}
