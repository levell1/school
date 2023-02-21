SELECT *
FROM   (SELECT ROWNUM num,a.*
        FROM (SELECT Student_ID, Name, Title, C_Number, Score
            FROM SG_Scores INNER JOIN Course USING (Course_ID)
                        INNER JOIN Student USING (Student_ID)
             WHERE  Score IS NOT NULL
             ORDER BY 5 DESC, 4 DESC) a
         )
WHERE  num BETWEEN 11 AND 15
/
