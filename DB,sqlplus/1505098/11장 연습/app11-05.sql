SELECT USERID,NAME,REGIST_NO, TELEPHONE
FROM   EC_MEMBER M
WHERE  NOT EXISTS  ( SELECT *
		FROM   EC_ORDER O
		WHERE	M.USERID =O.ORDER_ID)
ORDER 	BY 2
/
