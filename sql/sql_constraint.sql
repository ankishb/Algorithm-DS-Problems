A foreign key refers to a primary key of another table

There are 6 types of contraint in relational model

1. Entity Integrity Constraint:
		NULL should not be there in primary key attruibute
		Referential Integrity Constraint is enforced using a combination of Primary and Foreign keys. In the relation SALE, Sale_id is the primary key and Salesperson_id & Serial_no are the foreign keys.
		
2. The Referential Integrity Constraint 
		It ensures the validity of the data using a combination of Primary Keys and Foreign Keys. 
		For exp: Book must be written by atleast one author
		
3. Semantic Integrity Constraint:
		Correct value type should be inserted in table
		For exp: 123 cann't be used in first name of person table
	
4. Domain Constraint
		Correctness of value/domain in attribute
		For exp: A country name is represented using two letter word, India: IN, United State: US, But 34 doesn't reflect anything. So it violate the domain constraint
		
5. Null Constraint:
		Logical NULL in attribute violate this constraint
		For exp: first and last name, both can't be null for the definition of employee in company or author name in book
		
6. Check Constraint:
		Logical insertion of values
		For example: A book can't be publish in year 2020, as current year is 2019