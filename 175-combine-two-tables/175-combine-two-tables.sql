# Write your MySQL query statement below
select p.firstName,p.lastName,c.city,c.state from Person as p LEFT JOIN Address as c on p.personId=c.personId;