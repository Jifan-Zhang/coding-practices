# 58.57%
select Request_at as "Day", round(sum(tmp)/count(id),2) as "Cancellation Rate"
from (
select *,case
when t.Status like "%cancel%" then 1
when t.Status = "completed" then 0 
end as tmp
from (select * from Trips where client_id not in (select users_id from users where banned="Yes"))t
)t2
group by Request_at
having Request_at >= "2013-10-01" and
    Request_at <= "2013-10-03"