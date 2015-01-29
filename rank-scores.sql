# Write your MySQL query statement below
select Score,(select count(EN.Score) from (select distinct Score from Scores) as EN where EN.Score >= OU.Score) as Rank from Scores as OU order by Score Desc
