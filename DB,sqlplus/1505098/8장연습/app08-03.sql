select ORDER_ID, PRODUCT_CODE "�ֹ���ǰ", ORDER_QTY "����",
       TO_CHAR(CMONEY, 'L9,999,999') "����ݾ�",
       TO_CHAR(TO_CHAR(SYSDATE ,'DDD')+365)-TO_CHAR(CDATE,'DDD') "������ ����",
       SYSDATE "������"
FROM   EC_ORDER
WHERE  GUBUN ='����'
/
