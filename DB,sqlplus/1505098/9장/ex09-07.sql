SELECT   DEPT_ID
FROM     PROFESSOR
GROUP BY DEPT_ID
HAVING   COUNT(*) = 1
/
