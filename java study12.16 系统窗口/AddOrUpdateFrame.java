import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class AddOrUpdateFrame extends JFrame implements ActionListener{
	
	JLabel numLa,nameLa,sexLa,ageLa,deptLa;
	JTextField numTxt,nameTxt,ageTxt;
	JComboBox sexCom,deptCom;
	JButton bt;
	MainFrame main;//定义主窗口
	
	public AddOrUpdateFrame(String type,StudentInfo stu,MainFrame main)
	{
		this.setSize(300,400);
		this.setLayout(null);
		numLa=new JLabel("学号");
		numLa.setSize(60, 30);
		numLa.setLocation(30, 30);
		this.add(numLa);
		numTxt=new JTextField();
		numTxt.setSize(120, 30);
		numTxt.setLocation(100, 30);
		this.add(numTxt);
		nameLa=new JLabel("姓名");
		nameLa.setSize(60, 30);
		nameLa.setLocation(30, 80);
		this.add(nameLa);
		nameTxt=new JTextField();
		nameTxt.setSize(120, 30);
		nameTxt.setLocation(100, 80);
		this.add(nameTxt);
		sexLa=new JLabel("性别");
		sexLa.setSize(60, 30);
		sexLa.setLocation(30, 130);
		this.add(sexLa);
		sexCom=new JComboBox();
		sexCom.setSize(120, 30);
		sexCom.setLocation(100, 130);
		sexCom.addItem("男");
		sexCom.addItem("女");
		this.add(sexCom);
		ageLa=new JLabel("年龄");
		ageLa.setSize(60, 30);
		ageLa.setLocation(30, 180);
		this.add(ageLa);
		ageTxt=new JTextField();
		ageTxt.setSize(120, 30);
		ageTxt.setLocation(100, 180);
		this.add(ageTxt);
		deptLa=new JLabel("年龄");
		deptLa.setSize(60, 30);
		deptLa.setLocation(30, 230);
		this.add(deptLa);
		deptCom=new JComboBox();
		deptCom.setSize(120, 30);
		deptCom.setLocation(100, 230);
		deptCom.addItem("CS");
		deptCom.addItem("IS");
		deptCom.addItem("MA");
		this.add(deptCom);
		if(type.equals("增加"))
		{
			this.setTitle("增加");
			bt=new JButton("增加");
			bt.setSize(60, 30);
			bt.setLocation(90,280);
		}
		else
		{
			this.setTitle("修改");
			bt=new JButton("修改");
			bt.setSize(60, 30);
			bt.setLocation(90,280);
			if(stu!=null)
			{
				numTxt.setText(stu.getSno());
				numTxt.setEditable(false);
				nameTxt.setText(stu.getSname());
				sexCom.setSelectedItem(stu.getSex());
				ageTxt.setText(String.valueOf(stu.getAge()));
				deptCom.setSelectedItem(stu.getSdept());
			}
		}
		this.add(bt);
		bt.addActionListener(this);
		this.setVisible(true);
		this.main=main;
	}
	
	public void actionPerformed(ActionEvent e)
	{
		JButton bt=(JButton)e.getSource();
		StudentDAO dao=new StudentDAO();
		String sno=numTxt.getText().trim();
		String sname=nameTxt.getText().trim();
		String sex=sexCom.getSelectedItem().toString();
		int age=Integer.parseInt(ageTxt.getText().trim());
		String sdept=deptCom.getSelectedItem().toString();
		StudentInfo stu=new StudentInfo(sno,sname,sex,age,sdept);
		if(bt.getText().equals("修改"))
		{
			dao.updateStudent(stu);
		}
		else
		{
			dao.addStudent(stu);
		}
		ArrayList list=dao.findStuBySname("");
		main.initTable(list);
		this.dispose();
		
	}
}
