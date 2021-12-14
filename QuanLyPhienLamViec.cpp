#include"QuanLyPhienLamViec.h"
    QuanLyPhienLamViec::QuanLyPhienLamViec(){};
    QuanLyPhienLamViec::~QuanLyPhienLamViec(){};

int QuanLyPhienLamViec::DangNhap(){
    string tk,mk,tkmk,str0,str,str1,str2;
    int a=0,b;
    time_t curr_time;                               
    curr_time = time(NULL);                //3 dòng ni dùng tạo time
    char *tm = ctime(&curr_time);
    do{
    cout<< "Tai Khoan: ";
    cin>> tk;
    cout<< "Mat Khau: ";
    cin>> mk;
    ifstream kiemtra("TenNhanVien.txt");
    getline(kiemtra,str0);
    getline(kiemtra,str);
    getline(kiemtra,str1);
    getline(kiemtra,str2);
    if(tk==str1&&mk==str2){
        _name=str;  //dùng để lưu tên nv đăng nhập, khi xuất tiền dô file thì lấy dùng
        ofstream Fileqltime("QuanLytime.txt",ios::app);     //lưu time đang nhap của nv
        Fileqltime<< str << endl << "da dang nhap vao luc :" << tm;
        Fileqltime.close();  
        return 1;
    }
    while (!kiemtra.eof())
    {
        getline(kiemtra,str0);
        getline(kiemtra,str);
        getline(kiemtra,str1);
        getline(kiemtra,str2);
        if(tk==str1&&mk==str2){       //check xem tk và mk có trùng ko
            a++;
            _name=str;  //dùng để lưu tên nv đăng nhập, khi xuất tiền dô file thì lấy dùng
            ofstream Fileqltime("QuanLytime.txt",ios::app);     //lưu time đang nhap của nv
            Fileqltime<< str << endl << "da dang nhap vao luc :" << tm;
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
    FileThu<<"Tong tien NV da thu trong:"<< tm ;                //lưu tiền nv thu trong ngày vào
    FileThu<<a<<endl;
    FileThu.close();
}
void QuanLyPhienLamViec::xuatNV(){
    int a;
    string str0,str,str1,str2;
    ifstream kiemtra("TenNhanVien.txt");   
    while (!kiemtra.eof())
    {
        getline(kiemtra,str0);
        getline(kiemtra,str);
        getline(kiemtra,str1);
        getline(kiemtra,str2);
        cout<< str0 << ". " << str << "\t";                 //xuất id và name nv
    }
    kiemtra.close();
}
void QuanLyPhienLamViec::xuattimedn(int n){
    int id,a=0;
    string name,user,pass,copy;
    ifstream xuat("TenNhanVien.txt");
    do{
    while (!xuat.eof())
    {
        xuat>>id;
        xuat>>name;
        copy=name;                  //kiểm tra id
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
    ifstream xuat("TenNhanVien.txt");
    do{
    while (!xuat.eof())
    {
        xuat>>id;
        xuat>>name;
        copy=name;                      // kiểm tra id
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
            cout << tt << tien << endl;
        } 
    }
    xuat.close();
    open.close();
}

