select distinct SecondHighestSalary from(
select nth_value(salary, 2) over() as SecondHighestSalary from( 
select distinct salary from employee order by salary desc) as t) as t1

#Second way
#select distinct salary as SecondHighestSalary from employee order by salary desc limit 1 offset 1 
