# Write your MySQL query statement belowselct

select EmployeeUNI.unique_id, Employees.name from   EmployeeUNI 
right join  employees on Employees.id=EmployeeUNI.id;