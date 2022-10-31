*-- Keep a log of any SQL queries you execute as you solve the mystery.

-- -- Descriptions of the crime happened at the given location and time.
SELECT description FROM crime_scene_reports 
    WHERE street LIKE "Humphrey Street"
        AND day = 28 AND month = 7;

-- Checking the interviews that took place the theft day!
SELECT * FROM interviews 
WHERE transcript LIKE "%bakery%"
AND day>=28 AND month >= 7 AND year>=2021;

-- The thief drove away in a car from the bakery, within 10 minutes from the theft.
SELECT name FROM people
JOIN bakery_security_logs ON 
bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 
AND hour = 10 AND minute >= 15 AND minute <= 25
AND activity = "exit";

-- One of those who uses this specific ATM are suspected to be the thief. 
SELECT name FROM people
JOIN bank_accounts ON
bank_accounts.person_id = people.id
JOIN atm_transactions ON
atm_transactions.account_number = bank_accounts.account_number 
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.transaction_type = 'withdraw';

-- Suspcets : The thief is one of the callers
SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND phone_calls.duration <= 60;


-- Which City they traveled to !
SELECT DISTINCT city FROM airports
WHERE id = 
(SELECT destination_airport_id FROM flights
WHERE origin_airport_id = 
(SELECT id FROM airports WHERE full_name LIKE "%fiftyville%") 
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour,minute LIMIT 1);

-- At 8:20, we got the first flight to New York City, One of the passengers could be the thief
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;

 -- One of those wo get phoned during this period, is the accomplice that helped the thief!
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;