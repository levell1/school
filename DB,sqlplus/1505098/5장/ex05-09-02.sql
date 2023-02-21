CREATE TABLE Course (
Course_ID     VARCHAR2(5)      PRIMARY KEY,
Title         VARCHAR2(20),
C_Number      NUMBER(1)        NOT NULL,
Professor_ID  VARCHAR2(3)      CONSTRAINT Student_fk
                               REFERENCES Professor )
/
