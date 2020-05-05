/* MS SQL Server code*/

SELECT MAX(Doctor),MAX(Professor),MAX(Singer),MAX(Actor) from
(SELECT 
    CASE WHEN Occupation = 'Doctor' THEN name END AS Doctor , 
    CASE WHEN Occupation = 'Professor' THEN name END AS Professor , 
    CASE WHEN Occupation = 'Singer' THEN name END AS Singer , 
    CASE WHEN Occupation = 'Actor' THEN name END AS Actor , 
    RANK() OVER(PARTITION BY Occupation ORDER BY name) AS row_rank
FROM Occupations
) AS t
GROUP BY row_rank