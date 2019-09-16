package 类的继承;
//super调用父亲的构造方法
class Animalz{
	public Animalz(String name) {
	System.out.println("我是" + name);
	}
}
class Dogz extends Animalz{
	public Dogz() {
		super("哈哈");
	}
}
public class example04 {
	public static void main(String[] args) {
		Dogz dogz = new Dogz();
	}
}
