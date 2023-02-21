SELECT *
FROM   ( SELECT Dept_ID, Position
         FROM   Professor )
PIVOT  (
        COUNT(*)
        FOR Position IN('총장','교수','부교수','조교수','초빙교수')
)
ORDER BY Dept_ID
/
