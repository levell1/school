SELECT Student_ID, Course_ID, Score,
       RANK() OVER(ORDER BY Score DESC) "��ü����",
RANK()OVER (PARTITION BY Course_ID ORDER BY Score DESC) "���� ����"
FROM   SG_Scores
WHERE  Score IS NOT NULL
ORDER  BY 2,5
/
