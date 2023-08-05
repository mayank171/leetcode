
select activity_date as day,count(distinct(user_id)) as active_users from activity group by activity_date having datediff("2019-07-27",activity_date) between 0 and 29