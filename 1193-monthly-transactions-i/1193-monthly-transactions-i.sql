
with cte as
(
select 
substring(trans_date,1,7) as month,
country,
count(amount) over (partition by substring(trans_date,1,7),country) as trans_count,
sum(state='approved') over (partition by substring(trans_date,1,7),country) as approved_count, 
sum(amount) over (partition by substring(trans_date,1,7),country) as trans_total_amount,
sum(case when state="approved" then amount else 0 end) over(partition by substring(trans_date,1,7),country) as approved_total_amount 
from transactions
),

cte2 as
(select *,row_number() over (partition by month,country,trans_count,approved_count,trans_total_amount,approved_total_amount) as X from cte)

select month,country,trans_count,approved_count,trans_total_amount,approved_total_amount from cte2 where X=1;

# select substring(trans_date,1,7) as month,
# country,
# count(amount) as trans_count,
# sum(state='approved') as approved_count,
# sum(amount) as trans_total_amount,
# sum(case when state='approved' then amount
#     else 0
#     end) as approved_total_amount
# from transactions group by substring(trans_date,1,7),country;
