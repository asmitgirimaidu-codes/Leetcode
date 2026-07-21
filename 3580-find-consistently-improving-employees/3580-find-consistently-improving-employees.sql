WITH RankedReviews AS (
    SELECT 
        employee_id,
        rating,
        review_date,
        ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) AS rn
    FROM performance_reviews
),
LastThreeReviews AS (
    SELECT 
        employee_id,
        MAX(CASE WHEN rn = 1 THEN rating END) AS r1,
        MAX(CASE WHEN rn = 2 THEN rating END) AS r2,
        MAX(CASE WHEN rn = 3 THEN rating END) AS r3
    FROM RankedReviews
    WHERE rn <= 3
    GROUP BY employee_id
    HAVING COUNT(*) = 3
)
SELECT 
    e.employee_id,
    e.name,
    (l.r1 - l.r3) AS improvement_score
FROM LastThreeReviews l
JOIN employees e ON l.employee_id = e.employee_id
WHERE l.r3 < l.r2 AND l.r2 < l.r1
ORDER BY improvement_score DESC, e.name ASC;
