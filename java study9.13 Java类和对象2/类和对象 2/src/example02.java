//构造方法的重载
class Persons {
	String name;
	int age;
	public Persons(int a) {
		age = a;
	}
	public Persons(String n , int a) {
		name = n;
		age = a;
	}
	public void speak() {
		System.out.println("今年" + age);
	}
	public void say() {
		System.out.println(name + "今年" + age);
	}
}
public class example02 {
	public static void main(String[] args) {
		Persons p1 = new Persons(18);
		Persons p2 = new Persons("张三",32);
		p1.speak();
		p2.say();
	}
}
