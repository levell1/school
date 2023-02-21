ALTER TABLE Professor
ADD CONSTRAINT Professor_fk FOREIGN KEY (Dept_ID)
                            REFERENCES Department
/
