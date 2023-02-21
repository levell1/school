SELECT Student_ID, Course_ID, Score, Score_Assigned
FROM   SG_Scores
WHERE  Course_ID = 'L1031'
  AND  Score     = ( SELECT MAX(Score)
                     FROM   SG_Scores
                     WHERE  Course_ID = 'L1031')
/