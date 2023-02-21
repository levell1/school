SELECT  Dept_ID, YEAR , COUNT(*) "ÀÎ¿ø¼ö"
FROM    Student
GROUP   BY ROLLUP(Dept_ID, Year)
/
