SELECT Name, Dept_ID, ( SELECT COUNT(Dept_ID)
                        FROM   Professor A
                        WHERE  A.Dept_ID = B.Dept_ID
                        GROUP  BY Dept_ID) "학과교수 수"
FROM   Professor B
WHERE  Professor_ID = 'P12'
/
