CREATE TABLE EC_Basket(
Order_No     VARCHAR2(10)  PRIMARY KEY,
Order_ID     VARCHAR2(10)  NOT NULL  CONSTRAINT EC_Basket_fk1
                                     REFERENCES EC_Member,
Product_Code VARCHAR2(10)  NOT NULL  CONSTRAINT EC_Basket_fk2
                                     REFERENCES EC_Product,
Order_Qty    NUMBER(3)     NOT NULL,
Order_Date   DATE          DEFAULT SYSDATE)
/
