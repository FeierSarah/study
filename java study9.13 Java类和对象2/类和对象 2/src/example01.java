//构造方法的定义
class Person {
	int age;
	public Person(int a) {
		age = a;
	}
	public void speak() {
		System.out.println("今年" + age);
	}
}
public class example01 {
	/**
	 * 实例化一个类的对象后，如果要为这个对象中的属性赋值，则必须直接访问对象的属性或调用 sexXxx() 方法，
	 * 如果需要在实例化对象的同时就为这个对象的属性进行赋值，可以通过构造方法来实现
	 * 构造方法（也被称为构造器）是类的一个特殊成员，它会在类实例化对象时被自动调用
	 */
	public static void main(String[] args) {
		Person p = new Person(18);
		p.speak();
	}
}
