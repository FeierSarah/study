//静态代码块
class Personn{
	static {
		System.out.println("执行了Personn类中的静态代码块");
	}
}
public class example03 {
	static {
		System.out.println("执行了测试类中的静态代码块");
	}
	public static void main(String[] args) {
		Personn p1 = new Personn();
		Personn p2 = new Personn();
	}
	//静态代码块在类的第一次使用时才会被加载，且只会被调用一次
}
