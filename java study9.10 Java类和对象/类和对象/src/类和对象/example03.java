package 类和对象;
//方法的重载
//方法重载：Java允许在一个程序中定义多个名称相同，但是参数的类型或个数不同的方法
public class example03 {
	public static int add(int x, int y) {
		return x + y;
	}
	public static int add(int x, int y, int z) {
		return x + y + z;
	}
	public static double add(double x, double y) {
		return x + y;
	}
	public static void main(String[] args) {
		int sum1 = add(1, 2);
		int sum2 = add(3, 4, 7);
		double sum3 = add(0.2, 5.3);
		System.out.println(sum1);
		System.out.println(sum2);
		System.out.println(sum3);
	}
}
