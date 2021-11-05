-- write a SQL query that lists the names of songs that are by Post Malone.
-- Your query should output a table with a single column for the name of each song.
-- You should not make any assumptions about what Post Malone’s artist_id is

SELECT songs.name FROM songs INNER JOIN artists ON artists.id = songs.artist_id WHERE artists.name LIKE "%Post Malone%"