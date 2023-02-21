UPDATE Course
SET    Course_Fees = Course_Fees - 5000
WHERE  Course_Fees > ( SELECT AVG(COURSE_Fees)
                       FROM   Course )
/
