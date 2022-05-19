-- Keep a log of any SQL queries you execute as you solve the mystery.
--CRIME SCENE REPORTS
SELECT * FROM crime_scene_reports WHERE day = "28" AND month  = "7" AND year = "2020" AND street = "Chamberlin Street";
id	year	month	day	street	description
295	2020	7	28	Chamberlin Street	Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
                    Interviews were conducted today with three witnesses who were present at the time —
                    each of their interview transcripts mentions the courthouse.

-- COURTHOUSE LOGS
SELECT * FROM courthouse_security_logs WHERE year = "2020" AND day = "28" AND month = "7" AND hour = "10" AND minute >= "10" AND minute <= "20"
id	year	month	day	hour	minute	activity	license_plate
259	2020	7	    28	10	    14	entrance	    13FNH73
260	2020	7	    28	10	    16	exit	        5P2BI95
261	2020	7	    28	10	    18	exit	        94KL13X
262	2020	7	    28	10	    18	exit	        6P58WS2
263	2020	7	    28	10	    19	exit	        4328GD8
264	2020	7	    28	10	    20	exit	        G412CB7



-- INTERVIEWS
SELECT * FROM interviews WHERE year = "2020" AND day = "28" AND month = "7"
id	name	year	month	day	transcript
--158	Jose	2020	7	28	“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
--159	Eugene	2020	7	28	“I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
--160	Barbara	2020	7	28	“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.

161	Ruth	2020	7	28	Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
                            If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

162	Eugene	2020	7	28	I don't know the thief's name, but it was someone I recognized.
                            Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

163	Raymond	2020	7	28	As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
                            In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
                            The thief then asked the person on the other end of the phone to purchase the flight.
--ATM TRANSACTIONS
SELECT * FROM atm_transactions WHERE year = "2020" AND day = "28" AND month = "7" AND atm_location = "Fifer Street" AND transaction_type = "withdraw"
id	account_number	year	month	day	atm_location	transaction_type	amount
246	28500762	    2020	7	    28	Fifer Street	withdraw	        48
264	28296815	    2020	7	    28	Fifer Street	withdraw        	20
266	76054385	    2020	7	    28	Fifer Street	withdraw        	60
267	49610011	    2020	7	    28	Fifer Street	withdraw        	50
269	16153065	    2020	7	    28	Fifer Street	withdraw        	80
288	25506511	    2020	7	    28	Fifer Street	withdraw        	20
313	81061156    	2020	7	    28	Fifer Street	withdraw        	30
336	26013199	    2020	7	    28	Fifer Street	withdraw        	35

-- PHONE CALLS
SELECT * FROM phone_calls WHERE year = "2020" AND day = "28" AND month = "7" AND duration < "60"
id	caller	        receiver	     year	month	day	duration
221	(130) 555-0289	(996) 555-8899	2020	7	    28	51
224	(499) 555-9472	(892) 555-8872	2020	7   	28	36
233	(367) 555-5533	(375) 555-8161	2020	7   	28	45
--234	(609) 555-5876	(389) 555-5198	2020	7	28	60
251	(499) 555-9472	(717) 555-1342	2020	7   	28	50
254	(286) 555-6063	(676) 555-6554	2020	7   	28	43
255	(770) 555-1861	(725) 555-3243	2020	7   	28	49
261	(031) 555-6622	(910) 555-3251	2020	7   	28	38
279	(826) 555-1652	(066) 555-9701	2020	7   	28	55
281	(338) 555-6650	(704) 555-2131	2020	7   	28	54

id	    name	phone_number	passport_number	license_plate
--221103	Patrick	(725) 555-4692	2963008352	    5P2BI95
--243696	Amber	(301) 555-4174	7526138472	    6P58WS2
398010	Roger	(130) 555-0289	1695452385	    G412CB7
CALLED
id	name	phone_number	passport_number	license_plate
567218	Jack	(996) 555-8899	9029462229	52R0Y8U

--467400	Danielle(389) 555-5198	8496433585	    4328GD8
686048	Ernest	(367) 555-5533	5773159633	    94KL13X
CALLED
id	name	    phone_number    	passport_number	license_plate
864400	Berthold	(375) 555-8161	NULL	        4V16VO0

--745650	Sophia	(027) 555-1068	3642612721	    13FNH7


-- FLIGHTS
SELECT * FROM flights WHERE year = "2020" AND day = "29" AND month = "7"

id	origin_airport_id	destination_airport_id	year	month	day	hour	minute
--18	8	6	2020	7	29	16	0
--23	8	11	2020	7	29	12	15
36	        8	                4	            2020	  7	    29	  8	       20
--43	8	1	2020	7	29	9	30
--53	8	9	2020	7	29	15	20

--AIRPORTS
SELECT * FROM airports WHERE id = 8
id	abbreviation	full_name	                        city
8	CSF	           Fiftyville Regional Airport	    Fiftyville

--PASSENGERS
SELECT * FROM passengers WHERE flight_id = "36"
flight_id	passport_number	seat
36	        7214083635  	2A
36   	    1695452385	    3B
36	        5773159633	    4A
36	        1540955065  	5C
36	        8294398571	    6C
36  	    1988161715	    6D
36  	    9878712108	    7A
36	        8496433585  	7B

-- PEOPLE
SELECT * FROM people WHERE license_plate = "13FNH73" OR license_plate = "5P2BI95" OR license_plate = "94KL13X" OR license_plate = "6P58WS2" OR license_plate = "4328GD8" OR license_plate = "G412CB7"

id	    name	phone_number	passport_number	license_plate
221103	Patrick	(725) 555-4692	2963008352	    5P2BI95
243696	Amber	(301) 555-4174	7526138472	    6P58WS2
398010	Roger	(130) 555-0289	1695452385	    G412CB7
467400	Danielle(389) 555-5198	8496433585	    4328GD8
686048	Ernest	(367) 555-5533	5773159633	    94KL13X
745650	Sophia	(027) 555-1068	3642612721	    13FNH7

SELECT * FROM bank_accounts WHERE person_id = "686048"
49610011

SELECT * FROM airports WHERE id = "4"