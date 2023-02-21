SELECT Dept_ID, Student_ID, Name, '2018/07/15' "휴학일자",
 TO_DATE('180715','YYMMDD')+NUMTOYMINTERVAL(1,'YEAR') "복학예정일"
FROM  Student
WHERE Student_ID  = 'C1802'
/
