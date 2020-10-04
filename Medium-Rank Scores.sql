# Beat 96.34% in time; Beat 100% in memory 
select Score, RK as "Rank" from scores join
  (select Score, row_number() over(order by score desc) as RK from scores  group by score 
     order by score) t 
using(score)
order by RK