package ��ļ̳�;
//��д���෽��
class Animals{
	void shout() {
		System.out.println("���﷢������");
	}
}
class Dogs extends Animals{
	void shout() {
		System.out.println("����");
	}
}
public class example02 {
	public static void main(String[] args) {
		Dogs dogs = new Dogs();
		dogs.shout();
	}
}
