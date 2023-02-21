ALTER TABLE Course
MODIFY (CONSTRAINT Course_fk FOREIGN KEY (Professor_ID)
                   REFERENCES Professor
                   ON DELETE CASCADE)
/
