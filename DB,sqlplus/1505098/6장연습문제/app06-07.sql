SELECT Product_Code, Product_Name, Unit_Price, Left_Qty, Company
FROM   EC_Product
WHERE  Unit_Price BETWEEN 300000 AND 500000
ORDER  BY 3 DESC
/
