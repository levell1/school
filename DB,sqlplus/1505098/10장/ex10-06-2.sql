SELECT SG.STUDENT_ID, SG.COURSE_ID, SG.SCORE,G.GRADE
FROM   SG_SCORES SG,SCORE_GRADE G
WHERE  SG.SCORE BETWEEN G.Low AND G.High
 AND   SG.STUDENT_ID = 'C1602'
ORDER  BY 2
/
