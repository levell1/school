SELECT Order_No, Order_ID, Product_Code, Csel, Gubun
FROM   EC_Order
WHERE  Csel !='신용카드' AND Gubun ='배달'
ORDER  BY 2
/
