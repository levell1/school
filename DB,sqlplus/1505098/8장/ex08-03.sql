SELECT Name, SUBSTR(Name,1,1), Email, INSTR(Email,'@')
FROM   Professor
ORDER  BY 1
/
