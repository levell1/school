SELECT PROFESSOR_ID,NAME,POSITION,TITLE,C_NUMBER
FROM   PROFESSOR INNER JOIN COURSE USING (PROFESSOR_ID)
ORDER  BY 1
/
