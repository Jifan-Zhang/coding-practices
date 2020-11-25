# 78.04%
select class from 
    (select distinct class, student from courses)as t 
group by class having count(class) >= 5