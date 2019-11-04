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
	
	public static ArrayList getArrays(int count,int max)//产生5个1到22的随机数
	{
		Random ra=new Random();
		ArrayList result=new ArrayList();
		//创建一个可变数组对象来保存结果
		Integer temp=Integer.valueOf(ra.nextInt(max)+1);
		//产生第一个随机数并转换成整形类对象
		result.add(temp);
		//放入到可变数组对象中
		int i=1;
		while(i<=count-1)
		{
			temp=Integer.valueOf(ra.nextInt(22)+1);
			//产生一个随机数并转换成整形类对象
			if(!result.contains(temp))//判断结果中是否已经包含新产生的对象
			{
				result.add(temp);
				i++;
			}
		}
		return result;
	}
	
	

}
