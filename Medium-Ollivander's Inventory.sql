select id,age,coins,t3.power 
from(
    select Wands.code as cd,age, min(coins_needed) as coins,power from Wands 
        join (select age,code from Wands_Property where is_evil=0) as t1 using(code)
    group by age,power,cd
) as t3 join Wands on (t3.cd=Wands.code and t3.coins=Wands.coins_needed and t3.power=Wands.power)

order by power desc,age desc