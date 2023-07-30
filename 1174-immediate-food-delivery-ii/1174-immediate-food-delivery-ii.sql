# Write your MySQL query statement below
with cte1 as
(select * from delivery order by customer_id,order_date),

cte2 as
(select *,row_number() over (partition by customer_id order by order_date) as X from cte1)

select 
round(sum(case when order_date=customer_pref_delivery_date then 1 else 0 end)/count(*)*100,2) as immediate_percentage 
from cte2 where X=1;