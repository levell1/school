SELECT COURSE_FEES, TO_CHAR(COURSE_FEES, 'L999,999') "������ȭ��",
       TO_CHAR(COURSE_FEES, 'C999G999') "ISO ȭ��"
FROM   COURSE
WHERE  COURSE_FEES = 40000
/
