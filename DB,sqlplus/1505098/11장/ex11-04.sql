SELECT STUDENT_ID, COURSE_ID,SCORE, TO_CHAR(SCORE_ASSIGNED,'YY/MM') "�����"
FROM   SG_SCORES
WHERE  (TO_CHAR(SCORE_ASSIGNED, 'YY/MM'),SCORE) IN
	(SELECT TO_CHAR(SCORE_ASSIGNED, 'YY/MM'), MAX(SCORE)
	FROM	SG_SCORES
	GROUP	BY	TO_CHAR(SCORE_ASSIGNED, 'YY/MM'))
ORDER	BY 4
/
