CREATE OR REPLACE FUNCTION  Grade_Cal(Score Number)
 RETURN  CHAR IS
 v_Grade CHAR(2);
BEGIN
 IF Score >=95      THEN v_Grade := 'A+';
	ELSIF Score >=90      	THEN v_Grade := 'A+';
	ELSIF Score >=85      	THEN v_Grade := 'A+';
	ELSIF Score >=80      	THEN v_Grade := 'A+';
	ELSIF Score >=75      	THEN v_Grade := 'A+';
	ELSIF Score >=70      	THEN v_Grade := 'A+';
	ELSIF Score >=65      	THEN v_Grade := 'A+';
	ELSIF Score >=60      	THEN v_Grade := 'A+';
				ELSE v_Grade := 'F ';
	END IF;
	RETURN	v_Grade;
END;
/
