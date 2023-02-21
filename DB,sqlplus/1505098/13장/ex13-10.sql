SELECT Dept_ID, Year, Student_ID, Name, Address
FROM   Student
WHERE  CONTAINS (Address, '¼Û% OR ¼ö%') > 0
/
