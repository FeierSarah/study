package 类和对象;
//方法的递归
public class example04 {
	public static int getSum(int n) {
		if (n == 1) {//结束条件
			return 1;
		}
		int temp = getSum(n - 1);
		return temp + n;
	}
	public static void main(String[] args) {
		int sum = getSum(4);
		System.out.println(sum);
	}
}
