SELECT Professor_ID,Name,Position,Telephone,
       LPAD(Telephone, 12, '053-')
FROM   Professor
ORDER  BY 1
/
