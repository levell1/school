SELECT*
FROM(SELECT ROWNUM num, a.*
FROM   (SELECT PRODUCT_CODE,PRODUCT_NAME,UNIT_PRICE,COMPANY
 FROM   EC_PRODUCT
 WHERE  UNIT_PRICE IS NOT NULL
 ORDER  BY 3 DESC) a
	)
WHERE num BETWEEN 11 AND 15
/
