INSERT INTO Computer_Student
(Student_ID,Dept_ID, Year,Name,ID_Number)
VALUES
(CONCAT('C',LTRIM(TO_CHAR(ST_SEQ.NEXTVAL,'9999'))),
   '&학과','&학년','&성명','&주민번호')
/
