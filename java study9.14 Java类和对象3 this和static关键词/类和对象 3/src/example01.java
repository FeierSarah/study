//this �ؼ���
//this����ָ����ǰ���������ڷ����з��ʶ����������Ա
//�÷�1������ֲ��������Ƴ�ͻ
/*class Person{
	int age;
	public Person(int age) {
		this.age = age;
	}
}*/

//�÷�2��ͨ��this���ó�Ա����
/*class Person{
	public void openMouth() {
		System.out.println(" ");
	}
	public void speak() {
		this.openMouth();
	}
}*/

//����3�����ù��췽��
class Person{
	public Person() {
		System.out.println("�޲������췽��������");
	}
	public Person(int age) {
		this();
		System.out.println("�в������췽��������");
	}
}
public class example01 {
	public static void main(String[] args) {
		Person p = new Person(18);
	}
}
