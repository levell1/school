SELECT SUBSTR(Address,1,2) "시도별", COUNT(*) "인원수"
FROM   EC_Member
GROUP  BY ROLLUP(SUBSTR(Address,1,2))
/
