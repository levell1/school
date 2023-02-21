SELECT Dept_ID, Professor_ID, Name, Position
FROM   Professor
WHERE  Dept_ID NOT IN ('컴공','정통')
ORDER  BY Dept_ID
/
