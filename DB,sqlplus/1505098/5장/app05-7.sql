ALTER TABLE EC_Order
ADD CONSTRAINT EC_Order_fk FOREIGN KEY (Product_Code)
                           REFERENCES EC_Product
/
