SELECT *
FROM Users;

-- DROP TABLE Users;
-- -- Leetcode-подобная задача: найти пользователей с количеством заказов > 1
-- SELECT u.name, COUNT(o.id) as order_count
-- FROM Users u
-- JOIN Orders o ON u.id = o.user_id
-- GROUP BY u.id, u.name
-- HAVING COUNT(o.id) > 1;