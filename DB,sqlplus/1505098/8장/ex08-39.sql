SELECT Dept_ID, Year, student_ID, name, address
FROM   student
WHERE  REGEXP_LIKE (Address, '���ı�|������')
/
