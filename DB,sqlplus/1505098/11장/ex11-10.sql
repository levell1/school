SELECT M.STUDENT_ID,NAME,COUNT(*) "??????????",
       (SELECT SUM(C_NUMBER)
       FROM    SG_SCORES INNER JOIN COURSE USING (COURSE_ID)
       WHERE  STUDENT_ID = M.STUDENT_ID
       GROUP  BY  STUDENT_ID )"??????????"
FROM SG_SCORES M INNER JOIN STUDENT S ON M.STUDENT_ID = S.STUDENT_ID
GROUP	BY M. STUDENT_ID, NAME
HAVING	COUNT(*) >1
ORDER	BY	4	DESC
/
