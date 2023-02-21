CREATE TABLE Professor (
Professor_ID  VARCHAR2(3)    PRIMARY KEY,
Name          VARCHAR2(20)   NOT NULL,
Position      VARCHAR2(10)   NOT NULL,
Dept_ID                      CONSTRAINT  Professor_fk
                             REFERENCES  Department
                             ON DELETE   CASCADE,
Telephone     VARCHAR2(12)  )
/
