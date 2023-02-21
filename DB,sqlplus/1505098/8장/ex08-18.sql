SELECT Dept_ID, Year, I_Date,CURRENT_DATE "기준일",
       TRUNC(MONTHS_BETWEEN(CURRENT_DATE, I_Date)) "재적월수"
FROM   Student
WHERE  Dept_ID = '컴공'
ORDER  BY 4
/
