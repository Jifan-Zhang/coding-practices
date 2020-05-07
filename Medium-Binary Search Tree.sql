select row_number() over(order by N),
case
    when N in (select P from BST) and  (P is not null) then "Inner"
    when P is null then "Root"
    else "Leaf"
end as name
from BST

