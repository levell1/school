SELECT SUBSTR(Address,1,2) "�õ���", COUNT(*) "�ο���"
FROM   EC_Member
GROUP  BY ROLLUP(SUBSTR(Address,1,2))
/
