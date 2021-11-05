-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.

SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Johnny Depp" OR people.name = "Helena Bonham Carter"
-- Until here the code generates a row with all the movies where either Depp or Carter starred
-- With GROUP BY the program groups the rows with same value (titles) into summary rows (one row per title) counting +1 every time the tilte appears
GROUP BY title
-- If the title appear more than once then both actor starred in it
HAVING COUNT(title) > 1;