USE library;
#（1） 查询读者 Rose 的读者号和地址；
SELECT ID, address FROM Reader WHERE name = 'Rose';

#（2） 查询读者 Rose 所借阅读书（包括已还和未还图书）的图书名和借期；
SELECT Book.name,Borrow.Borrow_Date 
    FROM Book, Reader, Borrow
    WHERE Reader.name = 'Rose' and Reader.ID = Borrow.Reader_ID and Borrow.book_ID = Book.ID;

SELECT Book.name, Borrow.Borrow_Date 
    FROM Borrow
    INNER JOIN Book  ON Borrow.book_id = Book.ID
    INNER JOIN Reader  ON Reader.ID = Borrow.Reader_ID
    WHERE Reader.name = 'Rose';

#（3） 查询未借阅图书的读者姓名；
SELECT name 
    FROM Reader
    WHERE name not in(
        SELECT Reader.name
            FROM Reader, Borrow
            WHERE Reader.ID = Borrow.Reader_ID);

#（4） 查询 Ullman 所写的书的书名和单价；
SELECT name,price
    FROM Book
    WHERE author = 'Ullman';
#（5） 查询读者“李林”借阅未还的图书的图书号和书名；
SELECT Book.ID, Book.name
    FROM Book, Reader, Borrow
    WHERE Reader.name = '李林' and Reader.ID = Borrow.Reader_ID and Borrow.book_ID = Book.ID and Borrow.Return_Date is NULL;
# （6） 查询借阅图书数目超过 3 本的读者姓名；
SELECT name 
    FROM Reader
    WHERE ID in (
        SELECT Reader_ID
            FROM borrow
            GROUP BY Reader_ID
                HAVING COUNT(*) > 3);
#（7） 查询没有借阅读者“李林”所借的任何一本书的读者姓名和读者号；
SELECT Reader.name, Reader.ID
    FROM Reader
    WHERE Reader.ID not in(
        SELECT  Reader_ID
            FROM    Borrow
            WHERE   book_ID in (
                SELECT  Borrow.book_ID
                    FROM Reader, Borrow
                    WHERE Reader.ID = Borrow.Reader_ID and READER.name = '李林'));
#（8） 查询书名中包含“MySQL”的图书书名及图书号；
SELECT name,ID
    FROM book
    WHERE name LIKE '%MySQL%';
#（9） 查询 2021 年借阅图书数目排名前 20 名的读者号、姓名、年龄以及借阅图书数；
SELECT ID,  name, age, address, COUNT(*) AS total_num
    FROM Reader
    INNER JOIN Borrow ON Reader.ID = Borrow.Reader_ID
    WHERE YEAR(Borrow_Date) = 2021
    GROUP BY  ID,  name, age, address
    LIMIT 20;
#（10）创建一个读者借书信息的视图，该视图包含读者号、姓名、所借图书号、图书名和借期；
#并使用该视图查询最近一年所有读者的读者号以及所借阅的不同图书数；
DROP VIEW IF EXISTS Borrow_info;
CREATE VIEW Borrow_info AS
    SELECT  Reader.ID AS '读者号',Reader.name AS '姓名', Book.ID AS '图书号', Book.name AS '图书名', Borrow.Borrow_Date AS '借期'
    FROM Book, Reader, Borrow
    WHERE Book.ID = Borrow.book_ID and Reader.ID = Borrow.Reader_ID
    ORDER BY Reader.ID;
