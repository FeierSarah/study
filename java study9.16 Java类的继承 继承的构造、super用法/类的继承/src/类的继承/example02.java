package 类的继承;
//重写父类方法
class Animals{
	void shout() {
		System.out.println("动物发出叫声");
	}
}
class Dogs extends Animals{
	void shout() {
		System.out.println("汪汪");
	}
}
public class example02 {
	public static void main(String[] args) {
		Dogs dogs = new Dogs();
		dogs.shout();
	}
}
