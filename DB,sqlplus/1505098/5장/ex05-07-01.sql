CREATE TABLE Student (
Dept_ID     VARCHAR2(10),
Year        VARCHAR2(1),
Student_ID  VARCHAR2(7),
Name        VARCHAR2(20)     NOT NULL,
ID_Number   VARCHAR2(14)     NOT NULL,
Address     VARCHAR2(40),
CONSTRAINT  Student_pk       	PRIMARY KEY (Student_ID),
CONSTRAINT  Student_DeptID_fk	FOREIGN KEY (Dept_ID)
            REFERENCES   	Department(Dept_ID))
/
