SELECT Dept_ID, NAME, ID_Number,
       DECODE(SUBSTR(ID_NUMBER , 8, 1), '1', '��', '2','��',
                                        '3', '��', '4','��')
FROM   Student
WHERE  Dept_ID ='�İ�'
ORDER  BY 3
/
