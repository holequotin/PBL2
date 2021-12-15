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
    int a,n;
    do{
    cout<<"Menu chuc nang"<<endl;
    cout<<"1/Them nhan vien"<<endl
        <<"2/Xoa nhan vien"<<endl
        <<"3/Sua nhan vien"<<endl
        <<"4/Thoi gian nhan vien dang nhap"<<endl
        <<"5/Hoa don nhan vien da thanh toan"<<endl
        <<"Chon chuc nang:";
    cin>>n;
    while(n<1||n>5){
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
        nv.Update();
        nv.Save();
        break;
    case 4:
        plv.xuatNV();
        cout<< endl <<"nhap id nhan vien: ";
        cin>>a;
        plv.xuattimedn( a);
        break;
    case 5:
        plv.xuatNV();
        cout<< endl <<"nhap id nhan vien: ";
        cin>>a;
        plv.xuatHD( a);
        break;
    }
    cout<<"Ban co muon them nua khong[y/n]:";
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
void QLTC(QLNV &nv, QuanLyChiTieu &ct, QuanLyPhienLamViec &plv){
    int n;
    do{
    cout<<"Tong tien da thu: "<< ct.XuatTienThu() <<endl;
    cout<<"Tong tien da chi: " << ct.XuatTienChi() <<endl;
    plv.xuatNV();
    cout << endl << "Chon ma so nhan vien muon xem tien da thu: ";
    cin >> n;
    while(n<1||n>nv.getNumber()){
         cout<< endl <<"Chon sai ma so nhan vien, vui long nhap lai: ";
         cin>>n;
    }
    plv.xuatTNNV(n);
    cout<<"Ban co muon them nua khong[y/n]:";
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
//Hàm quản lí hàng hóa
void QLHH(QuanLyPhienLamViec &plv,QuanLyHangHoa&hh,QLNV &nv,QuanLyChiTieu &ct){
    int n;
    while(true)
    {
    system("cls");
    hh.Show();
    cout<<"Menu chuc nang:"<<endl;
    cout<<"1/Nhap hang hoa"<<endl
        <<"2/Lich su nhap hang hoa"<<endl
        <<"3/Them hang hoa moi"<<endl
        <<"4/Xoa hang hoa"<<endl
        <<"5/Sua hang hoa"<<endl
        <<"6/Thoat"<<endl;
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
    hh.Show();
    cout<<"Menu chuc nang:"<<endl;
    cout<<"1/Dat mon"<<endl
        <<"2/Dat mang ve"<<endl
        <<"3/Huy mon"<<endl
        <<"4/Thanh toan"<<endl
        <<"5/Thoat"<<endl;
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
void QuanLy(){
    while(true){
    QuanLyPhienLamViec plv;
    QuanLyHangHoa hh;
    QLNV nv;
    QuanLyChiTieu ct;
    QuanLyBan b;
    int n;
    plv.DangNhap();
    int x=0;
    while(x!=1){
    set_color(14);
    cout<<"Menu chuc nang"<<endl;
    cout<<"1/Quan li thu chi"<<endl
        <<"2/Quan li hang hoa"<<endl
        <<"3/Quan li nhan vien"<<endl
        <<"4/Ban hang"<<endl
        <<"5/Dang xuat"<<endl
        <<"Chon chuc nang:";
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
    x=1;
    plv.TongTienNV();
    break;
    }
    }
    }
}    

int main(){
    // QLNV nv;
    // QuanLyBan b;
    // QuanLyPhienLamViec plv;
    // QuanLyChiTieu ct;
    // QuanLyHangHoa hh;
    QuanLy();
   return 0;
}