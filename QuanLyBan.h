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
    //hàm đặt mang về
    void Ship(QuanLyHangHoa &p);
    //hàm thanh toán( có thể một lúc nhiều bàn)
    void Bill();
    //Hủy món
    void Cancel(QuanLyHangHoa &);
    //Đa năng hóa toán tử
    Ban& operator[](const int);
};
