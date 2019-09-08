public class example08 {
	//嵌套循环语句实现乘法口诀表
	public static void main(String[] args) {
		for(int i=1;i<=9;i++) {
			for(int j=1;j<=i;j++) {
				System.out.print(j+"*"+i +"="+j*i+"\t");
			}
			System.out.println("");
		}
	}
}
