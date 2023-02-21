select ORDER_ID, PRODUCT_CODE "주문상품", ORDER_QTY "수량",
       TO_CHAR(CMONEY, 'L9,999,999') "결재금액",
       TO_CHAR(TO_CHAR(SYSDATE ,'DDD')+365)-TO_CHAR(CDATE,'DDD') "결제후 일자",
       SYSDATE "기준일"
FROM   EC_ORDER
WHERE  GUBUN ='결제'
/
