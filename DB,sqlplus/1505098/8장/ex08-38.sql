SELECT Dept_ID, Position, Name, Duty
FROM   Professor
ORDER  BY CASE Position WHEN '총장'   THEN 1
			WHEN '교수'   THEN 2
			WHEN '부교수' THEN 3
			WHEN '조교수' THEN 4
		END, Dept_ID
/
