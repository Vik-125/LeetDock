SELECT MAX(salary) as SecondHighestSalary
from Employee
WHERE SALARY < (SELECT MAX(salary) FROM Employee);