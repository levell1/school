CREATE TABLE Professor (
Professor_ID  VARCHAR2(3)    PRIMARY KEY,
Name          VARCHAR2(20)   NOT NULL,
Position      VARCHAR2(10)   NOT NULL     CONSTRAINT Professor_ck
   CHECK (Position IN ('����','�α���','������','�ʺ�����')),
Dept_ID                      CONSTRAINT Professor_fk
                             REFERENCES Department,
Telephone     VARCHAR2(12)   CONSTRAINT Professor_uk UNIQUE )
/
