//数组查找最大值
public class example03 {
	public static void main(String[] args) {
		int[] arr = {1, 2, 5, 8, 7, 6, 3 };
		int max = arr[0];
		for(int i = 1; i < arr.length; i++) {
			if(arr[i] > max) {
				max = arr[i];
			}
		}
		System.out.println("数组最大为：" + max);
	}
}
