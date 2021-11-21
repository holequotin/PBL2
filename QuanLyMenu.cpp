#include"QuanLyMenu.h"

//khi gọi constructor của lớp con thì auto gọi của lớp cha trươc
QuanLyMenu::QuanLyMenu(int n,HangHoa *p){
    this->_number=n;
    this->_p=p;
}
QuanLyMenu::~QuanLyMenu(){
}
// void QuanLyMenu::Show(){

// }