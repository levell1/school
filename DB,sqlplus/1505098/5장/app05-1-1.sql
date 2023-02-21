CREATE TABLE EC_Product	(
Product_Code   VARCHAR2(10)   PRIMARY KEY,
Product_Name   VARCHAR2(20)   NOT NULL,
Standard       VARCHAR2(20),
Unit           VARCHAR2(10),
Unit_Price     NUMBER(7)      NOT NULL,
Left_Qty       NUMBER(5)      NOT NULL,
Company        VARCHAR2(20),
ImageName      VARCHAR2(20),
Info           VARCHAR2(50),
Detail_Info    VARCHAR2(255))
/
