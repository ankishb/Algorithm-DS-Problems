
DATE:  YYYYMMDD (4Y, 2M, 2D)
TIME: HHMMSS (2H, 2M, 2S)
TIME_STAMP: YYYYXXDDHHMMSSZZZZZZ (4Y, 2X, 2D, 2H, 2M, 2S, 6Z)
Z: minisecond

select DAY(Sale_date) from pet_sale

select COUNT(*) from pet_sale
where MONTH(sale_date) == '05'

select (sale_date + 2 DAYS) from pet_sale

select (CURRENT_DATE - Sale_date) from pet_sale


-- Drop the PETSALE table in case it exists
drop table PETSALE;
-- Create the PETSALE table 
create table PETSALE (
	ID INTEGER PRIMARY KEY NOT NULL,
	ANIMAL VARCHAR(20),
	QUANTITY INTEGER,
	SALEPRICE DECIMAL(6,2),
	SALEDATE DATE
	);
-- Insert saple data into PETSALE table
insert into PETSALE values 
	(1,'Cat',9,450.09,'2018-05-29'),
	(2,'Dog',3,666.66,'2018-06-01'),
	(3,'Dog',1,100.00,'2018-06-04'),
	(4,'Parrot',2,50.00,'2018-06-04'),
	(5,'Dog',1,75.75,'2018-06-10'),
	(6,'Hamster',6,60.60,'2018-06-11'),
	(7,'Cat',1,44.44,'2018-06-11'),
	(8,'Goldfish',24,48.48,'2018-06-14'),
	(9,'Dog',2,222.22,'2018-06-15')
	
;


select SUM(SALEPRICE) from PETSALE;
select SUM(SALEPRICE) AS SUM_OF_SALEPRICE from PETSALE;
select MAX(QUANTITY) from PETSALE;
select AVG(SALEPRICE) from PETSALE;
select AVG( SALEPRICE / QUANTITY ) from PETSALE where ANIMAL = 'Dog';
select ROUND(SALEPRICE) from PETSALE;
select LENGTH(ANIMAL) from PETSALE;
select UCASE(ANIMAL) from PETSALE;
select DISTINCT(UCASE(ANIMAL)) from PETSALE;
select * from PETSALE where LCASE(ANIMAL) = 'cat';
select DAY(SALEDATE) from PETSALE where ANIMAL = 'Cat';
select COUNT(*) from PETSALE where MONTH(SALEDATE)='05';
select (SALEDATE + 3 DAYS) from PETSALE;
select (CURRENT DATE - SALEDATE) from PETSALE;







Query 1: Retrieve all employees whose address is in Elgin,IL
[Hint: Use the LIKE operator to find similar strings]
Query 2: Retrieve all employees who were born during the 1970's.
[Hint: Use the LIKE operator to find similar strings]
Query 3: Retrieve all employees in department 5 whose salary is between
60000 and 70000 .
[Hint: Use the keyword BETWEEN for this query ]
Query 4A: Retrieve a list of employees ordered by department ID.
[Hint: Use the ORDER BY clause for this query]
Query 4B: Retrieve a list of employees ordered in descending order by
department ID and within each department ordered alphabetically in
descending order by last name.
Query 5A: For each department ID retrieve the number of employees in the
department.
[Hint: Use COUNT(*) to retrieve the total count of a column, and then GROUP BY]Course:	Databases	and	SQL	for	Data	Science	- LAB:	String	Patterns,	Sorting	and	Grouping
Copyright	©2018	IBM	Corporation Page	10 of	15
Query 5B: For each department retrieve the number of employees in the
department, and the average employees salary in the department.
[Hint: Use COUNT(*) to retrieve the total count of a column, and AVG() function to
compute average salaries, and then group]
Query 5C: Label the computed columns in the result set of Query 5B as
“NUM_EMPLOYEES” and “AVG_SALARY”.
[Hint: Use AS “LABEL_NAME” after the column name]
Query 5D: In Query 5C order the result set by Average Salary.
[Hint: Use ORDER BY after the GROUP BY]
Query 5E: In Query 5D limit the result to departments with fewer than 4
employees.
[Hint: Use HAVING after the GROUP BY, and use the count() function in the
HAVING clause instead of the column label.
Note: WHERE clause is used for filtering the entire result set whereas the HAVING
clause is used for filtering the result of the grouping]
BONUS Query 6: Similar to 4B but instead of department ID use department
name. Retrieve a list of employees ordered by department name, and within
each department ordered alphabetically in descending order by last name.
[Hint: Department name is in the DEPARTMENTS table. So your query will need to
retrieve data from more than one table. Don’t worry if you are not able to figure this
one out … we’ll cover working with multiple tables in the next lesson.]
In this lab you learned how to work with string patterns, sorting result sets and
grouping result sets.

-- Query 1------
;
select F_NAME , L_NAME
from EMPLOYEES
where ADDRESS LIKE '%Elgin,IL%' ;
--Query 2--
;
select F_NAME , L_NAME
from EMPLOYEES
where B_DATE LIKE '197%' ;
---Query3--
;
select *
from EMPLOYEES
where (SALARY BETWEEN 60000 and 70000)  and DEP_ID = 5 ;
--Query4A--
;
select F_NAME, L_NAME, DEP_ID 
from EMPLOYEES
order by DEP_ID;
--Query4B--
;
select F_NAME, L_NAME, DEP_ID 
from EMPLOYEES
order by DEP_ID desc, L_NAME desc;
--Query5A--
;
select DEP_ID, COUNT(*)
from EMPLOYEES
group by DEP_ID;
--Query5B--
;
select DEP_ID, COUNT(*), AVG(SALARY)
from EMPLOYEES
group by DEP_ID;
--Query5C--
;
select DEP_ID, COUNT(*) AS "NUM_EMPLOYEES", AVG(SALARY) AS "AVG_SALARY"
from EMPLOYEES
group by DEP_ID;
--Query5D--
;
select DEP_ID, COUNT(*) AS "NUM_EMPLOYEES", AVG(SALARY) AS "AVG_SALARY"
from EMPLOYEES
group by DEP_ID
order by AVG_SALARY;
--Query5E--
;
select DEP_ID, COUNT(*) AS "NUM_EMPLOYEES", AVG(SALARY) AS "AVG_SALARY"
from EMPLOYEES
group by DEP_ID
having count(*) < 4
order by AVG_SALARY;
--5E alternative: if you want to use the label
select DEP_ID, NUM_EMPLOYEES, AVG_SALARY from
  ( select DEP_ID, COUNT(*) AS NUM_EMPLOYEES, AVG(SALARY) AS AVG_SALARY from EMPLOYEES group by DEP_ID)
  where NUM_EMPLOYEES < 4
order by AVG_SALARY;
--BONUS Query6--
;
select D.DEP_NAME , E.F_NAME, E.L_NAME
from EMPLOYEES as E, DEPARTMENTS as D
where E.DEP_ID = D.DEPT_ID_DEP
order by D.DEP_NAME, E.L_NAME desc ;

