# Time beats 88.92% RAM beats 100%
select t2.name as "Employee" from employee as t1 join employee as t2 on t2.managerid=t1.id
where t1.salary<t2.salary