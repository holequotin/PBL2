#include"QuanLyBan.h"

int main(){
    int n;
    QuanLyHangHoa p;
    cout<<"Nhap so ban:";cin>>n;
    QuanLyBan q(n);
    q.Book(p);
    q.Show();
    q.Bill();
    q.Show();
    p.Save();
    return 0;
}