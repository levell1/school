SELECT Course_ID, Student_ID, SCORE,
       RANK()       OVER (ORDER BY SCORE DESC) "����",
       DENSE_RANK() OVER (ORDER BY SCORE DESC) "����",
       ROW_NUMBER() OVER (ORDER BY SCORE DESC) "����"
FROM   SG_SCORES
WHERE  Student_ID = 'C1701'
/
