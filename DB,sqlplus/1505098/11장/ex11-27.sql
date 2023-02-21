DELETE FROM Computer_Student
WHERE  Year = (SELECT Year
               FROM   Student
               WHERE  Student_ID = 'C1602')
/
