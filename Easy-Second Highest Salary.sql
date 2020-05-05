select distinct SecondHighestSalary from(
select nth_value(salary, 2) over() as SecondHighestSalary from( 
select distinct salary from employee order by salary desc) as t) as t1