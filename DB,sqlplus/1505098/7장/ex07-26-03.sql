MERGE INTO  Course C
      USING T_Course T
      ON    ( C.Course_ID = T.Course_ID)
WHEN  MATCHED THEN
      UPDATE
      SET   C.Title = T.Title, C.Course_Fees = T.Course_Fees
WHEN  NOT MATCHED THEN
      INSERT
      (Course_ID, Title, C_Number, Professor_ID, Course_Fees)
      VALUES
      (T.Course_ID, T.Title, T.C_Number, T.Professor_ID, T.Course_Fees)
/
