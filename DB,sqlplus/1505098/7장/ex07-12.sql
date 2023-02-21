ALTER TABLE SG_Scores
ADD   (User_Name VARCHAR2(25) DEFAULT '오라클계정: '	|| USER,
      C_Date     DATE         DEFAULT SYSDATE )
/
