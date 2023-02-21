SELECT Name, Position, Dept_ID
FROM   Professor P
WHERE  EXISTS ( SELECT *
                FROM   Course C
                WHERE  P.Professor_ID = C.Professor_ID)
/