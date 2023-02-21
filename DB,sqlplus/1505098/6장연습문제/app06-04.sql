SELECT Order_No, Product_Code, Order_Qty, Csel, CMoney, CDate, Gubun
FROM   EC_Order
WHERE  Csel IS NOT NULL AND Gubun = '∞·¡¶'
/
