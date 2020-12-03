/* 67%

select case 
    when id = (select max(id) from seat) and  id%2=1 then id
    when id%2 = 1 then id +1 
    when id%2 = 0 then id - 1
end as id, student

from seat
order by id
*/



SET @var_name = (select max(id) from seat);
select student, case 
    when id = @var_name and id%2=1 then id
    when id%2 = 1 then id +1 
    when id%2 = 0 then id -1
    else null
end as id
from seat
order by id;