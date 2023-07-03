# Write your MySQL query statement below

# select t1.machine_id,round(avg(t2.timestamp-t1.timestamp),3) as processing_time
# from activity t1 join activity t2 
# on 
# t1.machine_id=t2.machine_id 
# and 
# t1.process_id=t2.process_id 
# and 
# t1.activity_type='start' 
# and 
# t2.activity_type='end' 
# group by t1.machine_id;

SELECT s.machine_id, ROUND(AVG(e.timestamp-s.timestamp), 3) AS processing_time
FROM Activity s JOIN Activity e ON
    s.machine_id = e.machine_id AND s.process_id = e.process_id AND
    s.activity_type = 'start' AND e.activity_type = 'end'
GROUP BY s.machine_id