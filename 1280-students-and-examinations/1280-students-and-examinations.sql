# Write your MySQL query statement below
with t1 as
(select * from students cross join subjects)

,t2 as
(select student_id,subject_name,count(subject_name) as ctr from examinations group by student_id,subject_name)

select t1.student_id,
t1.student_name,
t1.subject_name,
case when t2.ctr is not null then t2.ctr
else 0 end 
as attended_exams
from t1 left join t2 on 
t1.student_id=t2.student_id and t1.subject_name=t2.subject_name 
order by t1.student_id,t1.subject_name;