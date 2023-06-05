cant use group by when joining 2 tables
only use group by if using aggregate function in same table itself# select dname as Department, ename as Employee, esalary as Salary from
# (select e.id as eid,e.name as ename,e.salary as esalary,e.departmentId as edid,d.id as did,d.name as dname from Employee e inner join Department d on e.departmentId=d.id) as E where (did,esalary) in (select departmentId,max(salary) from employee group by departmentId);
select department.name as Department,E.name as Employee,E.salary as Salary from
(select *,max(salary) over(partition by departmentId) as maxi from Employee) as E inner join department on E.departmentId=department.id where E.maxi=E.salary;