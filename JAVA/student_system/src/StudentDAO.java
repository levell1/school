import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.Scanner;

import javax.swing.JOptionPane;

/**
 * StudentDAO.java 
 * 학생관리시스템에서 요구하는 기능을 처리하는 객체를 만드는 클래스
 * 학생관리시스템의 요구사항을 만족시키기 위해서 입력정보를 StudentUI 객체의 도움을
 * 받아 모든 로직을 처리하고 실제 데이터를 보관하는 역할을 담당한다.
 */

public class StudentDAO extends Exception {
	private Scanner scan;
	private ArrayList<Student> list;
	private String id;			// 학생 id
	private String name;		//학생 이름
	private int score;			//학생 성적

	public StudentDAO() {
		list = new ArrayList<Student>();
	}
	public ArrayList<Student> list() {
		return list;
	}
	//1. 등록(form)
	public String insert(String a,String b,String c) {
		
		String str = "";
		score = Integer.parseInt(c);
		Student stu = new Student(a, b, score);
		
		for(int i = 0; i < list.size(); i++) {
			Student stu1 = list.get(i);
			if(a.equals(stu1.getId())) {
				JOptionPane.showMessageDialog(null,"이미 존재하는 아이디입니다.","존재하는 아이디", JOptionPane.ERROR_MESSAGE );
				str="=====등록 실패하였습니다.=====" +'\n';
				return str;
			}
		}
		if (0>=score || score>=100) {
			JOptionPane.showMessageDialog(null,"성적은 (0~99)까지 입력가능합니다.","성적입력 오류", JOptionPane.ERROR_MESSAGE );
			str="=====등록 실패하였습니다.=====" +'\n';
			return str;
		}
		list.add(stu);
		JOptionPane.showMessageDialog(null,"등록 성공하였습니다.","등록성공", JOptionPane.INFORMATION_MESSAGE );
		str="=====등록 성공하였습니다.=====" +'\n' ;
		str+="학번: "+a+"\t이름: "+b+"\t성적: "+c;
		return str;
		
	}

	//2. 조회
	public String inquire() {
		int a= list.size();
		String str = "\t==회원 수 :"+a+"명=="+'\n';
		
		for(int i = 0; i < list.size(); i++){
			str += "학번:" + list.get(i).getId() + "\t이름: " + list.get(i).getName() + "\t성적: " + list.get(i).getScore()+'\n';
		}

		return str;
	}
	
	//3. 수정 메뉴
	public String update() {
		String str ="";
		String rename = null;
		String rescore = null;
		int score1;
		String reid = JOptionPane.showInputDialog("수정 할 학번을 입력하세요");
		JOptionPane.showMessageDialog(null,"변경 할 학번이 \" "+reid+" \" 가 맞나요?"+'\n', "학번 확인",JOptionPane.INFORMATION_MESSAGE );
		//변경할 학번 찾기
		int remnum = -1;
		//stu 에 변경할 학생의 정보를 저장 , remnum에 변경할 학생배열 번호저장
		for(int i = 0; i < list.size(); i++) {
			Student stu = list.get(i);
			if(reid.equals(stu.getId())) {
				remnum = i;
			}
		}
		
		//없는아이디 체크
		if (remnum == -1) {
			JOptionPane.showMessageDialog(null,reid+"는 없는 아이디입니다.","없는 아이디", JOptionPane.ERROR_MESSAGE );
			str="없는아이디입니다.";
			return str;
		}
		
		//변경전 데이터 저장 (사용자에게 변경전, 후 차이를 보여주기 위하여)
		Student laststu = list.get(remnum);
		String lastid = laststu.getId();
		String lastname = laststu.getName();
		int lastscore = laststu.getScore();
		
		
		//수정코드
		if (reid !=null) {
			reid = JOptionPane.showInputDialog("재설정 할 학번을 입력하세요");
			//아이디 중복체크
			for(int i = 0; i < list.size(); i++) {
				Student stu = list.get(i);
				if(reid.equals(stu.getId())) {
					//경고창
					JOptionPane.showMessageDialog(null,"이미 존재하는 아이디입니다.","존재하는 아이디", JOptionPane.ERROR_MESSAGE );
					str="수정 실패하였습니다.";
					return str;
				}
			}
			rename = JOptionPane.showInputDialog("재설정 할 이름을 입력하세요");
			rescore = JOptionPane.showInputDialog("재설정 할 성적을 입력하세요(0~99)");
		}
		//성적값 오류
		while (true) {
			try {
				score1 = Integer.parseInt(rescore);
				if (0>=score1|| score1>=100) {
					str="성적은 (0~99)까지 입력가능합니다."+'\n';
					str+="=====등록 실패하였습니다.=====";
					rescore = JOptionPane.showInputDialog("정수(0~99)를 다시 입력하세요");
				}
				else if(0<=score1 && score1<100) {
					break;
				}
				
			}  catch (NumberFormatException e) {
				rescore = JOptionPane.showInputDialog("정수(0~99)를 다시 입력하세요");
			}
		}
		
		
		score1 = Integer.parseInt(rescore);
		Student stu = new Student(reid, rename, score1);
		str="학번: "+lastid+"\t이름: "+lastname+"\t성적: "+lastscore+"  이"+'\n'
				+"학번: "+reid+"\t이름: "+rename+"\t성적: "+score1+"  로 변경되었습니다.";
		
		list.set(remnum,stu);
		return str;
	}
	
	//4. 삭제 메뉴
	public String delete() {
		String del_id = JOptionPane.showInputDialog("삭제 할 학번을 입력하세요");
		String str="";
		boolean found = false;
		int tempIndex = 0;
		
		for(int i = 0; i < list.size(); i++) {
			Student stu = list.get(i);
			if(del_id.equals(stu.getId())) {
				found = true;
				tempIndex = i;
			}
		}
		
		if(found) {
			list.remove(tempIndex);
			JOptionPane.showMessageDialog(null,del_id+" 님의  정보가  삭제되었습니다.","삭제", JOptionPane.INFORMATION_MESSAGE );
			str= del_id+" 의 정보가 삭제됨";
		}else {
			JOptionPane.showMessageDialog(null,del_id+" 는  없는  아이디입니다.","에러",  JOptionPane.ERROR_MESSAGE );
			str =del_id+" 는 없는학번입니다."+'\n';
			str+="=====삭제 실패하였습니다.=====";
		}
		return str;
	}


	//5. 성적순으로 정렬
	public void sortScore() {
			ScoreComparator scmp = new ScoreComparator();
			Collections.sort(list,scmp);
		}

	//6. 이름순으로 정렬
	public void sortName() {
			Collections.sort(list);
		}
	
	//7.저장
	public void save() throws IOException {
			OutputStream out = new FileOutputStream("person.txt");
			ObjectOutputStream oos = new ObjectOutputStream(out);
			oos.writeObject(list);
			
			oos.close();
			out.close();
			JOptionPane.showMessageDialog(null,"저장 성공하였습니다.","저장 성공", JOptionPane.INFORMATION_MESSAGE );
		}
	
	//8.불러오기
	public void load() throws Exception{
			
		Object obj =null;
		InputStream in = null;
		ObjectInputStream ois = null;
		
		in = new FileInputStream("person.txt");
		ois = new ObjectInputStream(in);
		obj = ois.readObject();
		
		list =  (ArrayList<Student>) obj;
		
		ois.close();
		in.close();
		JOptionPane.showMessageDialog(null,"불러오기 성공하였습니다.","불러오기 성공", JOptionPane.INFORMATION_MESSAGE );
		
	}

	
}
