import java.io.Serializable;

/**
 * Student.java
 * 학생관리시스템에서 학생 데이터 하나를 객체단위로 보관하기 위한 클래스
 * 학생 각각의 정보는 하나의 Student 데이터 객체가 된다.
 */
public class Student implements Serializable, Comparable<Student>{
	private String id;		//학번
	private String name;	//이름
	private int score;		//성적

	public Student(String id, String name, int score) {
		this.id = id;
		this.name = name;
		this.score = score;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getScore() {
		return score;
	}

	public void setScore(int score) {
		this.score = score;
	}

	//객체 정보를 문자열로 표현
	public String toString() {
		return "학번:"+id+ " 이름:"+name+" 성적:"+score+"\n";
	}
	//객체 같은지 검사
	public boolean equals(Student stu) {
		boolean result = false;
		if(id.equals(stu.id))
			return true;
		return result;
	}

	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		return name.compareTo(o.name);
	}
}









