CREATE TABLE   SG_Scores (
Student_ID     VARCHAR2(7),
Course_ID      VARCHAR2(5),
Score          NUMBER(3),
Grade          VARCHAR2(2),
Score_Assigned DATE,
CONSTRAINT SG_Scorese_pk PRIMARY KEY (Student_ID, Course_ID))
/
