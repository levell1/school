SELECT ORDER_ID,  PRODUCT_CODE, TO_CHAR(CMONEY,'9999999') "결제금액",
       CDATE "결제일자",
       CASE WHEN GUBUN ='결제' THEN '배달준비'
 	    WHEN GUBUN ='미결' THEN '결제대기'
 	    WHEN GUBUN ='취소' THEN '반품'
			ELSE '대기'
	END "처리내용"
FROM	EC_ORDER
WHERE	GUBUN != '배달'
/
