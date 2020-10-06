Time beats 86.83%, Memory beats 100%.
select department.name as "Department",t.name as "Employee", Salary from   
    (
        select salary,employee.name as "name",departmentid ,
    dense_rank() over(partition by departmentid order by salary desc) as "rank" 
    from employee
    ) t
  join 
    Department
  on t.departmentid = Department.Id
where t.rank<=3