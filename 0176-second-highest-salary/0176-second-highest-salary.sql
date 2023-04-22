#select max(salary) as SecondHighestSalary from employee where salary < (select max(salary) from employee)  ---> will work even if second highest salary does not exist in table

#select salary as SecondHighestSalary from employee order by salary desc limit 1,1  ---> use if second highest salary is guaranteed to exist in table ( this query works for nth salary also)

# select distinct(e1.salary) as SecondHighestSalary from employee e1 where 1=
# (
#     select count(distinct(e2.salary)) from employee e2 where e1.salary<e2.salary
# )   #----> this also cant work if second highest salary doent exist  ( this works for nth salary also )

select max(salary) as SecondHighestSalary from Employee where salary< (select max(salary) from Employee); 