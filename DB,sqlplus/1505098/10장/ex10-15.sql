SELECT P.PROFESSOR_ID, NAME, POSITION, TITLE, C_NUMBER
FROM   PROFESSOR P ,COURSE C
WHERE P.PROFESSOR_ID = C.PROFESSOR_ID (+)
  AND COURSE_ID IS NULL
ORDER BY 1
/
