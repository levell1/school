SELECT NAME, REGIST_NO,
       DECODE(SUBSTR(REGIST_NO,8,1), '1','����', '2','����'
				   , '3','����', '4','����')"����"
FROM   EC_Member
ORDER  BY 3
/
