SELECT Student_ID, Name
FROM   Student
MINUS
SELECT Student_ID, Name
FROM   SG_Scores  INNER JOIN Student USING (Student_ID)
/