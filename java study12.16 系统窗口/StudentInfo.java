//定义一个表示一条记录的学生信息类
public class StudentInfo {

	private String sno;
	private String sname;
	private String sex;
	private int age;
	private String sdept;
	public void setSno(String sno) {
		this.sno = sno;
	}
	public String getSno() {
		return sno;
	}
	public void setSname(String sname) {
		this.sname = sname;
	}
	public String getSname() {
		return sname;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getSex() {
		return sex;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getAge() {
		return age;
	}
	public void setSdept(String sdept) {
		this.sdept = sdept;
	}
	public String getSdept() {
		return sdept;
	}
	
	public StudentInfo(String sno,String sname,String sex,int age,String sdept)
	{
		this.sno=sno;
		this.sname=sname;
		this.sex=sex;
		this.age=age;
		this.sdept=sdept;
	}
}
