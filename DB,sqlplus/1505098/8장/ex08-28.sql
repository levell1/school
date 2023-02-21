SELECT SCORE,TO_CHAR(Score, 'S999'), TO_CHAR(-Score, '999'),
             TO_CHAR(SCORE,'B999.9'), TO_CHAR(SCORE, '099.99')
FROM   SG_SCORES
WHERE  SCORE >= 98
ORDER BY 1 DESC
/
