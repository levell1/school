SELECT ORDER_ID,  PRODUCT_CODE, TO_CHAR(CMONEY,'9999999') "�����ݾ�",
       CDATE "��������",
       CASE WHEN GUBUN ='����' THEN '����غ�'
 	    WHEN GUBUN ='�̰�' THEN '�������'
 	    WHEN GUBUN ='���' THEN '��ǰ'
			ELSE '���'
	END "ó������"
FROM	EC_ORDER
WHERE	GUBUN != '���'
/
