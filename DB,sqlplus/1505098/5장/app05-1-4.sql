CREATE TABLE EC_Order(
Order_No   	VARCHAR2(10) PRIMARY KEY,
Order_ID   	VARCHAR2(10) NOT NULL,
Product_Code 	VARCHAR2(10) NOT NULL,
Order_Qty    	NUMBER(3)    NOT NULL,
Csel        	VARCHAR(10),
CMoney      	NUMBER(9),
Cdate       	DATE,
Mdate       	DATE,
Gubun       	VARCHAR(10))
/
