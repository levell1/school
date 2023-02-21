SELECT Dept_ID || '학과' || Name || ' ' || Position ||
       '의 전화번호는 '  || Telephone || '이다.'
FROM   Professor
ORDER  BY Dept_ID
/
