package ��Ͷ���;
//��Ķ���Ͷ���Ĵ���
class Person {
	int age;
	void speak() {
		System.out.println("�ҽ���" + age + "��");
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