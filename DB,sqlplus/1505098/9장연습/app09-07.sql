SELECT CASE GROUPING_ID(ORDER_ID,Product_Code)  WHEN 0 THEN ORDER_ID
    						WHEN 1 THEN NULL
    						WHEN 2 THEN '상품 집계'
     						WHEN 3 THEN '전체 합계'
 			END "주문자_ID",
 	CASE GROUPING_ID(ORDER_ID,Product_Code) WHEN 0 THEN Product_Code
   						WHEN 1 THEN '회원 집계'
   						WHEN 2 THEN Product_Code
    						WHEN 3 THEN NULL
 			END "주문상품"  , SUM(CMoney) "결제금액"
FROM  EC_ORDER
WHERE SUBSTR(CDATE,4,2) <= 3
GROUP BY CUBE(ORDER_ID,Product_Code)
ORDER BY ORDER_ID
/
