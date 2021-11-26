#include"QuanLyChiTieu.h"
QuanLyChiTieu::QuanLyChiTieu(int a, int b){
    this->TongTienThu=a;
    this->TongTienChi=b;
}
QuanLyChiTieu::~QuanLyChiTieu(){}
void QuanLyChiTieu::ThuTien(int TongTien){
    TongTienThu += TongTien;
    string str;
    int a;
    ifstream xuattien("TienThu.txt");
    if(!xuattien.eof()){
        getline(xuattien,str);
        xuattien>>a;
    }
    a+=TongTien;
    ofstream FileThu("TienThu.txt",ios::trunc);
    FileThu<<"Tong tien da thu:"<<endl;
    FileThu<<a;
    FileThu.close();
    time_t curr_time;
    curr_time = time(NULL);
    char *tm = ctime(&curr_time);
    ofstream FileThuHoaDon("TienThuHoaDon.txt",ios::app);
    FileThuHoaDon<<"Tong tien da thu cua hoa don vao:"<< tm ;
    FileThuHoaDon<<TongTien << endl;
    FileThuHoaDon.close();
}
int QuanLyChiTieu::XuatTienThu(){
    string str;
    int a;
    cout<<"Tong tien da thu:"<<endl;
    ifstream xuattien("TienThu.txt");
    if(!xuattien.eof()){
        getline(xuattien,str);
        xuattien>>a;
    }
    cout<< a;
    return 0;
}
int QuanLyChiTieu::XuatTienThuHD(){
    string str;
    int a;
    cout<<"Tong tien da thu theo hoa don:"<<endl;
    ifstream xuattien("TienThuHoaDon.txt");
    if(!xuattien.eof()){
        getline(xuattien,str);
        xuattien>>a;
    }
    string HD ;
    while (!xuattien.eof())
    {   
        getline(xuattien,HD);
        cout<<HD<< endl;
        HD = "";
    }
    return 0;
}
void QuanLyChiTieu::ChiTien(int tientieu){
    TongTienChi += tientieu;
    ofstream FileChi("TienChi.txt",ios::trunc);
    FileChi<<"Tong tien da chi:"<<endl;
    FileChi<<TongTienChi;
    FileChi.close();
}
int QuanLyChiTieu::XuatTienChi(){
    string str;
    int a;
    ifstream XuatTienChi("TienChi.txt");
    if(!XuatTienChi.eof()){
        getline(XuatTienChi,str);
        XuatTienChi>>a;
    }
    return a;
}
void QuanLyChiTieu::resetTienThu(){
    FILE *f = fopen("TienThu.txt", "w");
}
void QuanLyChiTieu::resetTienThuHD(){
    FILE *f = fopen("TienThuHoaDon.txt", "w");
}
