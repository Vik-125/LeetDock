# Write your MySQL query statement below
SELECT P.firstName,P.lastName,A.city,A.state
FROM Person AS P
LEFT JOIN Address as A
ON P.personId = A.personId;