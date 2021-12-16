#include"QuanLyPhienLamViec.h"
#include"QuanLyBan.h"
#include"QLNV.h"

#include<iostream>
using namespace std;
// void ManHinhChinh(bool dangnhap){
//     if(dangnhap==true) QuanLy();
//     else NhanVien();
//}
//chi ra lam
// void QuanLy(){
//     QuanLyPhienLamViec plv;
//     QuanLyHangHoa hh;
//     QuanLyNhanVien nv;
//     QuanLyBan b;
//     cout<<"Menu chuc nang"<<endl;
//     cin>>aashfk;
//     switch...case(x)
//         1:QuanLyThuChi();
//         2:QuanLyHangHoa();
//         3:QuanLyNhanVien();
//         4:BuonBan();
// }
void QuanLyNhanVien(QLNV &nv,QuanLyPhienLamViec &plv){
    int a,n,x=0;
    do{
    system("cls");
    set_color(14);
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t\t\tQUAN LY NHAN VIEN"<<endl;
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t1/Them nhan vien"
        <<"\t\t2/Xoa nhan vien"<<endl
        <<"\t\t3/Sua nhan vien"<<endl
        <<"\t\t4/Thoi gian nhan vien dang nhap"<<endl
        <<"\t\t5/Hoa don nhan vien da thanh toan"<<endl
        <<"\t\t6/Thoat"<<endl;
    cout<<"Nhap chuc nang:";
    cin>>n;
    while(n<1||n>6){
        cout<<"Chuc nang khong ton tai, vui long nhap lai: ";
        cin>>n;
    }
    switch (n)
    {
    case 1:
        nv.Addelement();
        nv.Save();
        break;
    case 2:
        nv.Remove();
        nv.Save();
        break;
    case 3:
        system("cls");
        nv.Update();
        nv.Save();
        break;
    case 4:
        plv.xuattimedn();
        break;
    case 5:
        plv.xuatHD();
        break;
    case 6:
        x=1;
        break;
    }
    }while(x!=1);
}
void QLTC(QLNV &nv, QuanLyChiTieu &ct, QuanLyPhienLamViec &plv){
    int n,x=0;
    do{
    // system("cls");
    // cout<<"Tong tien da thu: "<< ct.XuatTienThu() <<endl;
    // cout<<"Tong tien da chi: " << ct.XuatTienChi() <<endl;
    // cout<<"Menu chuc nang"<<endl;
    // cout<<"1/Thu nhap theo phien lam viec"<<endl
    //     <<"2/Lam moi tien thu"<<endl
    //     <<"3/Lam moi tien chi"<<endl
    //     <<"4/Thoat"<<endl
    //     <<"Chon chuc nang:";
    // cin>>n;
    system("cls");
    set_color(14);
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t\t\tQUAN LY HANG HOA"<<endl;
    cout<<"\t\t============================================="<<endl;
     cout<<"Tong tien da thu: "<< ct.XuatTienThu() <<endl;
     cout<<"Tong tien da chi: " << ct.XuatTienChi() <<endl;
    cout<<"\t\t1/Tien thu theo phien lam viec"<<endl
        <<"\t\t2/Lam moi tien thu"<<endl
        <<"\t\t3/Lam moi tien chi"<<endl
        <<"\t\t4/Thoat"<<endl;
    cout<<"Nhap chuc nang:";
    cin>>n;
    while(n<1||n>4){
        cout<<"Chuc nang khong ton tai, vui long nhap lai: ";
        cin>>n;
    }
    switch (n)
    {
    case 1:
        plv.xuatTNNV();
        break;
    case 2:
        ct.resetTienThu();
        break;
    case 3:
        ct.resetTienChi();
        break;
    case 4:
        x=1;
        break;
    }
    }while(x!=1);
}
//Hàm quản lí hàng hóa
void QLHH(QuanLyPhienLamViec &plv,QuanLyHangHoa&hh,QLNV &nv,QuanLyChiTieu &ct){
    int n;
    while(true)
    {
    system("cls");
    set_color(14);
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t\t\tQUAN LY HANG HOA"<<endl;
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t1/Nhap hang hoa"
        <<"\t\t\t2/Lich su nhap hang hoa"<<endl
        <<"\t\t3/Them hang hoa moi"
        <<"\t\t4/Xoa hang hoa"<<endl
        <<"\t\t5/Sua hang hoa"
        <<"\t\t\t6/Thoat"<<endl;
    cout<<"Nhap chuc nang:";
    cin>>n;
    while(n<1||n>6){
        cout<<"Chuc nang khong ton tai, vui long nhap lai: ";
        cin>>n;
    }
    switch (n)
    {
    case 1:
    hh.EnterStock(ct);
    hh.Save();
    break;
    case 2:
    {
    cout<<"Lich su nhap hang hoa:"<<endl;
    string line;
    ifstream input("QuanLyNhap.txt");
    set_color(15);
	while(!input.eof())	//khi chưa tới cuối file thì tiếp tục đọc
	{
		getline(input,line);
		cout<<line<<endl;
	}
    input.close();
    getch();
    }
    break;
    case 3:
    hh.AddElement();
    hh.Save();
    break;
    case 4:
    hh.Remove();
    hh.Save();
    break;
    case 5:
    system("cls");
    hh.Update();
    hh.Save();
    break;
    case 6:
    return;
    break;        
    }
    }
}
//Hàm quản lí bán hàng
void QLBH(QuanLyPhienLamViec &plv,QuanLyHangHoa&hh,QuanLyBan b,QuanLyChiTieu &ct){
    int n;
    while(true)
    {
    system("cls");
    //hh.Show();
    set_color(14);
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t\t\tCHUC NANG BAN HANG"<<endl;
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t1/Dat mon"
        <<"\t\t\t2/Dat mang ve"<<endl
        <<"\t\t3/Huy mon"
        <<"\t\t\t4/Thanh toan"<<endl
        <<"\t\t5/Thoat"<<endl;
    cout<<"Nhap chuc nang:";
    cin>>n;
    while(n<1||n>5){
        cout<<"Chuc nang khong ton tai, vui long nhap lai: ";
        cin>>n;
    }
    switch (n)
    {
    case 1:
    system("cls");
    b.Book(hh);
    hh.Save();
    break;
    case 2:
    b.Ship(hh,ct,plv);
    hh.Save();
    break;
    case 3:
    b.Cancel(hh);
    hh.Save();
    break;
    case 4:
    b.Bill(ct,plv);
    hh.Save();
    break;
    case 5:
    return;
    break;       
    }
    }
}
//thắc mắc chỗ biến quản lí phiên làm việc
void QuanLy(QuanLyPhienLamViec &plv){
    system("cls");
    QuanLyHangHoa hh;
    QLNV nv;
    QuanLyChiTieu ct;
    QuanLyBan b;
    int n;
    //int x=0;
    while(true){
    system("cls");
    set_color(14);
    cout<<"\t\t========================================================="<<endl;
    cout<<"\t\t\t\t   CAC CHUC NANG QUAN LI"<<endl;
    cout<<"\t\t========================================================="<<endl;
    cout<<"\t\t1/Quan li thu chi"
        <<"\t\t\t2/Quan li hang hoa"<<endl
        <<"\t\t3/Quan li nhan vien"
        <<"\t\t\t4/Ban hang"<<endl
        <<"\t\t5/Dang xuat"<<endl;
    cout<<"Chon chuc nang:";
    cin>>n;
    while(n<1||n>5){
        cout<<"Chuc nang khong ton tai, vui long nhap lai: ";
        cin>>n;
    }
    switch (n)

    {
    case 1:
    system("cls");
    QLTC(nv,ct,plv);
    break;
    case 2:
    system("cls");
    QLHH(plv,hh,nv,ct);
    break;
    case 3:
    system("cls");
    QuanLyNhanVien(nv,plv);
    break;
    case 4:
    system("cls");
    QLBH(plv,hh,b,ct);
    break;
    case 5:   
    //hh.Save();
    //x=1;
    plv.TongTienNV();
    return;
    }
    }
}    
void NhanVien(QuanLyPhienLamViec&plv){
    QuanLyHangHoa hh;
    QLNV nv;
    QuanLyChiTieu ct;
    QuanLyBan b;
    int n;
    while(true)
    {
    system("cls");
    //hh.Show();
    set_color(14);
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t\t\tCHUC NANG BAN HANG"<<endl;
    cout<<"\t\t============================================="<<endl;
    cout<<"\t\t1/Dat mon"
        <<"\t\t\t2/Dat mang ve"<<endl
        <<"\t\t3/Huy mon"
        <<"\t\t\t4/Thanh toan"<<endl
        <<"\t\t5/Dang xuat"<<endl;
    cout<<"Nhap chuc nang:";
    cin>>n;
    while(n<1||n>5){
        cout<<"Chuc nang khong ton tai, vui long nhap lai: ";
        cin>>n;
    }
    switch (n)
    {
    case 1:
    system("cls");
    b.Book(hh);
    hh.Save();
    break;
    case 2:
    b.Ship(hh,ct,plv);
    hh.Save();
    break;
    case 3:
    b.Cancel(hh);
    hh.Save();
    break;
    case 4:
    b.Bill(ct,plv);
    hh.Save();
    break;
    case 5:
    plv.TongTienNV();
    return;
    break;       
    }
    }
}
void ManHinhChinh(){
    while(true){
    system("cls");
    QuanLyPhienLamViec  plv;
    int x=plv.DangNhap();
    if(x==1){
        QuanLy(plv);
    }else
        NhanVien(plv);
    }
}
int main(){
    ManHinhChinh();
   return 0;
}