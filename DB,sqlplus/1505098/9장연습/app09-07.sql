SELECT CASE GROUPING_ID(ORDER_ID,Product_Code)  WHEN 0 THEN ORDER_ID
    						WHEN 1 THEN NULL
    						WHEN 2 THEN '��ǰ ����'
     						WHEN 3 THEN '��ü �հ�'
 			END "�ֹ���_ID",
 	CASE GROUPING_ID(ORDER_ID,Product_Code) WHEN 0 THEN Product_Code
   						WHEN 1 THEN 'ȸ�� ����'
   						WHEN 2 THEN Product_Code
    						WHEN 3 THEN NULL
 			END "�ֹ���ǰ"  , SUM(CMoney) "�����ݾ�"
FROM  EC_ORDER
WHERE SUBSTR(CDATE,4,2) <= 3
GROUP BY CUBE(ORDER_ID,Product_Code)
ORDER BY ORDER_ID
/
