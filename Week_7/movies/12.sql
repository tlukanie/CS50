--SELECT movies.title FROM movies JOIN ratings ON ratings.movie_id = movies.id, stars ON stars.movie_id = movies.id, people ON stars.person_id= people.id WHERE people.name IN ('Helena Bonham Carter','Johnny Depp');
SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = 'Johnny Depp' AND movies.title IN(
SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = 'Helena Bonham Carter');