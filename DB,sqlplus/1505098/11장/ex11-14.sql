SELECT *
FROM   ( SELECT Dept_ID, Position
         FROM   Professor )
PIVOT  (
        COUNT(*)
        FOR Position IN('����','����','�α���','������','�ʺ�����')
)
ORDER BY Dept_ID
/
