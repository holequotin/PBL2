#include"Ban.h"
class QuanLyBan
{
private:
    int  _number;
    //danh sách liên kết các bàn
    Ban *_p;
public:
    //Constructor và destructor tạm thời để trống
    QuanLyBan(int =10);
    ~QuanLyBan();
    //xem tình trạng dãy bàn
    void Show();
    //hàm đặt bàn(có thể một lúc nhiều bàn)
    void Book(QuanLyHangHoa&);
    //hàm đặt thêm món(có thể một lúc nhiều bàn)=>cũng tương tự như cái hàm book=> dùng chung cho khỏe
    void Order();
    //hàm đặt mang về
    void Ship();
    //hàm thanh toán( có thể một lúc nhiều bàn)
    void Bill();
    Ban& operator[](const int);
};
