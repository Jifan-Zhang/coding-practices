# Time beats 87.21%

select department.name as "Department" , t2.name as "Employee", Salary from (
    select name, salary, departmentid,rk from(
        select name, salary, departmentid, dense_rank() 
        over(partition by departmentId order by salary desc ) as rk from employee ) t1 
    where rk =1
    ) t2 
join
department 

on t2.departmentId=department.id 
