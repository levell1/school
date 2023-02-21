SELECT  Dept_ID, YEAR , COUNT(*) "ÀÎ¿ø¼ö"
FROM    Student
GROUP   BY Dept_ID, Year
ORDER   BY 1,2
/
