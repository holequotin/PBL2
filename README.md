# PBL2
Đề tài quản lí bán hàng
Mô tả chương trình:
Khi khởi động chương trình sẽ yêu cầu nhập tài khoản và mk để có thể vào quản lí
===========================================================================
Màn hình chính:
-Màn hình đầu tiên là yêu cầu đăng nhập
<!-- -Đơn hàng đã bán
-Doanh thu
-Tình trạng bàn đang sử dụng
-Mặt hàng bán chạy -->
# **# Chức năng chính là quản lí hoạt động bán hàng**
Sẽ gồm các chức năng quản lí chính:
## -Quản lí hàng hóa
	+Loại hàng nào còn trong kho và còn bao nhiêu.Thêm xóa và sửa thông tin hàng hóa
	+Nhập hàng và trả hàng(vào kho):Nhập kho và xuất kho, lưu lại thông tin nhập kho và xuất kho=>Tạo một file mới có tên là nhâp kho và xuất kho
	+Lịch sử nhập xuất hàng hóa
	Mô tả: Khi chọn chức năng nhập hoặc xuất kho thì chương trình sẽ yêu cầu nhập mã sản phẩm(có thể cùng lúc nhiều sp) rồi nhập hoặc xuất một lần
	=>Tương tự như chức năng đặt bàn
*************
## -Quản lí bàn:
	+Xem thông tin hiện tại của các bàn
	+Chức năng bán hàng:Đặt món, thêm món, bán mang về, hủy món và thanh toán
## -Quản lí thu chi, hóa đơn:
	+tiền đầu ngày, tiền cuối ngày, lãi tương ứng với ngày bán=>Xem chi tiết:tiền thu và tiền chi, xem chi tiết các khoản thu chi
	+Lưu thông tin của các ngày=>Sử dụng danh sách liên kết sau đó in chồng lên file txt
## Quản lí nhân viên
	+Thêm xóa sửa nhân viên
	+Xem các thông số của nhân viên:
-Chức năng quan trọng nhất là chức năng bán hàng(tương tự như PBL1):Hiện ra tình trạng bàn trước rồi tới hiện hóa đơn=> Chọn món
	+Cũng sẽ gồm các chức năng:Đặt món ,thêm món, Bán mang về và thanh toán
=============================================================================
Tạo một cái class hóa đơn:
Thông tin của một hóa đơn bao gồm:
-Mã đơn hàng
-Danh sách các hàng hóa kèm số lượng(có thể dùng mảng đặc hoặc dslk, vector)
-Ngày và giờ xuất hóa đơn
-Tình trạng hóa đơn(Đã thanh toán, chưa thanh toán, đang vận chuyển)
-Tổng tiền
Các chức năng (function) của một đơn hàng bao gồm:chưa biết
===========================================================================
Tạo một class hàng hóa
Lớp hàng hóa có các thuộc tính sau
-Mã hàng hóa
-Tên hàng hóa
-Đơn gía
-Số lượng=> Hàng còn trong kho
********
Các chức chức năng của class hàng hóa
-Các constructor
-Xem hàng hóa: Chức năng xem thông tin đầy đủ của hàng hóa
============================================================================
Tạo một class quản lí hàng hóa
Mô tả: Khi bắt đầu chương trình thì chương trình sẽ đọc hàng hóa từ file txt rồi đẩy vào một dslk hàng hóa
Các thuộc tính:
Số lượng hàng hóa
Một danh sách các hàng hóa còn trong kho
Các chức năng:
Constructor:Khi gọi constructor thì sẽ đọc từ file txt rồi đẩy các hàng hóa vào dslk
+Chức năng đọc file được gắn vào đây luôn
Destructor:Xóa cái danh sách
	Mỗi khi một đối tượng của thằng này bị xóa thì sẽ ghi đè lên file hàng hóa rồi xóa
Xem danh sách hàng hóa
Nhập hàng và trả hàng
Thêm và xóa hàng hóa
Xem hàng hóa
=>Sau khi bán hàng hóa thì số lượng hàng hóa trong kho cũng sẽ giảm
=>Dùng biến static để quản lí số lượng của class này
============================================================================
Tạo một cái class bàn
Thông tin của một bàn gồm
-Mã bàn
-Trạng thái
-Danh sách các món đang gọi=>Đưa vào hàm Show()
-Tổng tiền
-Thanh toán:Thay đổi trạng thái bàn và xuất hóa đơn
Các chức năng (function) của một bàn:Tương tự như cái chức năng của PBL cũ
-Đặt bàn:thay đổi trạng thái rồi tiến hành chọn món
-Gọi thêm món:thêm 1 món
-Huy mon an
-Chức năng thanh toán: in hóa đơn ra Hoadon.txt rồi trả bàn
============================================================================
Tạo một class quản lí bàn=> Chỉ có một dãy bàn duy nhất từ đầu đến cuối=> Chỉ có một đối tượng của lớp này
Các thuộc tính:
Số lượng bàn trong quán
Một danh sách các đối tượng bàn: danh sách đặc các bàn
Vì các bàn cùng chung 1 menu nên cho sử dụng chung một danh sách đặc
Các chức năng:
Đặt thêm món=>Dựa vào lớp con(thêm nhiều món)
Đặt bàn:Thay đổi trạng thái của bàn(thêm nhiều bàn)
Thanh toán:In ra hóa đơn rồi xóa bàn khỏi dslk(thanh toán nhiều bàn)
Chuyển bàn:Chuyển từ bàn này sang bàn kia(chức năng mới)
Đặt bàn mang về
Xem trạng thái của tất cả các bàn(hàm Show)
=> Nói chung là tương tự cái PBL2
==============================================================================
void thongtin(FILE *fout,mon *mon1){
	fscanf(fout,"%d",&mon1->code);
	fgets(mon1->name,sizeof(mon1->name),fout);fflush(stdin);
	fscanf(fout,"%d",&mon1->cost);
}

=>Đẩy tất cả các file text dô một folder cho dễ quản lí
Trước mỗi chức năng sẽ có lệnh xóa màn hình


Ta sẽ sử dụng các tính năng là phiên đăng nhập=> Tình trạng bàn sẽ được lưu cho mỗi lần thoát phiên đăng nhập
Làm sao để tạo class menu=>Là con của thằng hàng hóa, có thêm thuộc tính là số lượng(số lượng cho mỗi bàn)\

Thường thì số bàn trong quán là cố định nên chỉ cần:Tạo một class bàn rồi cho vào danh sách đặc
Thông tin sẽ được ghi đè liên tục=> Khi out ra màn hình chính thì sẽ cập nhật lại=>Có cũng được mà ko có cũng được

Giả sử số lượng hàng hóa khách order lớn hơn số lượng còn trong kho
