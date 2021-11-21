#include"QuanLyHangHoa.h"

class QuanLyMenu:public QuanLyHangHoa
{
    public:
    //Đơn giản là tạo một cái danh sách rỗng
    QuanLyMenu(int=0,HangHoa*p=nullptr);
    //thằng Destructor này sẽ lưu lại thông tin các đơn hàng vào một file mới
    ~QuanLyMenu();
   // void Show();
};