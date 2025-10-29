-- Создаем таблицы для тренировки
CREATE TABLE Users (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(100)
);

CREATE TABLE Orders (
    id INT PRIMARY KEY,
    user_id INT,
    amount DECIMAL(10,2),
    order_date DATE
);

-- Добавляем тестовые данные
INSERT INTO Users VALUES 
(1, 'Alice', 'alice@test.com'),
(2, 'Bob', 'bob@test.com'),
(3, 'Charlie', 'charlie@test.com'),
(4, 'My', 'charlie25@test.com');

INSERT INTO Orders VALUES
(1, 1, 100.50, '2024-01-15'),
(2, 2, 200.75, '2024-01-16'),
(3, 1, 50.25, '2024-01-17');