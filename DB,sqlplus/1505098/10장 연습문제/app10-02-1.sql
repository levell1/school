SELECT M.NAME, M.TELEPHONE,M.ADDRESS,P.PRODUCT_NAME "배달상품",O.ORDER_QTY"수량"
FROM   EC_ORDER O,EC_PRODUCT P,EC_MEMBER M
WHERE  O.Product_Code = P.Product_Code
AND    O.ORDER_ID = M.USERID
AND    O.GUBUN ='결제'
ORDER  BY 1
/
