package 类和对象;
//类的定义和对象的创建
class Person {
	int age;
	void speak() {
		System.out.println("我今年" + age + "岁");
	}
}

public class example01 {
	public static void main(String[] args) {
		Person p1 = new Person();
		Person p2 = new Person();
		p1.age = 18;
		p1.speak();
		p2.speak();
	}
}