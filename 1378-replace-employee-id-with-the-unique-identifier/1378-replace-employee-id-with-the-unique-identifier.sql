# Write your MySQL query statement belowselct

select EmployeeUNI.unique_id, Employees.name from employees
left join EmployeeUNI on Employees.id=EmployeeUNI.id;