ALTER TABLE SG_Scores
ADD   (User_Name VARCHAR2(25) DEFAULT '����Ŭ����: '	|| USER,
      C_Date     DATE         DEFAULT SYSDATE )
/
