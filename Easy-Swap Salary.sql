/*51.64%
update salary 
    set sex = case when sex = 'm' then 'f' else 'm' end 
*/

/* 58.25% */
update salary set sex = if(sex = 'm','f','m') 
