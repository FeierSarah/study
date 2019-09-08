public class example11 {
	//continue Óï¾ä
	public static void main(String[] args) {
		int sum=0;
		for(int i=1;i<=100;i++) {
			if(i%2==0) {
				continue;
			}
			sum+=i;
		}
		System.out.println("sum="+sum);
	}
}
