SELECT UNIQUE Order_ID "�ֹ��� ID",
       SUM(CMoney) "�����հ�"
FROM   EC_ORDER
GROUP  BY Order_ID
/
