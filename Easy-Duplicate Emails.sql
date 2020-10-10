# (1)
select distinct Email from person as t1 join person as t2 using(Email)
where t1.id != t2.id

# (2)
select distinct Email from person as t1 join person as t2 using(Email)
where t1.id < t2.id
