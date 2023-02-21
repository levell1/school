SELECT Dept_ID, NAME, ID_Number,
       DECODE(SUBSTR(ID_NUMBER , 8, 1), '1', '남', '2','여',
                                        '3', '남', '4','여')
FROM   Student
WHERE  Dept_ID ='컴공'
ORDER  BY 3
/
