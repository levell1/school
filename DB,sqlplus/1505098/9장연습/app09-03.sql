SELECT UNIQUE Order_ID "주문자 ID",
       SUM(CMoney) "결제합계"
FROM   EC_ORDER
GROUP  BY Order_ID
/
