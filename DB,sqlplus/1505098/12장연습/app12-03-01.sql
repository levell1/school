INSERT INTO EC_Basket
(Order_No, Order_ID, Product_Code, Order_Qty, Order_Date)
VALUES
(CONCAT(TO_CHAR(SYSDATE,'YYMMDD'),TO_CHAR(Order_Seq.NEXTVAL)), '&�ֹ���ID', '&��ǰ�ڵ�', '&�ֹ�����', SYSDATE)
/
