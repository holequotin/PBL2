#include"QuanLyChiTieu.h"
QuanLyChiTieu::QuanLyChiTieu(int a, int b){
    this->TongTienThu=a;
    this->TongTienChi=b;
}
QuanLyChiTieu::~QuanLyChiTieu(){}
void QuanLyChiTieu::ThuTien(int TongTien){             //hàm dùng để lưu tổng tiền và tiền theo hoá đơn
    TongTienThu += TongTien;
    string str;
    int a;
    ifstream xuattien("TienThu.txt");
    if(!xuattien.eof()){
        getline(xuattien,str);                         //đọc file đã cho sẵng, để xem tổng tiền đã thu được bao nhiêu
        xuattien>>a;
    }       
    a+=TongTien;                                        //sau đó sẽ cộng thêm tiền từ hoá đơn mới thanh toán vào
    ofstream FileThu("TienThu.txt",ios::trunc);
    FileThu<<"Tong tien da thu:"<<endl;
    FileThu<<a;                                         //và ghi vào file
    FileThu.close();
    time_t curr_time;
    curr_time = time(NULL);
    char *tm = ctime(&curr_time);                       // ghi thời gian
    ofstream FileThuHoaDon("TienThuHoaDon.txt",ios::app);
    FileThuHoaDon<<"Tong tien da thu cua hoa don vao:"<< tm ;   //tổng theo hoá đơn, sẽ ghi tiếp ko ghi đè
    FileThuHoaDon<<TongTien << endl;
    FileThuHoaDon.close();
}
int QuanLyChiTieu::XuatTienThu(){                   //in ra tổng tiền đã thu 
    string str;
    int a;
    cout<<"Tong tien da thu:"<<endl;
    ifstream xuattien("TienThu.txt");
    if(!xuattien.eof()){
        getline(xuattien,str);                      //đọc file và xuất
        xuattien>>a;
    }
    cout<< a;
    return 0;
}
int QuanLyChiTieu::XuatTienThuHD(){                 //xuất tiền thu theo hoá đơn, chỉ có theo ngày ko rõ ràng

    cout<<"Tong tien da thu theo hoa don:"<<endl;
    ifstream xuattien("TienThuHoaDon.txt");
    string HD ;
    while (!xuattien.eof())
    {                                                //đọc file và xuất tiền ra
        getline(xuattien,HD);
        cout<<HD<< endl;
        HD = "";
    }
    return 0;
}
void QuanLyChiTieu::ChiTien(int tientieu){          //lưu tổng tiền chi vào file
    TongTienChi += tientieu;
    ofstream FileChi("TienChi.txt",ios::trunc);
    FileChi<<"Tong tien da chi:"<<endl;
    FileChi<<TongTienChi;
    FileChi.close();
}
int QuanLyChiTieu::XuatTienChi(){                   //in ra tổng tiền đã chi,khi nhập hàng hoá vào kho
    string str;
    int a;
    ifstream XuatTienChi("TienChi.txt");
    if(!XuatTienChi.eof()){
        getline(XuatTienChi,str);
        XuatTienChi>>a;
    }
    return a;
}
void QuanLyChiTieu::resetTienThu(){                 //hàm dùng để reset file
    FILE *f = fopen("TienThu.txt", "w");
}
void QuanLyChiTieu::resetTienThuHD(){               //hàm dùng để reset file
    FILE *f = fopen("TienThuHoaDon.txt", "w");
}
