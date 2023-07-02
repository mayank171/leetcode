# Write your MySQL query statement below
select name from
(
select * from customer 
except
select * from customer where referee_id=2) as A;