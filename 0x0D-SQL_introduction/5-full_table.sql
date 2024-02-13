-- Prints the full description of the table first_table from the database hbtn_0c_0 in my MySQL server.
SELECT COLUMN_NAME, COLUMN_TYPE
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA - '%DATABASE%'
AND TABLE_NAME = 'first_table';
