SELECT UNIQUE CURRENT_DATE "��������", I_DATE "��������",
       EXTRACT(YEAR  FROM I_DATE) "���г⵵",
       EXTRACT(MONTH FROM I_DATE) "���п�",
       EXTRACT(DAY   FROM I_DATE) "������"
FROM   Student
WHERE  I_DATE IS NOT NULL
ORDER  BY 2
/
