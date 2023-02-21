CREATE TABLE Professor(
Professor_ID VARCHAR2(3)  PRIMARY KEY,
Name         VARCHAR2(20) NOT NULL,
Position     VARCHAR2(10) NOT NULL    CONSTRAINT Professor_ck
  CHECK (Position  in ('교슈','부교수','조교수','초빙교수')),
Telephone    VARCHAR2(12) CONSTRAINT Professor_uk UNIQUE)
/
