CREATE TABLE Professor(
Professor_ID VARCHAR2(3)  PRIMARY KEY,
Name         VARCHAR2(20) NOT NULL,
Position     VARCHAR2(10) NOT NULL    CONSTRAINT Professor_ck
  CHECK (Position  in ('����','�α���','������','�ʺ�����')),
Telephone    VARCHAR2(12) CONSTRAINT Professor_uk UNIQUE)
/
