SELECT Student_ID, Course_ID,Score,Score_Assigned,
       TO_CHAR(Score_Assigned,  'YYYY/MM/DD')
FROM   SG_Scores
WHERE  Score >=98
ORDER  BY 3 DESC
/
