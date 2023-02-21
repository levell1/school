SELECT NAME, REGIST_NO,
       DECODE(SUBSTR(REGIST_NO,8,1), '1','남자', '2','여자'
				   , '3','남자', '4','여자')"성별"
FROM   EC_Member
ORDER  BY 3
/
