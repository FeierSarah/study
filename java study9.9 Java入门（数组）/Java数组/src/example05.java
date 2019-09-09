//多维数组定义
public class example05 {
	public static void main(String[] args) {
		int[][] arr = new int [3][];
		arr[0] = new int[] {11, 23 };
		arr[1] = new int[] {21, 34, 22 };
		arr[2] = new int[] {31, 56, 32, 24 };
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}
