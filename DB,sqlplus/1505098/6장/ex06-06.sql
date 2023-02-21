SELECT  Course_ID, Title "과목명", C_Number "학점",
        C_Number * 30000 + NVL(Course_Fees,0) "과목별 수강료"
FROM    Course
ORDER   BY 4 DESC, Course_ID	ASC
/
