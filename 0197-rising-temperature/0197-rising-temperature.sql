# Write your MySQL query statement below
select distinct(t1.id) from weather t1 join weather t2 on  TO_DAYS(t1.recordDate)-TO_DAYS(t2.recordDate)=1 and t1.temperature>t2.temperature;