-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get the information of the crime
SELECT id, description FROM crime_scene_reports WHERE year = "2020" AND month = "7" AND day = "28" AND street = "Chamberlin Street";

--id | description
--295 | Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- Get the interview transcripts
SELECT id, name, transcript FROM interviews WHERE year = "2020" AND month = "7" AND day = "28" AND transcript LIKE "%courthouse%";

/*
id | name | transcript
161 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
162 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
163 | Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/

-- Show all fligths from fiftyville on 29/7 the first one is the one of th thief. Here we obtain id of flight and destination airport (City they left)
SELECT flights.id, hour, minute, destination_airport_id FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE flights.day = 29 AND flights.month =7 AND flights.year = 2020
AND airports.city="Fiftyville"
ORDER BY hour, minute
LIMIT 1;
/*
id | hour | minute | destination_airport_id
36 | 8 | 20 | 4
*/

-- See the city of first flight -> City they run away
SELECT city FROM airports WHERE id = 4;
-- London
--
-- Same result doing this if ID is unknown
/*
SELECT city FROM airports
WHERE id IN
(SELECT destination_airport_id FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE flights.day = 29 AND flights.month =7 AND flights.year = 2020 AND airports.city="Fiftyville"
ORDER BY hour
LIMIT 1);
*/

-- Names of the passengers who where at the parking lot between 10:15hs & 10:25hs and exiting courthouse;
-- fly to London;
-- withdraw money from atm in Fifer St.;
-- call someone for less than 60 sec.
-- Is the thief

SELECT DISTINCT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN phone_calls ON caller = people.phone_number
WHERE flight_id = 36 -- ID of flight to London
AND courthouse_security_logs.day = 28
AND courthouse_security_logs.month = 7
AND courthouse_security_logs.year = 2020
AND courthouse_security_logs.hour = 10
AND courthouse_security_logs.minute > 15
AND courthouse_security_logs.minute < 25
AND courthouse_security_logs.activity = "exit"
AND transaction_type LIKE "withdraw"
AND atm_location LIKE "%Fifer Street%"
AND duration <60;

/*
name
Ernest
*/


-- Name of the person accomplice, who Ernest call that day for less than 1 minute
SELECT DISTINCT name FROM people
JOIN phone_calls ON receiver = people.phone_number
WHERE caller IN
(SELECT phone_number FROM people WHERE name = "Ernest")
AND day = 28 AND month = 7 AND year = 2020
AND duration<60
ORDER BY duration;
/*
name
Berthold
*/


