-- 코드를 입력하세요
SELECT
    COUNT(DISTINCT NAME) as cnt
FROM 
    ANIMAL_INS
WHERE 
    NAME IS NOT NULL