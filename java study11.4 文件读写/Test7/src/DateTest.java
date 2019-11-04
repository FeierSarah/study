import java.util.*;
public class DateTest {
    public static void main(String[] args)
    {
    	/*Date date=new Date();
    	System.out.println(date.getDate());
    	System.out.println(date.getMonth()+1);
    	System.out.println(date.getYear()+1900);
    	System.out.println(date.getHours());
    	System.out.println(date.getMinutes());
    	System.out.println(date.getSeconds());*/
    	
    	Calendar cal=Calendar.getInstance();
    	//创建日历类对象的方法
    	System.out.println(cal.get(Calendar.YEAR));
    	System.out.println(cal.get(Calendar.MONTH));
    	System.out.println(cal.get(Calendar.DATE));
    	System.out.println(cal.get(Calendar.DAY_OF_WEEK));
    }
}
