import java.util.*;


public class ArrayListTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList list=getArrays(9,45);
		for(int i=0;i<list.size();i++)
		{
			System.out.print(list.get(i)+",");
		}
	}
	
	public static ArrayList getArrays(int count,int max)//����5��1��22�������
	{
		Random ra=new Random();
		ArrayList result=new ArrayList();
		//����һ���ɱ����������������
		Integer temp=Integer.valueOf(ra.nextInt(max)+1);
		//������һ���������ת�������������
		result.add(temp);
		//���뵽�ɱ����������
		int i=1;
		while(i<=count-1)
		{
			temp=Integer.valueOf(ra.nextInt(22)+1);
			//����һ���������ת�������������
			if(!result.contains(temp))//�жϽ�����Ƿ��Ѿ������²����Ķ���
			{
				result.add(temp);
				i++;
			}
		}
		return result;
	}
	
	

}
