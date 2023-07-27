# Write your MySQL query statement below
with cte1 as
(select *,row_number() over (partition by customer_id order by order_date,customer_pref_delivery_date) as extra from delivery)

select round(sum(case when order_date=customer_pref_delivery_date then 1
           else 0 end)/count(*)*100,2) as immediate_percentage from cte1 where extra=1;