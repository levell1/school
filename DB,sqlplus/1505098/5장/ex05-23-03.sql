ALTER TABLE Course
ADD   CONSTRAINT Course_fk
      FOREIGN KEY (Professor_ID) REFERENCES Professor
/
