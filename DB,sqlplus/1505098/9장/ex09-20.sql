SELECT UNIQUE Student_ID,
       COUNT(*) OVER (PARTITION BY Student_ID) "�����"
FROM   SG_Scores
ORDER  BY 1
/
