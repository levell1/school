SELECT Student_ID, SUM(C_Number)
FROM   SG_Scores INNER JOIN Course USING (Course_ID)
GROUP  BY Student_ID
HAVING SUM(C_Number) >
       ( SELECT SUM(C_Number)
         FROM   SG_Scores INNER JOIN Course USING (Course_ID)
         WHERE  Student_ID = 'C1602')
/
