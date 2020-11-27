# 98.22%

# Write your MySQL query statement below

select id, visit_date, people from(
    select *, count(greater) over (partition by greater) as ct from (
    select *, id - row_number() over (partition by people>=100) as greater from Stadium) as t
    where people>=100
) as t2
where ct >=3