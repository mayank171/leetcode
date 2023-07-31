# Write your MySQL query statement below
with cte1 as
(select * from activity where datediff("2019-07-27",activity_date)>=0 and datediff("2019-07-27",activity_date)<=29)

select activity_date as day, count(distinct(user_id)) as active_users from cte1 group by activity_date;