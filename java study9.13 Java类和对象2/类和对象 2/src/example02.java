//���췽��������
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
		System.out.println("����" + age);
	}
	public void say() {
		System.out.println(name + "����" + age);
	}
}
public class example02 {
	public static void main(String[] args) {
		Persons p1 = new Persons(18);
		Persons p2 = new Persons("����",32);
		p1.speak();
		p2.say();
	}
}
