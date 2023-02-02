SELECT
    Id,
    Company,
    Salary
FROM
    (
        SELECT
            *,
            ROW_NUMBER() OVER(
                PARTITION BY COMPANY
                ORDER BY
                    Salary ASC,
                    Id ASC
            ) AS RN_ASC,
            ROW_NUMBER() OVER(
                PARTITION BY COMPANY
                ORDER BY
                    Salary DESC,
                    Id DESC
            ) AS RN_DESC
        FROM
            Employee
    ) AS temp
WHERE
    RN_ASC BETWEEN RN_DESC - 1
    AND RN_DESC + 1
ORDER BY
    Company,
    Salary;