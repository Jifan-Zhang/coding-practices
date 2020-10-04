CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      select salary from(
      select salary, row_number() over(order by salary desc) as m from employee 
      group by salary) t 
      where m=N
  ) ;
END