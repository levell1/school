SELECT NAME, REGIST_NO,
	DECODE(SUBSTR(REGIST_NO,8,1),   '1',TO_CHAR(SYSDATE, 'RRRR')-LPAD(TO_CHAR(SUBSTR(REGIST_NO,1,2)),4,'19'),
					'2',TO_CHAR(SYSDATE, 'RRRR')-LPAD(TO_CHAR(SUBSTR(REGIST_NO,1,2)),4,'19'),
					'3',TO_CHAR(SYSDATE, 'RRRR')-LPAD(TO_CHAR(SUBSTR(REGIST_NO,1,2)),4,'20'),
					'4',TO_CHAR(SYSDATE, 'RRRR')-LPAD(TO_CHAR(SUBSTR(REGIST_NO,1,2)),4,'20'))	"나이",
					TO_CHAR(SYSDATE, 'DS') "기준년월일"
FROM   EC_Member
ORDER  BY 3
/
