SELECT Dept_ID, Position, Name, Duty
FROM   Professor
ORDER  BY CASE Position WHEN '����'   THEN 1
			WHEN '����'   THEN 2
			WHEN '�α���' THEN 3
			WHEN '������' THEN 4
		END, Dept_ID
/
