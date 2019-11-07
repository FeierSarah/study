
public class StringTest {

	public static void main(String[] args) {
		/*String str1=new String();
		String str4="";
		String str2=new String("abc");
		char[] chs={'a','b','c'};
		String str3=new String(chs);
		System.out.println(str1);
		System.out.println(str2);
		System.out.println(str3);*/
		String ID="61011219990908102X";
		System.out.println(ID.indexOf("61")==0);
		System.out.println(ID.startsWith("61"));
		System.out.println(ID.contains("61"));
		String str="";
		System.out.println(str.isEmpty());
		
		System.out.println("今年是"+2019+"年");
		System.out.println("今年是"+String.valueOf(2019)+"年");
		String str1="abcdefg";
		System.out.println(str1.replace("d", "*"));
		
		String info="张三,123456,35341234,123@163.com";
		addUser(info);
		
	}
	
	public static void addUser(String userInfo)
	{
		String[] infos=userInfo.split(",");
		/*for(int i=0;i<infos.length;i++)
		{
			System.out.println(infos[i]);
		}*/
		String str="insert into user values('";
		str=str+infos[0];
		str=str+"','";
		str=str+infos[1];
		str=str+"','";
		str=str+infos[2];
		str=str+"','";
		str=str+infos[3];
		str=str+"')";
		
		System.out.println(str);
		String num="201706060101";
		System.out.println(num.substring(4));
		
		//根据所给的身份证号判断这个人是否是2001年出生
		String IDNum="61011220010908102X";
		System.out.println(IDNum.substring(6,10).equals("2001"));
		System.out.println(Integer.parseInt(IDNum.substring(6,10))==2001);
		System.out.println(IDNum.substring(6).startsWith("2001"));
		System.out.println(IDNum.substring(0,10).endsWith("2001"));
		System.out.println(IDNum.indexOf("2001")==6);
		
		
		StringBuffer str1=new StringBuffer("insert into user values('");
		str1.append(infos[0]);
		str1.append("','");
		str1.append(infos[1]);
		str1.append("','");
		str1.append(infos[2]);
		str1.append("','");
		str1.append(infos[3]);
		str1.append("')");
		
		str1.insert(0,"x");
		System.out.println(str1.toString());
	}

}
