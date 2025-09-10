package Java;

public class bai17_StringMethods {
    public static void main(String[] args) {
        String name = "    Bro      ";

        boolean result = name.equalsIgnoreCase("bro");  //so sanh 
        //int result = name.length();  do lon
        //char result = name.charAt(2); tra ve ky tu
        //int result = name.indexOf("r ");  tra ve vi tri
        //boolean result = name.isEmpty();  trong hay khong
        //String result = name.toUpperCase();  viet hoa
        //String result = name.toLowerCase();  viet thuong
        //String result = name.trim();  xoa bo khoang trang truoc va sau
        //String result = name.replace('o', 'a');//thay the

        System.out.println(result);
    }
}
