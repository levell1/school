SELECT Dept_ID, Year, I_Date,CURRENT_DATE "������",
       TRUNC(MONTHS_BETWEEN(CURRENT_DATE, I_Date)) "��������"
FROM   Student
WHERE  Dept_ID = '�İ�'
ORDER  BY 4
/
