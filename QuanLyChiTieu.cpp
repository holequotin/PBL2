#include"QuanLyChiTieu.h"
QuanLyChiTieu::QuanLyChiTieu(int TongTienChi, int TongTienThu){
    this->TongTienChi=TongTienChi;
    this->TongTienThu=TongTienThu;
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
    xuattien.close();
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
    //cout<<"Tong tien da thu:"<<endl;
    ifstream xuattien("TienThu.txt");
    if(!xuattien.eof()){
        getline(xuattien,str);
        xuattien>>a;
    }
    return a;
}
int QuanLyChiTieu::XuatTienThuHD(){
    string str;
    int a;
    cout<<"Tong tien da thu theo hoa don:"<<endl;
    ifstream xuattien("TienThuHoaDon.txt");
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
    ofstream FileThu("TienThu.txt",ios::trunc);
    FileThu<<"Tong tien da thu:"<<endl;
    FileThu<<"0";
    FileThu.close();
}
void QuanLyChiTieu::resetTienChi(){
    ofstream FileThu("TienChi.txt",ios::trunc);
    FileThu<<"Tong tien da chi:"<<endl;
    FileThu<<"0";
    FileThu.close();
}
