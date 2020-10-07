#Time beat 99.41%, Memory beat 100%.

select distinct num as "ConsecutiveNums" from (
select id, num, row_number() over(partition by num, id - cast(rn as signed) order by id) rn
from (
    select *, row_number() over(partition by num order by id) rn
    from logs
) t) t1
where rn >=3
