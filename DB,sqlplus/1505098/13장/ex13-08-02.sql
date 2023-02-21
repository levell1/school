SELECT Dept_ID, Year, Student_ID, Name, ID_Number, Telephone
FROM   Student
WHERE  SUBSTR(ID_Number, 1,6) = '990205'
/
