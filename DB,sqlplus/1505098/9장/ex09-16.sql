SELECT UNIQUE COURSE_ID,
       COUNT(*) OVER( PARTITION BY COURSE_ID) " 학생수",
       AVG(SCORE) OVER(PARTITION BY COURSE_ID) "과목별 평균"
FROM   SG_SCORES
ORDER  BY 1
/
