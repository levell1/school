SELECT Dept_ID, Student_ID, Name, '2018/07/15' "��������",
 TO_DATE('180715','YYMMDD')+NUMTOYMINTERVAL(1,'YEAR') "���п�����"
FROM  Student
WHERE Student_ID  = 'C1802'
/
