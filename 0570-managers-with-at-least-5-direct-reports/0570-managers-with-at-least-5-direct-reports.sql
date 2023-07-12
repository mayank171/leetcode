# Write your MySQL query statement below

select name from Employee where id in
(select managerId as ctr from employee group by managerId having(count(managerId)>=5)) ;