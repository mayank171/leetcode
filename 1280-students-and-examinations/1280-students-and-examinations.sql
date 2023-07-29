# Write your MySQL query statement below
with cte1 as
(select * from students cross join subjects order by students.student_id),

cte2 as
(select *,count(*) as attended_exams from examinations group by student_id,subject_name)

select cte1.student_id,cte1.student_name,cte1.subject_name,
case when cte2.attended_exams is NULL then 0 
else cte2.attended_exams end as attended_exams
from cte1 left join cte2 on cte1.student_id=cte2.student_id and cte1.subject_name=cte2.subject_name order by student_id,subject_name;