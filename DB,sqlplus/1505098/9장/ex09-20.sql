SELECT UNIQUE Student_ID,
       COUNT(*) OVER (PARTITION BY Student_ID) "°ú¸ñ¼ö"
FROM   SG_Scores
ORDER  BY 1
/
