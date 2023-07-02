# Write your MySQL query statement below
select t2.product_name, t1.year, t1.price from sales t1 join product t2 on t1.product_id=t2.product_id;