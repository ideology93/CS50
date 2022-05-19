SELECT DISTINCT(movies.title)
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
where name in ('Helena Bonham Carter', 'Johnny Depp')
GROUP BY title
HAVING COUNT(movies.id) > 1