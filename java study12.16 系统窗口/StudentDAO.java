//对于学生表进行数据操作的类
import java.sql.*;
import java.util.*;
public class StudentDAO {
	private Connection con;
	public StudentDAO()
	{
		try{
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			//加载驱动
			String conStr="jdbc:sqlserver://localhost:1433; DatabaseName=student_course";
			//配置连接字符串
			String user="sa";
			//配置用户名
			String password="sa123";
			//配置用户的访问密码
			con=DriverManager.getConnection(conStr,user,password);
			//创建数据库连接对象
		}
	    catch (ClassNotFoundException e) {//捕捉处理驱动类未找到异常
		// TODO Auto-generated catch block
		e.printStackTrace();
	    }
       catch (SQLException e) {//捕捉处理数据连接或者操作异常
	     // TODO Auto-generated catch block
	     e.printStackTrace();
    }
		
	}
	
	//根据学号来查询学生
	public StudentInfo findStuBySno(String sno)
	{
		StudentInfo stu=null;
		try{
			PreparedStatement ps=con.prepareStatement("select * from student where sno=?");
     		ps.setString(1, sno);
			ResultSet rs=ps.executeQuery();
		    if(rs.next())
		    {
		    	String name=rs.getString(2);
		    	String sex=rs.getString(3);
		    	int age=rs.getInt(4);
		    	String dept=rs.getString(5);
		    	stu=new StudentInfo(sno,name,sex,age,dept);
		    }
			ps.close();
			//关闭SQL语句执行对象
			//con.close();
			//关闭数据库连接对象
		} 
	       catch (SQLException e) {//捕捉处理数据连接或者操作异常
		// TODO Auto-generated catch block
		e.printStackTrace();
	    }

		return stu;
	}
	
	//根据姓名来查询学生
	public ArrayList<StudentInfo> findStuBySname(String sname)
	{
		ArrayList<StudentInfo> result=new ArrayList<StudentInfo>();
		try{
			Statement st=con.createStatement();
     		String strSQL="select * from student where sname like '%"+sname+"%'";
			ResultSet rs=st.executeQuery(strSQL);
		    while(rs.next())
		    {
		    	String sno=rs.getString(1);
		    	String name=rs.getString(2);
		    	String sex=rs.getString(3);
		    	int age=rs.getInt(4);
		    	String dept=rs.getString(5);
		    	StudentInfo stu=new StudentInfo(sno,name,sex,age,dept);
		    	result.add(stu);
		    }
			st.close();
			//关闭SQL语句执行对象
			//con.close();
			//关闭数据库连接对象
		} 
	       catch (SQLException e) {//捕捉处理数据连接或者操作异常
		// TODO Auto-generated catch block
		e.printStackTrace();
	    }

		return result;
	}
	
	public void addStudent(StudentInfo stu)
	{
		try{
			PreparedStatement ps=con.prepareStatement("insert into student values(?,?,?,?,?)");
			//创建SQL语句执行对象
			ps.setString(1, stu.getSno());
			ps.setString(2,stu.getSname());
			ps.setString(3, stu.getSex());
			ps.setInt(4,stu.getAge());
			ps.setString(5,stu.getSdept());
			ps.execute();
			ps.close();
			//关闭SQL语句执行对象
			//con.close();
			//关闭数据库连接对象
		} 
	       catch (SQLException e) {//捕捉处理数据连接或者操作异常
		// TODO Auto-generated catch block
		e.printStackTrace();
	    }
	}
	
	public void delStudent(String sno)
	{
		try{
			PreparedStatement ps=con.prepareStatement("delete from student where sno=?");
			//创建SQL语句执行对象
			ps.setString(1, sno);
			ps.execute();
			ps.close();
			//关闭SQL语句执行对象
			//con.close();
			//关闭数据库连接对象
		} 
	       catch (SQLException e) {//捕捉处理数据连接或者操作异常
		// TODO Auto-generated catch block
		e.printStackTrace();
	    }
	}
	
	public void updateStudent(StudentInfo stu)
	{
		
			try{
				PreparedStatement ps=con.prepareStatement("update student set sname=?,ssex=?,sage=?,sdept=? where sno=?");
				//创建SQL语句执行对象
				ps.setString(1,stu.getSname());
				ps.setString(2, stu.getSex());
				ps.setInt(3,stu.getAge());
				ps.setString(4,stu.getSdept());
				ps.setString(5, stu.getSno());
				ps.execute();
				ps.close();
				//关闭SQL语句执行对象
				//con.close();
				//关闭数据库连接对象
			} 
		       catch (SQLException e) {//捕捉处理数据连接或者操作异常
			// TODO Auto-generated catch block
			e.printStackTrace();
		    }
	       
	}
}
