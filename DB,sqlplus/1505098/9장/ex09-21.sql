SELECT Student_ID, Course_ID, Score,
       RANK() OVER(ORDER BY Score DESC) "전체석차",
RANK()OVER (PARTITION BY Course_ID ORDER BY Score DESC) "과목별 석차"
FROM   SG_Scores
WHERE  Score IS NOT NULL
ORDER  BY 2,5
/
