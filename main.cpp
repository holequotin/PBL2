#include"QuanLyBan.h"

int main(){
    QuanLyHangHoa h;
    QuanLyBan b(10);
    b.Book(h);
    b.Cancel(h);
    b.Book(h);
    b.Show();
    b.Bill();
    h.Save();
    return 0;
}