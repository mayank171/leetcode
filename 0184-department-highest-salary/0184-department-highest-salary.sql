
select Department.name as Department, Employee.name as Employee, Employee.salary as Salary 
from Department join Employee on Department.id=employee.departmentId  
where (Employee.salary,Department.id) in 
(select max(salary),departmentId from Employee group by departmentId);