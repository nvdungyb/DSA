// Biểu diễn đồ thị trên máy tính

1a. Bằng ma trận kề 
	Nếu A(i,j) = 1 là một cạnh của đồ thị, hoặc 0 nếu không phải.
	Đối với đồ thị vô hướng: là ma trận đối xứng, tổng các phần tử trong ma trận bằng 2 lần số cạnh, tổng các phần tử trên hàng hoặc cột thứ i là bậng của đỉnh i.
	Đối với đồ thị có hướng: có thể không đối xứng, tổng các phần tử trong ma trận bằng tổng số cạnh, tổng các phần tử trên hàng thứ u là bán bậc ra của đỉnh u, tổng các phần tử trên cột thứ u là bán bậc vào của đỉnh u.
	
1b. Ma trận trọng số 
	Mỗi cạnh của đồ thị được gán một trọng số : là giá trị của cạnh.

Dễ cài đặt.
Nếu số đỉnh lớn, thì tốn bộ nhớ.

2. Danh sách cạnh
	Thường được biểu diễn khi đồ thị thưa (số cạnh <= 6 lần số đỉnh)
	+) Đối với đồ thị vô hướng, tồn tại hai đỉnh (u,v) chỉ cần liệt kê một cạnh (u,v).
	+) Đối với đồ thị có hướng, mỗi cạnh là bộ có tính đến thứ tự của các đỉnh.
	Trong trường hợp có trọng số, mỗi cạnh sẽ có thêm trọng số đi kèm đỉnh đầu và đỉnh cuối.
	Có thể biểu diễn bằng pair hoặc khởi tạo một struct 
	
	+) Đối với đồ thị có hướng, chú ý tới hướng của cạnh. Với đồ thị có hướng có trọng số ta làm tương tự như với đồ thị vô hướng có trọng số.
	
Tiết kiệm bộ nhớ, thuận lợi cho các bài toán chỉ liên quan tới cạnh của đồ thị.
Khi duyệt các đỉnh kề với đỉnh nào đó, bắt buộc phải duyệt tất cả các cạnh dẫn tới chi phí tính toán lớn.

3. Danh sách kề 
	Đối với mỗi đỉnh u của đồ thị, ta lưu trữ danh sách các đỉnh kề với đỉnh u. Trong c++, tra dùng vector.
	Để lưu trữ toàn bộ danh sách kề của các đỉnh ta dùng mảng vector.

