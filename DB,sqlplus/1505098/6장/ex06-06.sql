SELECT  Course_ID, Title "�����", C_Number "����",
        C_Number * 30000 + NVL(Course_Fees,0) "���� ������"
FROM    Course
ORDER   BY 4 DESC, Course_ID	ASC
/
