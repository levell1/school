CREATE TABLE Student (
Dept_ID     VARCHAR2(10)     CONSTRAINT Student_DeptID_fk
                             REFERENCES Department,
Year        VARCHAR2(1),
Student_ID  VARCHAR2(7)      PRIMARY KEY,
Name        VARCHAR2(20)     NOT NULL,
ID_Number   VARCHAR2(14)     NOT NULL,
Address     VARCHAR2(40) )
/
