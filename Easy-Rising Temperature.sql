# 88%
select id from(
select id, temperature, recorddate, 
lag(temperature,1) over() as lg,
lag(recordDate,1) over() as lgd
from weather order by recordDate) t 
where temperature > lg and datediff(recordDate,lgd)=1*/

/* 8%
select w1.id as "Id" from weather w1,weather w2 where datediff(w1.recordDate,w2.recordDate)=1 and w1.temperature>w2.temperature*/

/* 12.86%
select w1.id as "Id" from weather w1 join weather w2 on w1.temperature>w2.temperature and datediff(w1.recordDate,w2.recordDate)=1 */

