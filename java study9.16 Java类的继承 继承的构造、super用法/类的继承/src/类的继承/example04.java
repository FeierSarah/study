package ��ļ̳�;
//super���ø��׵Ĺ��췽��
class Animalz{
	public Animalz(String name) {
	System.out.println("����" + name);
	}
}
class Dogz extends Animalz{
	public Dogz() {
		super("����");
	}
}
public class example04 {
	public static void main(String[] args) {
		Dogz dogz = new Dogz();
	}
}
