/**********************************************************
*  테이블 삭제
***********************************************************/
DROP TABLE SG_Scores	purge;
DROP TABLE Student	purge;
DROP TABLE Course	purge;
DROP TABLE Professor	purge;
DROP TABLE Department	purge;
DROP TABLE T_Course	purge;
DROP TABLE T_SG_Scores	purge;
DROP TABLE Score_Grade	purge;

SELECT * FROM USER_CATALOG
/
