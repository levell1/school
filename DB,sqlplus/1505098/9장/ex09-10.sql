SELECT  Dept_ID, YEAR , COUNT(*) "�ο���"
FROM    Student
GROUP   BY ROLLUP(Dept_ID, Year)
/
