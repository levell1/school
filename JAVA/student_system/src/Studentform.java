import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Studentform  extends JFrame implements FocusListener, KeyListener, ActionListener {
	
	int score;
	private StudentDAO dao = new StudentDAO();
	private ArrayList<Student> temp  = dao.list();

	Font godic = new Font("고딕",Font.ITALIC,13);

	private JLabel timer = new JLabel("접속시간");
	private JLabel timerL = new JLabel("");
	
	private JLabel jid = new JLabel("학번: ");
	private JTextField tf_id = new JTextField(10);
	private JLabel jname = new JLabel("이름: ");
	private JTextField tf_name = new JTextField(10);
	private JLabel jscore = new JLabel("성적: ");
	private JTextField tf_score = new JTextField(10);
	
	private JTextArea ta = new JTextArea(7, 20);
	private JScrollPane scroll = new JScrollPane(ta);
	
	private JButton bt_check = new JButton("조회");
	private JButton bt_ok = new JButton("등록");
	private JButton bt_mod = new JButton("수정");
	private JButton bt_del = new JButton("삭제");
	private JButton bt_save = new JButton("저장");
	private JButton bt_load = new JButton("불러오기");
	private JButton bt_exit = new JButton("종료");
	private JButton bt_sortname = new JButton("이름정렬");
	private JButton bt_sortScore = new JButton("성적정렬");
	
	Studentform() {
		
		this.setTitle("1505098_김종욱 학생관리 시스템");
		this.formDesign();
		this.eventHandler();
		this.setSize(660, 310);
		this.setVisible(true);
	}
	public void formDesign() {
		this.setLayout(null);
		this.getContentPane().setBackground(Color.BLACK);
		//라벨
		jid.setLocation(10, 10);
		jid.setSize(50, 30);
		jid.setForeground(Color.white);
		jname.setLocation(10, 45);
		jname.setSize(50, 30);
		jname.setForeground(Color.white);
		jscore.setLocation(10, 80);
		jscore.setSize(50, 30);
		jscore.setForeground(Color.white);
		add(jid);
		add(jname);
		add(jscore);
		
		//텍스트필드
		tf_id.setLocation(50, 10);
		tf_id.setSize(60, 30);
		tf_name.setLocation(50, 45);
		tf_name.setSize(60, 30);
		tf_score.setLocation(50, 80);
		tf_score.setSize(60, 30);
		add(tf_id);
		add(tf_name);
		add(tf_score);
		
		
		//스크롤 text area
		scroll.setLocation(130, 50);
		scroll.setSize(500, 160);
		add(scroll);
		
		//버튼
		bt_check.setLocation(130, 10);
		bt_check.setSize(80, 30);
		bt_check.setFont(godic);
		bt_ok.setLocation(130, 220);
		bt_ok.setSize(70, 30);
		bt_ok.setFont(godic);
		bt_mod.setLocation(210, 220);
		bt_mod.setSize(70, 30);
		bt_mod.setFont(godic);
		bt_del.setLocation(290, 220);
		bt_del.setSize(70, 30);
		bt_del.setFont(godic);
		bt_save.setLocation(370, 220);
		bt_save.setSize(70, 30);
		bt_save.setFont(godic);
		bt_load.setLocation(450, 220);
		bt_load.setSize(100, 30);
		bt_load.setFont(godic);
		bt_exit.setLocation(560, 220);
		bt_exit.setSize(70, 30);
		bt_exit.setFont(godic);
		bt_sortname.setLocation(440, 10);
		bt_sortname.setSize(90, 30);
		bt_sortname.setFont(godic);
		bt_sortScore.setLocation(540, 10);
		bt_sortScore.setSize(90, 30);
		bt_sortScore.setFont(godic);
		add(bt_check);
		add(bt_ok);
		add(bt_mod);
		add(bt_del);
		add(bt_save);
		add(bt_load);
		add(bt_exit);
		add(bt_sortname);
		add(bt_sortScore);
		
		//접속시간
		timer.setLocation(10, 150);
		timer.setSize(110, 20);
		timer.setFont(new Font("Gothic",Font.ITALIC,18));
		timer.setForeground(Color.white);
		add(timer);
		timerL.setLocation(10, 170);
		timerL.setSize(110, 20);
		timerL.setForeground(Color.white);
		timerL.setFont(new Font("Gothic",Font.ITALIC,14));
		add(timerL);
		
		TThread th = new TThread(timerL);
		th.start();
		
		tf_id.setToolTipText("학번입력");
		tf_name.setToolTipText("이름입력");
		tf_score.setToolTipText("성적입력");
		
		ta.setToolTipText("Text Area 입니다.");
			
	}
	public void eventHandler() {
		tf_id.addFocusListener(this);
		tf_name.addFocusListener(this);
		tf_score.addFocusListener(this);
		tf_score.addKeyListener(this);
		bt_check.addActionListener(this);
		bt_ok.addActionListener(this);
		bt_mod.addActionListener(this);
		bt_del.addActionListener(this);
		bt_save.addActionListener(this);
		bt_load.addActionListener(this);
		bt_exit.addActionListener(this);
		bt_sortname.addActionListener(this);
		bt_sortScore.addActionListener(this);
	}
	
	public static void main(String[] args) {
		new Studentform();
	}
	@Override
	public void focusGained(FocusEvent e) {
		if(e.getSource().equals(tf_id)) {
			ta.setText("학번을 입력하세요"+'\n');
		}
		else if(e.getSource().equals(tf_name)) {
			ta.setText("이름을 입력하세요"+'\n');
		}
		else if(e.getSource().equals(tf_score)) {
			 ta.setText("(0~99정수)를 입력해주세요." +'\n');
		}
	}
	@Override
	public void focusLost(FocusEvent e) {
		
	}

	public void keyTyped(KeyEvent e) {
	}

	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == e.VK_ENTER) {
			ta.setText("입력된 정보"+'\n');
			ta.append("학번:"+tf_id.getText()+'\n'+"이름:"+tf_name.getText()+'\n'+"성적:"+tf_score.getText());
		}
	}

	public void keyReleased(KeyEvent e) {
	}

	public void actionPerformed(ActionEvent ac) {
		//1.등록
		if(ac.getSource() == bt_ok) {
			score = Integer.parseInt(tf_score.getText());
			ta.setText(dao.insert(tf_id.getText(), tf_name.getText(), tf_score.getText()));
			tf_id.setText("");
			tf_name.setText("");
			tf_score.setText("");			
		}
		
		//2.조회
		else if(ac.getSource() == bt_check) {
			ta.setText(""); 
			ta.append(dao.inquire());
		}
		
		//3.수정
		else if(ac.getSource() == bt_mod) {
			ta.setText("수정" +'\n');
			
			//사용중인 아이디들을 표시하여 변경에 참고하기위해
			ta.setText("현재 사용중인 학번 목록 입니다."+'\n');
			for(int i = 0; i < temp.size(); i++) {
				ta.append("학번: " + temp.get(i).getId()+"\n");
			}
			
			ta.setText(dao.update());
		}
		//4.삭제
		else if(ac.getSource() == bt_del) {
			ta.setText("삭제" +'\n');
			ta.append(dao.delete());
		}
		//5.저장
		else if(ac.getSource() == bt_save) {
			ta.setText("저장" +'\n');
			try {
				dao.save();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//6.불러오기
		else if(ac.getSource() == bt_load) {
			ta.setText("불러오기" +'\n');				
			try {
				dao.load();
				temp=dao.list();
				ta.append("불러온 데이터입니다." + '\n');
				ta.append(dao.inquire());
				
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//7.이름정렬
		else if(ac.getSource() == bt_sortname) {
			ta.setText("이름순 정렬" +'\n');
			dao.sortName();
			ta.append(dao.inquire());
		}
		//8.점수정렬
		else if(ac.getSource() == bt_sortScore) {
			ta.setText("성적순 정렬" +'\n');
			dao.sortScore();
			ta.append(dao.inquire());
		}
		//0.종료
		else if(ac.getSource() == bt_exit) {
			ta.setText("종료" +'\n');
			JOptionPane.showMessageDialog(null,"종료","종료",  JOptionPane.WARNING_MESSAGE );
			System.exit(0);
		}
		
		
	}

	//쓰레드 접속시간
	class TThread extends Thread{
		private JLabel timerL;
		TThread(JLabel timerL) {
			this.timerL = timerL;
		}
		
		@Override
		public void run() {
			int s1 = 0;
			int m1 = 0;
			String h = "";
			String m = "";
			String s = "";
			
			while (true){
				h = Integer.toString(s1/3600);
				m = Integer.toString(m1%60);
				s = Integer.toString(s1%60);
				timerL.setText( h+"시간 "+m+"분 "+s+"초 ");
				s1++;
				m1=s1/60;
				
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					return;
				}
			}
		}
	}
}
