// Khái niệm cơ bản về đồ thị

1. Đơn  đồ thị vô hướng
	G = <V,E>, gồm V là tập các đỉnh, E là tập các cặp không có thứ tự gồm 2 phần tử khác nhau của V gọi là các cạnh.
2. Đa đồ thị vô hướng
	Tương tự như đơn đồ thị vô hướng nhưng khác biệt là giữa hai đỉnh có thể tồn tại nhiều hơn 1 cạnh.
3. Giả đồ thị vô hướng
	Cạnh có đỉnh đầu và cuối là như nhau, gọi là khuyên.
	
4. Đơn đồ thị có hướng
	G = <V,E>, gồm V là các tập đỉnh, E là tập các cặp có thứ tự gồm 2 phần tử V gọi là các cung.
5. Đa đồ thị có hướng
	Giữa hai đỉnh có thể tồn tại nhiều hơn một cung. Hai cung tương ứng với cùng một đỉnh gọi là cung lặp.
6. Đỉnh kề, cạnh liên thuộc
	Hai đỉnh là kề nhau nếu tồn tại cạnh nối hai đỉnh đó là cạnh của đồ thị.
	Cạnh liên thuộc là cạnh của hai đỉnh của nó.
	
7. Bậc của đỉnh trên đồ thị vô hướng
	Là số cạnh liên thuộc với đỉnh đó.
	Đỉnh có bậc bằng 0 là đỉnh cô lập.
	Đỉnh có bậc bằng 1 là đỉnh treo.
	Định lý:
		Đồ thị G = <V,E> là đồ thị vô hướng có m cạnh, khi đó tổng bậc của các đỉnh trên đồ thị bằng 2 lần số cạnh.

8. Bán bậc của đỉnh đồ thị có hướng.
	Bán bậc ra của đỉnh là số cung đi ra của đỉnh đó.
	Bán bậc vào của đỉnh là số cung đi vào của đỉnh đó.
	Định lý:
		Tổng số bán bậc ra = tổng số bán bậc vào = số cung của đồ thị.

9. Đường đi
	Đường đi: dãy các đỉnh hoặc dãy các cạnh trong đó 2 đỉnh liên tiếp có cạnh nối. Độ dài đườn đi là số cạnh trên đường đi.
	Đường đi đơn: các đỉnh trên đường đi là phân biệt.
10. Chu trình
	là đường đi gồm các cạnh phân biệt có đỉnh đầu trùng với đỉnh cuối.
	Chu trình đơn là chu trình không có đỉnh nào giống nhau ngoại trừ đỉnh đầu với đỉnh cuối.
11. Liên thông
	Liên thông: đồ thị được gọi là liên thông nếu luôn tồn tại đường đi bất kì giữa hai đỉnh của đồ thị.
	Thành Phần liên thông: trường hợp đồ thị vô hướng không liên thông, nó phân rã thành các thành phần liên thông.
12. Liên thông mạnh, yếu
	Liên thông mạnh: đồ thị có hướng mà giữa hai đỉnh bất kì luôn có đường đi.
	Liên thông yếu: đồ thị có hướng nếu đồ thị vô hướng tương ứng với nó liên thông.
