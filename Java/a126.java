package Java;

public class a126 {
        private static int total = 0; // Biến static để đếm tổng số phương tiện

        private String type;

    public a126(String type) {

        this.type = type;

        total++; // Tăng tổng số phương tiện khi tạo đối tượng mới

    }

    public static void main(String[] args) {

        a126 car = new a126("Car");

        a126 motorbike = new a126("Motorbike");

        a126 boat = new a126("Boat");

        System.out.println("Tong so phuong tien: " + a126.total); // Kết quả: 2

        System.out.println();
    }
}
