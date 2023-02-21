UPDATE Student S
SET    Course_cnt = (SELECT COUNT(*)
                     FROM   SG_SCORES SG
                     WHERE  SG.Student_ID = S.Student_ID)
/
