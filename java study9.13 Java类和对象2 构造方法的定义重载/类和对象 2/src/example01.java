//���췽���Ķ���
class Person {
	int age;
	public Person(int a) {
		age = a;
	}
	public void speak() {
		System.out.println("����" + age);
	}
}
public class example01 {
	/**
	 * ʵ����һ����Ķ�������ҪΪ��������е����Ը�ֵ�������ֱ�ӷ��ʶ�������Ի���� sexXxx() ������
	 * �����Ҫ��ʵ���������ͬʱ��Ϊ�����������Խ��и�ֵ������ͨ�����췽����ʵ��
	 * ���췽����Ҳ����Ϊ�������������һ�������Ա����������ʵ��������ʱ���Զ�����
	 */
	public static void main(String[] args) {
		Person p = new Person(18);
		p.speak();
	}
}
