public class example10 {
	//break outer
	public static void main(String[] args) {
		outer:for(int i=1;i<=9;i++) {
			for(int j=1;j<=i;j++) {
				if(i>=3) {
					break outer;
				}
				System.out.print(j+"*"+i+"="+j*i+"\t");
			}
			System.out.println("");
		}
	}
}
