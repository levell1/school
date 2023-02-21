SELECT Student_ID , NAME, I_DATE,
       TO_CHAR(I_DATE, 'RRRR/MM/DD (DAY)')"입학일자"
FROM   Student
ORDER  BY 3
/
