INSERT INTO EC_Basket
(Order_No, Order_ID, Product_Code, Order_Qty, Order_Date)
VALUES
(CONCAT(TO_CHAR(SYSDATE,'YYMMDD'),TO_CHAR(Order_Seq.NEXTVAL)), '&주문자ID', '&상품코드', '&주문수량', SYSDATE)
/
