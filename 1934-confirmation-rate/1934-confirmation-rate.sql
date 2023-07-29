# Write your MySQL query statement below
with cte1 as
(
select s.user_id,
count(*) over (partition by s.user_id) as total,
sum(action="confirmed") over (partition by s.user_id) as confirmed,
row_number() over (partition by s.user_id) as rowx
from signups s left join confirmations c on s.user_id=c.user_id
)

select user_id,
case when confirmed is NULL then round(0.0,2)
else round(confirmed/total,2) 
end as confirmation_rate 
from cte1 where rowx=1