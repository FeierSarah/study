package ��ļ̳�;
//super
class Animalss{
	String name = "����";
	void shout() {
		System.out.println("���﷢������");
	}
}
class Dogss extends Animalss{
	String name = "Ȯ��";
	void shout() {
		super.shout();
	}
	void printName() {
		System.out.println("name = " + super.name);
	}
}
public class example03 {
	public static void main(String[] args) {
		Dogss dogss = new Dogss();
		dogss.shout();
		dogss.printName();
	}
}
