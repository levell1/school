CREATE INDEX STUDENT_BIRTH_INX
ON     Student(Substr(ID_NUMBER,1,6))
/
