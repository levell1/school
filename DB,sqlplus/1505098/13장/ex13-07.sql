SELECT Student_ID, Name, Course_ID, Score
FROM SG_Scores INNER JOIN Student USING (Student_ID)
WHERE (Course_ID, Grade) = (('L1031', 'B+'))
/
