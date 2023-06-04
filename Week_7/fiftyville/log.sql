-- Keep a log of any SQL queries you execute as you solve the mystery.
--starting from crime_scene_reports/ date is July 28, 2021
SELECT description FROM crime_scene_reports WHERE year=2021 AND day=28 AND street='Hum
phrey Street' AND month=7;
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
--Littering took place at 16:36. No known witnesses.
--checking names of the interviewers and transcripts from table interviews
SELECT name,transcript FROM interviews WHERE year=2021 AND day=28 AND month = 7;
--| Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
--| Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
--| Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

--checking bakery_security_logs
SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND day=28 AND month = 7 AND hour<16 AND activity='exit';
SELECT name,phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND day=28 AND month = 7 AND hour<16 AND activity='exit');
SELECT caller,receiver,duration FROM phone_calls WHERE year=2021 AND day=28 AND month = 7 AND duration <=60;
--callers, less than 60 seconds
--Sofia   | (130) 555-0289
--Kelsey  | (499) 555-9472
--Bruce   | (367) 555-5533
--Taylor  | (286) 555-6063
--Diana   | (770) 555-1861
SELECT account_number FROM atm_transactions WHERE year=2021 AND day=28 AND month = 7 AND transaction_type='withdraw' AND atm_location='Leggett Street';
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year=2021 AND day=28 AND month = 7 AND transaction_type='withdraw' AND atm_location='Leggett Street');
--Bruce receiver (375) 555-8161 Robin
--Diana receiver (725) 555-3243 Philip
--Taylor receiver (676) 555-6554 James
SELECT name,phone_number FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year=2021 AND day=28 A
ND month = 7 AND duration <=60);
--Robin      | (375) 555-8161
--Philip     | (725) 555-3243
--James      | (676) 555-6554
SELECT full_name,abbreviation FROM airports;
SELECT full_name,abbreviation FROM airports JOIN flights ON airports.id=flights.origin_airport_id WHERE full_name='Fiftyville Regional Airport' AND year=2021 AND day=29 AND month = 7;
SELECT passport_number FROM passengers JOIN flights ON passengers.flight_id=flights.id;
SELECT id FROM flights WHERE origin_airport_id IN (SELECT airports.id FROM airports JOIN flights ON airports.id=flights.origin_airport_id WHERE full_name='Fiftyville Regional Airport' AND year=2021 AND day=29 AND month = 7);
SELECT passport_number FROM passengers JOIN flights ON passengers.flight_id=flights.id WHERE flights.id IN (SELECT id FROM flights WHERE origin_airport_id IN (SELECT airports.id FROM airports JOIN flights ON airports.id=flights.origin_airport_id WHERE full_name='Fiftyville Regional Airport' AND year=2021 AND day=29 AND month = 7));
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers JOIN flights ON passengers.flight_id=flights.id WHERE flights.id IN (SELECT id FROM flights WHERE origin_airport_id IN (SELECT airports.id FROM airports JOIN flights ON airports.id=flights.origin_airport_id WHERE full_name='Fiftyville Regional Airport' AND year=2021 AND day=29 AND month = 7))) ORDER BY name ASC;
--license plate
--| Bruce     | 94KL13X
--Diana     | 322W7JE
--Taylor    | 1106N58
SELECT id,hour,minute FROM flights WHERE origin_airport_id IN (SELECT airports.id FROM airports JOIN flights ON airports.id=flights.origin_airport_id WHERE full_name='Fiftyville Regional Airport' AND year=2021 AND day=29 AND month = 7) ORDER BY hour ASC;
--7.16 is the earliest flight flight id:30 ...id 36 -departure 8:20
--Bruce was that one who left the earliest
SELECT full_name FROM airports JOIN flights ON airports.id=flights.destination_airport_id WHERE flights.id=36;
--LaGuardia Airport
